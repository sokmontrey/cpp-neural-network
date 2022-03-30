#include "layer.hh"

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

