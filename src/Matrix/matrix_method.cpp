#include "matrix.hh"

Matrix Matrix::matmul(Matrix& other){
	if(cols != other.getRows())
		throw std::invalid_argument("Matrix dimensions do not match");
	Matrix result(rows, other.getCols());
	for(int i=0; i<rows; i++){
		for(int j=0; j<other.getCols(); j++){
			for(int k=0; k<cols; k++){
				result(i,j) += matrix[i][k] * other(k,j);
			}
		}
	}
	return result;
}

double Matrix::sum(){
	double sum = 0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			sum += matrix[i][j];
		}
	}
	return sum;
}
double Matrix::max(){
	double max = matrix[0][0];
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			max = std::max(matrix[i][j], max);
		}
	}
	return max;
}

Matrix Matrix::transpose(){
	Matrix transposed(cols, rows);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			transposed(j, i) = matrix[i][j];
		}
	}
	return transposed;
}

Matrix Matrix::square(){
	Matrix squared(rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			squared(i, j) = matrix[i][j] * matrix[i][j];
		}
	}
	return squared;
}

Matrix Matrix::exp(){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = std::exp(matrix[i][j]);
		}
	}
	return result;
}
Matrix Matrix::log(){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = std::log(matrix[i][j]);
		}
	}
	return result;
}

void Matrix::print() const{
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++) {
			printf("%.4f  ", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
