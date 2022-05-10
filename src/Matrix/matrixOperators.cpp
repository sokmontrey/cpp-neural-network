#include "./matrix.hh"

double& Matrix::operator()(int row, int col){
	//TODO: add error handler for row > rows
	return this->matrix[row][col];
}

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