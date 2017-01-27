#include "Matrix.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// helpers

Matrix::Matrix(){
    vector<double> matrix;
};

Matrix::Matrix(int r, int c){ 
    for(int row = 0;  row < r; row++){
        vector<double> temp;
        for(int col = 0; col < c; col++){
            temp.push_back( (col*row)  );
        }
        matrix.push_back(temp);
    }
};


//methods

// returns a submatrix, x_lower, y_lower are the lower bounds and x_upper,y_upper) the upper bounds 
Matrix Matrix::getSubMatrix(int row_lower, int row_upper, int col_lower, int col_upper){
    for(int row = row_lower; row > row_upper; row++){
            for(int col = col_lower; col > col_upper; col++){

            }
    }
    Matrix temp;
    return temp;
}

void Matrix::print(string head){
    cout << head << endl;
    for(int row = 0;  row < matrix.size(); row++){
        for(int col = 0;  col < matrix[row].size(); col++){
            cout << matrix[row][col] << setprecision(2);
            cout << " ";
        }
        cout << "\n";
    }
}

void Matrix::print(){
    for(int row = 0;  row < matrix.size(); row++){
        for(int col = 0;  col < matrix[row].size(); col++){
            cout << matrix[row][col] << setprecision(2);
            cout << " ";
        }
    }
}

vector<double> Matrix::getMultipliedRow(int target, double factor){
    vector <double> product;

    product = matrix[target];

    for(int i = 0; i < product.size(); i++) {
    product[i] *= factor;
    }

    return product;
}



void Matrix::interchange(int r1, int r2){
    matrix[r1].swap(matrix[r2]);
}

void Matrix::replace(int target, int source, double factor){

    vector<double> factorRow = getMultipliedRow(source, factor);

    for (int i = 0; i < matrix[target].size(); i++){
        
        matrix[target][i] += factorRow[i];
    }

}

void Matrix::scale(int target, double factor){

    matrix[target] = getMultipliedRow(target, factor);

}

void Matrix::setCell(int r, int c, double x){
    matrix[r][c] = x;
}

double Matrix::getCell(int r, int c){
    return matrix[r][c];
}

void Matrix::sort(int c){
    
    int loc = 0;
    double temp = 0.0;

    for (int i = 0; i < matrix.size(); i++){
       
        temp = matrix[i][c];
        loc = i;
        while( (loc != 0) && (matrix[loc][c] > matrix[(loc-1)][c]) ){
            cout << matrix[loc][c] << " > " << matrix[(loc-1)][c] << endl;
        interchange(loc, (loc-1));
        loc--;
        }

    }


}

void Matrix::unitify(int r){
    int x = 0;
    while ( matrix[r][x] == 0) x++;
    if( matrix[r][x] != 1) matrix[r] = getMultipliedRow(r, (1/matrix[r][x]) );
}