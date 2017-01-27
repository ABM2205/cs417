#include<iostream>
#include "Matrix.cpp"
#include <fstream>
#include <math.h>
#include <bitset>

int main(int argc, char *argv[]){

    int a, b = 0;
    int val;

    double x0, x1 = 0;

    double m0, m1 = 0;

    double b10= 0;
    string b2 ="";

    ifstream data("data.txt");

    data >> a;
    Matrix A (a, a+1);
    
    data >> a >> b;
    A.setCell(0, 0, a);
    A.setCell(0, 1, b);
    data >> a >> b;
    A.setCell(1, 0, a);
    A.setCell(1, 1, b);
    data >> a;
    A.setCell(0, 2, a);
    data >> a;
    A.setCell(1, 2, a);

    A.unitify(0);
    A.unitify(1);
    A.sort(1);
    A.replace(0, 1, -1);
    A.unitify(0);
    A.unitify(1);

    // because n=2, 1 x 1 = 1 x 2

    cout << "\n";

    x1 = A.getCell(1, 2);
    x0 = (A.getCell(0, 0) * A.getCell(0, 2) + A.getCell(1, 0) * A.getCell(1, 2) );

    cout << "x0 = " << x0 << endl;
    cout << "x1 = " << x1 << endl;

    m0 = A.getCell(0, 2) - (A.getCell(0, 0) * x0 + A.getCell(0, 1) * x0);
    m1 = A.getCell(1, 2) - (A.getCell(1, 0) * x1 + A.getCell(1, 1) * x1);

    b10 = sqrt ( (m0*m0)+(m1*m1) );
    b2 = bitset<8>(b10).to_string();
    
    cout << "||b - A*x||2 = " << b2 << endl;
   return 0;
}