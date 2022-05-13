#include "./matrix.hh"

double& Matrix::operator()(int row, int col){
	//TODO: add error handler for row > rows
	return this->matrix[row][col];
}

/* scalar operator */
Matrix Matrix::operator+(double scalar){
	return Matrix::add(*this, scalar);
}
Matrix Matrix::operator*(double scalar){
	return Matrix::mul(*this, scalar);
}

Matrix Matrix::operator-(){
	return Matrix::neg(*this);
}

/* matrix operator */
Matrix Matrix::operator+(Matrix& other){
	return Matrix::add(*this, other);
}
Matrix Matrix::operator*(Matrix& other){
	return Matrix::mul(*this, other);
}

/* scalar operation */
Matrix Matrix::add(Matrix& A, double scalar){
	//TODO: error handler
	int rows = A.getRows();
	int cols = A.getCols();

	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i, j) = A(i, j) + scalar;
		}
	}
	return result;
}
Matrix Matrix::mul(Matrix& A, double scalar){
	//TODO: error handler
	int rows = A.getRows();
	int cols = A.getCols();

	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i, j) = A(i, j) * scalar;
		}
	}
	return result;
}
Matrix Matrix::neg(Matrix& A){
	int rows = A.getRows();
	int cols = A.getCols();
	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i, j) = - A(i, j);
		}
	}
	return result;
}

/* matrix operation */
Matrix Matrix::add(Matrix& A, Matrix& B){
	//TODO: error handler
	int rows = A.getRows();
	int cols = A.getCols();

	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i, j) = A(i, j) + B(i, j);
		}
	}
	return result;
}
Matrix Matrix::mul(Matrix& A, Matrix& B){
	//TODO: error handler
	int rows = A.getRows();
	int cols = A.getCols();

	Matrix result(rows, cols);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result(i, j) = A(i, j) * B(i, j);
		}
	}
	return result;
}
Matrix Matrix::matmul(Matrix& A, Matrix& B){
	int ARows = A.getRows(),
		ACols = A.getCols(),
		BRows = B.getRows(),
		BCols = B.getCols();
	Matrix result(ARows, BCols);
	for(int i=0; i<ARows; i++){
		for(int j=0; j<BCols; j++){
			int sum = 0;
			for(int k=0; k<ACols; k++){
				sum += A(i, k) * B(k, j);
			}
			result(i, j) = sum;
		}
	}
	return result;
}
