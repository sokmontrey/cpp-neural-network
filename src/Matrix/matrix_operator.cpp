#include "matrix.hh"

double& Matrix::operator()(int row, int col){
	return this->matrix[row][col];
}
Matrix Matrix::operator-(){
	Matrix result(rows, cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result(i,j) = -matrix[i][j];
		}
	}
	return result;
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
Matrix Matrix::operator-(double scalar){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] - scalar;
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
Matrix Matrix::operator/(double scalar){
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] / scalar;
		}
	}
	return result;
}

/*__matrix_operator__*/
Matrix Matrix::operator+(Matrix& other){
	if(rows != other.getRows() || cols != other.getCols())
		throw std::invalid_argument("Matrix dimensions do not match");
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] + other(i,j);
		}
	}
	return result;
}
//matrix multiplication
Matrix Matrix::operator^(Matrix& other){
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
//normal matrix multiplication(element by element)
Matrix Matrix::operator*(Matrix& other){
	if(rows != other.getRows()|| cols != other.getCols())
		throw std::invalid_argument("Matrix dimensions do not match");
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] * other(i,j);
		}
	}
	return result;
}

Matrix Matrix::operator-(Matrix& other){
	if(rows != other.getRows() || cols != other.getCols())
		throw std::invalid_argument("Matrix dimensions do not match");
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i,j) = matrix[i][j] - other(i,j);
		}
	}
	return result;
}
