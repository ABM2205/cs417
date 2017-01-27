#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;
#include "matrix.h"

int main()
{   int r,c;
cout<<"enter rows and cols"<<endl;
cin>>r>>c;
    mat A(r,c);
    A.display();

    A.ident();
    A.display();

    A.random_mat(10.0);
    A.display();
    return 0;
}