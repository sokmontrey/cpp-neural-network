#include "matrix.hpp"

Matrix::Matrix() = default;
Matrix::Matrix(int rows, int cols, double value){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i=0; i<rows; i++){
		this->matrix[i].resize(cols, value);
	}
}
Matrix::~Matrix(){ this->matrix.clear(); }

void transpose() const{
}

void Matrix::print() const{
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%.4f  ", this->matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
