#ifndef LOSS_HH
#define LOSS_HH

#include <iostream>
#include <cmath>

#include "../Matrix/matrix.hh"

class Matrix;

class Loss{
	public:
		static double mse(Matrix& output, Matrix& target);

		static Matrix matrixMSE(Matrix& output, 
				Matrix& target, 
				bool isDerivative);

};

#endif
