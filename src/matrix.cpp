#include "matrix.hpp"

Matrix::Matrix() = default;
Matrix::Matrix(int rows, int cols){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i = 0; i < rows; i++){
		this->matrix[i].resize(cols, 0);
	}
}
Matrix::Matrix(int rows, int cols, double value){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i=0; i<rows; i++)
		this->matrix[i].resize(cols, value);
}
Matrix::Matrix(int rows,int cols,double min,double max,double seed){
	this->rows = rows;
	this->cols = cols;
	srand(seed);
	this->matrix.resize(rows);
	for(int i=0; i<rows; i++){
		this->matrix[i].resize(cols);
		for(int j=0; j<cols; j++){
			this->matrix[i][j] = (double)rand()/RAND_MAX*(max-min)+min;
		}
	}
}
Matrix::Matrix(int rows,int cols,vector<vector<double>> matrix){
	this->rows = rows;
	this->cols = cols;
	this->matrix = matrix;
}
Matrix::~Matrix(){ this->matrix.clear(); }

