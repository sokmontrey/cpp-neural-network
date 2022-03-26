#include <iostream>
#include <vector>
#include <math>

#include "activation.h"

using namespace std;

class Matrix{
	private:
		unsigned row;
		unsigned col;

		vector<vector<double>> matrix;
	public:
		Matrix(unsigned row, unsigned col, double value);
		Matrix(unsigned row, unsigned col, bool random);
		Matrix(unsigned row, unsigned col, bool random, double min, double max);
		Matrix(unsigned row, unsigned col, bool random, double min, double max, double seed);

		unsigned getRows() const;
		unsigned getCols() const;
		double operator()(unsigned row, unsigned col) const;

		//matrix operations
		Matrix operator+(Matrix& B);
		Matrix operator-(Matrix& B);
		Matrix operator*(Matrix& B); //matrix multiplication

		//scaler operations
		Matrix operator+(double scalar);
		Matrix operator-(double scalar);
		Matrix operator*(double scalar);
		Matrix operator/(double scalar);
		Matrix operator^(double power);

		Matrix transpose() const;
		Matrix clip(double min, double max);

		//activation functions
		Matrix sigmoid() const;
		Matrix relu() const;
		Matrix tanh() const;
		Matrix softmax() const;

		//derivative of activation functions
		Matrix dsigmoid() const;
		Matrix drelu() const;
		Matrix dtanh() const;
		Matrix dsoftmax() const;

		void print() const;
}


