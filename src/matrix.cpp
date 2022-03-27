#include "matrix.hpp"

/*__constructor__*/

Matrix::Matrix() = default;
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

/*__getters__*/

int Matrix::getRows() { return rows; }
int Matrix::getCols() { return cols; }

/*__operators__*/

void Matrix::operator=(Matrix& other){
	if(this != &other){
		this->rows = other.getRows();
		this->cols = other.getCols();

		matrix.resize(rows);
		for(int i=0; i<rows; ++i){
			matrix[i].resize(cols);
			for(int j=0; j<cols; ++j){
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}
}
double& Matrix::operator()(int i, int j){
	return matrix[i][j];
}


/*__scalar operator__*/

/*____*/
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

