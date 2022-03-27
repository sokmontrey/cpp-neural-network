#include "matrix.hpp"

double& Matrix::operator()(int row, int col){
	return this->matrix[row][col];
}

/*__scalar_operator__*/
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

/*__matrix_operator__*/
Matrix Matrix::operator+(Matrix& other){
	if(rows != other.rows || cols != other.cols)
		throw std::invalid_argument("Matrix dimensions do not match");
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] + other(i,j);
		}
	}
	return result;
}
Matrix Matrix::operator*(Matrix& other){
	if(cols != other.rows)
		throw std::invalid_argument("Matrix dimensions do not match");
	Matrix result(rows, other.cols);
	//optimize matrix multiplication algorithm
	for(int i=0; i<rows; i++){
		for(int j=0; j<other.cols; j++){
			for(int k=0; k<cols; k++){
				result(i,j) += matrix[i][k] * other(k,j);
			}
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
