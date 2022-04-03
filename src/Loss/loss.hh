#ifndef LOSS_HH
#define LOSS_HH

#include <iostream>
#include <cmath>

#include "../Matrix/matrix.hh"

class Matrix;

class Loss{
	public:
		static Matrix mse(Matrix& output, 
				Matrix& target, 
				bool isDerivative);

};

#endif
