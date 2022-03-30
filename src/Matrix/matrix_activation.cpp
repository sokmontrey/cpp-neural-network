#include "matrix.hpp"

/*__activation__*/
Matrix Matrix::sigmoid(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::sigmoid(a(i,j));
        }
    }
    return result;
}
Matrix Matrix::tanh(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::tanh(a(i,j));
        }
    }
    return result;
}
Matrix Matrix::relu(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::relu(a(i,j));
        }
    }
    return result;
}
/*__derivative_activation__*/
Matrix Matrix::dSigmoid(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dSigmoid(a(i,j));
        }
    }
    return result;
}
Matrix Matrix::dTanh(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dTanh(a(i,j));
        }
    }
    return result;
}
Matrix Matrix::dRelu(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dRelu(a(i,j));
        }
    }
    return result;
}