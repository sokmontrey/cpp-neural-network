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
// Matrix::Matrix(int rows, int cols, double value){
// 	this->rows = rows;
// 	this->cols = cols;
// 	this->matrix.resize(rows);
// 	for(int i=0; i<rows; i++){
// 		this->matrix[i].resize(cols);
// 		for(int j=0; j<cols; j++)
// 			this->matrix[i][j] = value;
// 	}
// }
// Matrix::Matrix(int rows, int cols, vector<double> random){
// 	this->rows = rows;
// 	this->cols = cols;

// 	double min = random[0], max = random[1];
// 	if(random.size() >= 3) srand(random[2]);

// 	matrix.resize(rows);
// 	for(int i=0; i<rows; i++){
// 		matrix[i].resize(cols);
// 		for(int j=0; j<cols; j++){
// 			this->matrix[i][j] = (double)rand()/RAND_MAX*(max-min)+min;
// 		}
// 	}
// }
void Matrix::print() const {
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%.3f ", matrix[i][j]);
		}
		cout << endl;
	}
}

