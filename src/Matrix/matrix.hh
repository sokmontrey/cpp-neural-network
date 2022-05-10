#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <random>
#include <vector>
#include <cmath>

using namespace std;

class Matrix{
	private:
		int rows;
		int cols;
		vector<vector<double>> matrix;

		void _normal_init(int rows, int cols, double value);
		void _random_init(int rows, int cols, double min, double max, double seed);

	public:
		Matrix();
		~Matrix();
		Matrix(vector<vector<double>> initMatrix);
		Matrix(int rows, int cols);
		Matrix(vector<int> sizes, double value);
		Matrix(vector<int> sizes, vector<double> random);

		// double& operator()(int row, int col);

		// /*__scalar_operator__*/
		// Matrix operator+(double scalar);
		// Matrix operator*(double scalar);
		// Matrix operator-(double scalar);
		// Matrix operator/(double scalar);

		// /*__matrix_operator__*/
		// Matrix operator^(Matrix& other); //matmul
		// Matrix operator*(Matrix& other); //mul
		// Matrix operator+(Matrix& other); 
		// Matrix operator-(Matrix& other);

		// Matrix operator-();

		// /*__getter__*/
		// int getRows();
		// int getCols();

		// /*__method__*/
		// Matrix matmul(Matrix& other);
	
		// double sum();
		// double max();

		// Matrix transpose();
		// Matrix square();
		// Matrix exp();
		// Matrix log();


		void print() const;
};

#endif
