#include "activation.hh"

double Activation::sigmoid(double x, bool isDerivative){
	if(isDerivative) return x * (1.0 - x);
	return 1.0 / (1.0 + std::exp(-x));
}
double Activation::tanh(double x, bool isDerivative){
	if(isDerivative) return 1.0 - std::pow(x, 2);
	return (2.0 / (1.0 + std::exp(-2 * x))) - 1.0;
}
double Activation::relu(double x, bool isDerivative){
	if(isDerivative) return (x>0 ? 1 : 0);
	return std::max(0.0, x);
}

/*___matrix___*/

Matrix Activation::matrixSigmoid(Matrix& a, bool isDerivative){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::sigmoid(a(i,j), isDerivative);
        }
    }
    return result;
}
Matrix Activation::matrixTanh(Matrix& a, bool isDerivative){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::tanh(a(i,j), isDerivative);
        }
    }
    return result;
}
Matrix Activation::matrixRelu(Matrix& a, bool isDerivative){
    int rows = a.getRows(), cols = a.getCols();
    Matrix result(rows, cols);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result(i, j) = Activation::relu(a(i,j), isDerivative);
        }
    }
    return result;
}
