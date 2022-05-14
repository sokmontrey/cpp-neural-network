#ifndef ACTIVATION_HH
#define ACTIVATION_HH

#include <cmath>
#include "../Matrix/matrix.hh"

class Activation{
	public:
		static double sigmoid(double x,bool isDerivative,bool isActivated);
}; 

#endif
