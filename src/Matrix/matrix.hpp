#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "../Activation/activation.hpp"

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
		Matrix(int rows, int cols, vector<vector<double>> matrix);

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
		double sum();
		double max();

		Matrix transpose();
		Matrix square();
		Matrix exp();
		Matrix log();

		/*__activation__*/
		static Matrix sigmoid(Matrix& a);
		static Matrix tanh(Matrix& a);
		static Matrix relu(Matrix& a);

		/*__derivative_activation__*/
		static Matrix dSigmoid(Matrix& a);
		static Matrix dTanh(Matrix& a);
		static Matrix dRelu(Matrix& a);

		void print() const;
};
