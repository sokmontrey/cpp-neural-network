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
		Matrix(int rows, int cols);
		Matrix(vector<int> sizes, double value);
		Matrix(vector<int> sizes, vector<double> random);

		//use Matrix(vector<vector<double>> {}) to initialize
		Matrix(vector<vector<double>> initMatrix);

		double& operator()(int row, int col);

		/* scalar operation */
		static Matrix add(Matrix& A, double scalar);
		static Matrix mul(Matrix& A, double scalar);

		static Matrix neg(Matrix& A);
		/* matrix operation */
		static Matrix add(Matrix& A, Matrix& B);
		static Matrix mul(Matrix& A, Matrix& B);
		static Matrix matmul(Matrix& A, Matrix& B);

		/* scalar operator */
		Matrix operator+(double scalar);
		Matrix operator*(double scalar);
		
		Matrix operator-();

		/* matrix operator */
		Matrix operator+(Matrix& other);
		Matrix operator*(Matrix& other);

		/*__getter__*/
		int getRows() const;
		int getCols() const; 
	
		// double sum();
		// double max();

		// Matrix transpose();
		// Matrix square();
		// Matrix exp();
		// Matrix log();


		void print() const;
};

#endif
