#include "matrix.hpp"

void Matrix::reshape(int rows, int cols){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i = 0; i < rows; i++){
		this->matrix[i].resize(cols, 0);
	}
}
void Matrix::reshape(int rows, int cols, double value){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i=0; i<rows; i++){
		this->matrix[i].resize(cols);
		for(int j=0; j<cols; j++)
			this->matrix[i][j] = value;
	}
}
void Matrix::reshape(int rows, int cols, vector<double> random){
	this->rows = rows;
	this->cols = cols;

	double min = random[0], max = random[1];
	if(random.size() >= 3) srand(random[2]);

	matrix.resize(rows);
	for(int i=0; i<rows; i++){
		matrix[i].resize(cols);
		for(int j=0; j<cols; j++){
			this->matrix[i][j] = (double)rand()/RAND_MAX*(max-min)+min;
		}
	}
}
void Matrix::reshape(int rows, int cols, vector<vector<double>> matrix){
	this->rows = rows;
	this->cols = cols;
	this->matrix = matrix;
}


Matrix::Matrix() = default;
Matrix::~Matrix(){ this->matrix.clear(); }

Matrix::Matrix(int rows, int cols){ 
	this->reshape(rows, cols);
}
Matrix::Matrix(int rows, int cols, double value){
	this->reshape(rows, cols, value);
}
Matrix::Matrix(int rows, int cols, vector<double> random){
	this->reshape(rows, cols, random);
}
Matrix::Matrix(int rows,int cols,vector<vector<double>> matrix){
	this->reshape(rows, cols, matrix);
}

