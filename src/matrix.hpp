#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Matrix{
	private:
		int rows;
		int cols;

		vector<vector<double>> matrix;
	public:
		Matrix();
		Matrix(int rows, int cols, double value);
		Matrix(int rows, int cols, double min, double max);
		~Matrix();

		int getRows();
		int getCols();

		void operator= (Matrix& other);
		double& operator() (int row, int col);

		//scalar operations
		// to substract use + (-)
		// to devide use * (1/x)
		Matrix operator+ (double scalar) const;
		Matrix operator* (double scalar) const;
		Matrix operator^ (double scalar) const;

		void operator += (double scalar);

		//matrix operations
		Matrix operator+ (Matrix& other) const;
		Matrix operator* (Matrix& other) const;

		//transpose
		Matrix transpose() const;

		void print() const;
};


