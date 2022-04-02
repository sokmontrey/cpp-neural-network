#include "activation.hh"

double Activation::sigmoid(double x){
    return 1.0 / (1.0 + std::exp(-x));
}
double Activation::tanh(double x){
    return (2.0 / (1.0 + std::exp(-2 * x))) - 1.0;
}
double Activation::relu(double x){
    return std::max(0.0, x);
}

double Activation::dSigmoid(double activated){
    return activated * (1.0 - activated);
}
double Activation::dTanh(double activated){
    return 1.0 - std::pow(activated, 2);
}
double Activation::dRelu(double activated){
    return (activated>0 ? 1 : 0);
}

/*___matrix___*/

/*__activation__*/
Matrix Activation::matrixSigmoid(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::sigmoid(a(i,j));
        }
    }
    return result;
}
Matrix Activation::matrixTanh(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::tanh(a(i,j));
        }
    }
    return result;
}
Matrix Activation::matrixRelu(Matrix& a){
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
Matrix Activation::dMatrixSigmoid(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dSigmoid(a(i,j));
        }
    }
    return result;
}
Matrix Activation::dMatrixTanh(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dTanh(a(i,j));
        }
    }
    return result;
}
Matrix Activation::dMatrixRelu(Matrix& a){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::dRelu(a(i,j));
        }
    }
    return result;
}
