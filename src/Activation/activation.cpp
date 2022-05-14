#include "./activation.hh"

double Activation::sigmoid(double x, 
		bool isDerivative,
		bool isActivated){
	if(!isDerivative) return 1 / (1 + std::exp(-x));
	if(isActivated) return x * (1 - x);
	double ne = std::exp(-x);
	return ne / ( (1 + ne) * (1 + ne) );
}
double Activation::tanh(double x, 
		bool isDerivative,
		bool isActivated){
	if(!isDerivative) 
		double e = std::exp(x), ne = std::exp(-x); 
		return (e - ne) / (e + ne);
	if(isActivated) return 1 - (x * x)  
	return 1 - std::pow(Activation::tanh(x), 2);
}
double Activation::relu(double x,
		bool isDerivative){
	if(!isDerivative) return max(x, 0);
	return x>0 ? 1 : 0;
}


