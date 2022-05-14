#ifndef ACTIVATION_HH
#define ACTIVATION_HH

#include <cmath>
#include "../Matrix/matrix.hh"

class Activation{
	public:
		static double sigmoid(double x, bool isDerivative=false, bool isActivated=true);
		static double tanh(double x, bool isDerivative=false, bool isActivated=true);
		static double relu(double x, bool isDerivative=false);
}; 

#endif
