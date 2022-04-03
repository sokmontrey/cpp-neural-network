#include "./loss.hh"

Matrix Loss::mse(Matrix& output, Matrix& target, bool isDerivative){
	if(output.getRows() != target.getRows() || output.getCols() != target.getCols()){
		throw std::invalid_argument("Matrix dimensions do not match");
	}

	if(isDerivative){
		Matrix result = ((output - target).square() / output.getCols());
		return result;
	}

	Matrix derivative = (output - target) * 2.0 / output.getCols();
	return derivative;
}

