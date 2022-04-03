#include "./loss.hh"

double Loss::mse(Matrix& output, Matrix& target){
	if(output.getRows() != target.getRows() || output.getCols() != target.getCols()){
		throw std::invalid_argument("Matrix dimensions do not match");
	}

	double sum = 0;
	for(int i=0; i<output.getRows(); i++){
		for(int j=0; j<output.getCols(); j++){
			sum += std::pow(output(i,j) - target(i,j), 2);
		}
	}
	return sum / (output.getRows() * output.getCols());
}

Matrix Loss::matrixMSE(Matrix& output, Matrix& target, bool isDerivative){
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

