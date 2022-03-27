#include "matrix.hpp"

double& Matrix::operator()(int row, int col){
	return this->matrix[row][col];
}

/*__scalar_operator__*/
Matrix Matrix::addScalar(double scalar){
	return matrix + scalar;
}
Matrix Matrix::multiplyScalar(double scalar){
	return matrix * scalar;
}

Matrix Matrix::operator+(double scalar){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] + scalar;
		}
	}
	return result;
}
Matrix Matrix::operator*(double scalar){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] * scalar;
		}
	}
	return result;
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
