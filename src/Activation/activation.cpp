#include "./activation.hh"

double Activation::sigmoid(double x, 
		bool isDerivative=false, 
		bool isActivated=true){

	if(!isDerivative)
		return 1 / (1 + std::exp(-x));
	if(isActivated)
		return x * (1 - x);
	double e = std::exp(-x);
	return e / (1 + e) * (1 + e);
}

