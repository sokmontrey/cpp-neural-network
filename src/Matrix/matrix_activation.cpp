#include "matrix.hpp"

/*__activation__*/
Matrix Matrix::sigmoid(){
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::sigmoid(matrix[i][j]);
        }
    }
    return result;
}
Matrix Matrix::tanh(){
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::tanh(matrix[i][j]);
        }
    }
    return result;
}
Matrix Matrix::relu(){
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::relu(matrix[i][j]);
        }
    }
    return result;
}

/*__derivative__*/
Matrix Matrix::dSigmoid(){
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation:dSigmoid(matrix[i][j]):
        }
    }
    return result;
}
Matrix Matrix::dTanh(){
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dTanh(matrix[i][j]);
        }
    }
    return result;
}
Matrix Matrix::dRelu(){
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dRelu(matrix[i][j]);
        }
    }
    return result;
}