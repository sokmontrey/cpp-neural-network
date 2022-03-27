#include "matrix.hpp"

Matrix::Matrix() = default;
Matrix::Matrix(int rows, int cols){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i=0; i<rows; i++){
		this->matrix[i].resize(cols);
	}
}
Matrix::~Matrix(){ this->matrix.clear(); }

void Matrix::setAll(double value){
	if(isInitialized) throw "Matrix is already initialized";
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			this->matrix[i][j] = value;
		}
	}
	isInitialized = true;
}
void Matrix::randomize(double min, double max, double seed){
	if(isInitialized) throw "Matrix is already initialized";
	srand(seed);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			this->matrix[i][j] = min + (max-min)*((double)rand()/RAND_MAX);
		}
	}
	isInitialized = true;
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
