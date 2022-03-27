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
	//TODO: implement a better random generator
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
				matrix[i][j] = other(i, j);
			}
		}
	}
}
void Matrix::operator+=(double scalar){
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			matrix[i][j] += scalar;
		}
	}
}
double& Matrix::operator()(int i, int j){
	return matrix[i][j];
}


/*__scalar operator__*/
Matrix Matrix::operator+(double scalar) const {
	Matrix result(rows, cols, 0);
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			result(i,j) = matrix[i][j] + scalar;
		}
	}
	return result;
}
Matrix Matrix::operator*(double scalar) const {
	Matrix result(rows, cols, 0);
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			result(i,j) = matrix[i][j] * scalar;
		}
	}
	return result;
}
Matrix Matrix::operator^(double scalar) const {
	Matrix result(rows, cols, 0);
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			result(i,j) = pow(matrix[i][j], scalar);
		}
	}
	return result;
}

/*__matrix operator__*/
Matrix Matrix::operator+(Matrix& other) const {
	if(rows != other.getRows() || cols != other.getCols()){
		throw std::invalid_argument("Matrix dimensions do not match");
	}
	Matrix result(rows, cols, 0);
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			result(i,j) = matrix[i][j] + other.matrix[i][j];
		}
	}
	return result;
}
Matrix Matrix::operator*(Matrix& other) const {
	if(cols != other.getRows()){
		throw std::invalid_argument("Matrix dimensions do not match");
	}
	Matrix result(rows, other.getCols(), 0);
	for(int i=0; i<rows; ++i){
		for(int j=0; j<other.getCols(); ++j){
			for(int k=0; k<cols; ++k){
				result(i,j) += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	return result;
}

/*____*/

Matrix Matrix::transpose() const {
	Matrix result(cols, rows, 0);
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			result(j,i) = matrix[i][j];
		}
	}
	return result;
}

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

