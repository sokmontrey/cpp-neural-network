#include "matrix.hpp"

double& Matrix::operator()(int row, int col){
	return matrix[row][col];
}
