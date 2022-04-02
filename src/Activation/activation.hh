#ifndef ACTIVATION_HH
#define ACTIVATION_HH

#include <iostream>
#include <vector>
#include <cmath>

#include "../Matrix/matrix.hh"

using namespace std;

class Matrix;

class Activation{
	public:
		static double sigmoid(double x, bool isDerivative);
		static double tanh(double x, bool isDerivative);
		static double relu(double x, bool isDerivative);

		/*____matrix____*/
		static Matrix matrixSigmoid(Matrix& a, bool isDerivative);
		static Matrix matrixTanh(Matrix& a, bool isDerivative);
		static Matrix matrixRelu(Matrix& a, bool isDerivative);
};

#endif
