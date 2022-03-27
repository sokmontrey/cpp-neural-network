#include "matrix.hpp"

/*__constructor__*/
Matrix::Matrix(){ = default;

Matrix::Matrix(int rows, int cols, double value){
	this->rows = rows;
	this->cols = cols;

	matrix.resize(rows);
	for(int i=0; i<rows; ++i){
		matrix[i].resize(cols, value); 
	}
}
Matrix::Matrix(int rows, int cols, double min, double max){
	this->rows = rows;
	this->cols = cols;

	matrix.resize(rows);
	for(int i=0; i<rows; i++){
		matrix[i].resize(cols);
		for(int j=0; j<cols; j++){
			matrix[i][j] = min + (max-min)*((double)rand()/RAND_MAX);
		}
	}
}

Matrix::~Matrix(){ matrix.clear(); }

void Matrix::print() const {
	cout << "\n";
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%.4f  ", matrix[i][j]);
		}
		cout << "\n";
	}
	cout << "\n";
}

