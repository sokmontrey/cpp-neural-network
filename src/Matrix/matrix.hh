#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "../Activation/activation.hh"

using namespace std;
class Matrix{
	private:
		int rows;
		int cols;
		vector<vector<double>> matrix;

	public:
		Matrix();
		~Matrix();
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, double value);
		Matrix(int rows, int cols, vector<double> random);
		Matrix(vector<vector<double>> matrix);

		double& operator()(int row, int col);

		/*__scalar_operator__*/
		Matrix operator+(double scalar);
		Matrix operator*(double scalar);
		Matrix operator-(double scalar);
		Matrix operator/(double scalar);

		/*__matrix_operator__*/
		Matrix operator^(Matrix& other); //matmul
		Matrix operator*(Matrix& other); //mul
		Matrix operator+(Matrix& other); 
		Matrix operator-(Matrix& other);

		Matrix operator-();

		/*__getter__*/
		int getRows();
		int getCols();

		/*__method__*/
		Matrix matmul(Matrix& other);
	
		double sum();
		double max();

		Matrix transpose();
		Matrix square();
		Matrix exp();
		Matrix log();


		void print() const;
};

#endif
