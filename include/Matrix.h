#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using namespace std;

class Matrix {
private:
    vector< vector<double> > matrix;
public:
    Matrix();
    Matrix(int,int);

    vector<double> getMultipliedRow(int, double);
    void replace(int, int, double);
    void scale(int, double);

    Matrix getSubMatrix(int,int,int,int);
    
    void print();
    void print(string);

    void setCell(int, int, double);
    double getCell(int, int);
    
    void interchange(int, int);
    void sort(int);

    void unitify(int);
};

#endif