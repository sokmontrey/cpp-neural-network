#include "matrix.hpp"

double Matrix::sum(){
	double sum = 0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			sum += matrix[i][j];
		}
	}
	return sum;
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
			result(i,j) = exp(matrix[i][j]);
		}
	}
	return result;
}
Matrix Matrix::log(){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = log(matrix[i][j]);
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
