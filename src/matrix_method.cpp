#include "matrix.hpp"

Matrix Matrix::transpose(){
	Matrix transposed(cols, rows);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			transposed(j, i) = matrix[i][j];
		}
	}
	return transposed;
}
