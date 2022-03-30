#include "layer.hh"

/*__constructor__*/

Layer::Layer() = default;

Layer::Layer(
	int inputLength, int outputLength, 
	Matrix (*activationFunc)(Matrix& a), 
	Matrix (*dActivationFunc)(Matrix& activated)
){
	this->weight = Matrix(inputLength, outputLength, {-1, 1, 1});
	this->bias = Matrix(1, outputLength, {-1, 1, 1});
	this->output = Matrix(1, outputLength, 0);
  
	this->activation = activationFunc;
	this->dActivation = dActivationFunc;
}

/*__end_constructor__*/
Matrix Layer::forward(Matrix& input){
	output = input.matmul(weight) + bias;
	output = activation(output);
	return output;
}
Matrix Layer::forward(Matrix input){
	output = input.matmul(weight) + bias;
	output = activation(output);
	return output;
}

/*__getter__*/
Matrix Matrix::getOutput(){ return output; }
Matrix Matrix::getWeight(){ return weight; }
Matrix Matrix::getBias(){ return bias; }

/*__setter__*/
void Matrix::setWeight(Matrix& newWeight){
	weight = newWeight;
}
void Matrix::setBias(Matrix& newBias){
	bias = newBias;
}
