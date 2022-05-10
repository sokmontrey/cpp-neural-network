#include "matrix.hh"

Matrix::Matrix() = default;
Matrix::~Matrix(){ this->matrix.clear(); }
Matrix::Matrix(vector<vector<double>> matrix){
	this->rows = matrix.size();
	this->cols = matrix[0].size();
	this->matrix = matrix;
}

void Matrix::_normal_init(int rows, int cols, double value){
	this->rows = rows;
	this->cols = cols;
	this->matrix.resize(rows);
	for(int i = 0; i < rows; i++){
		this->matrix[i].resize(cols, value);
	}
}
Matrix::Matrix(int rows, int cols){ 
	this->_normal_init(rows, cols, 0);
}
Matrix::Matrix(vector<int> sizes, double value){
	this->_normal_init(sizes[0], sizes[1], value);
}

void Matrix::_random_init(int rows, int cols, double min, double max, double seed){
	this->rows = rows;
	this->cols = cols;

	srand(seed);
	
	matrix.resize(rows);
	for(int i=0; i<rows; i++){
		matrix[i].resize(cols);
		for(int j=0; j<cols; j++){
			this->matrix[i][j] = (double)rand()/RAND_MAX*(max-min)+min;
		}
	}
}
Matrix::Matrix(vector<int> sizes, vector<double> random){
	double min = random[0],
		max = random[1],
		seed = random.size()>=3? random[2] : 1;
	this->_random_init(sizes[0], sizes[1], min, max, seed);
}

void Matrix::print() const {
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%.3f ", matrix[i][j]);
		}
		cout << endl;
	}
}

