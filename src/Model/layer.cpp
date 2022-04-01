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
	this->neurons = Matrix(1, outputLength, 0);
  
	this->activation = activationFunc;
	this->dActivation = dActivationFunc;
}
Layer::Layer(int inputLength, int outputLength){
	weight = Matrix(inputLength, outputLength, {-1, 1, 1});
	bias = Matrix(1, outputLength, {-1, 1, 1});
	neurons = Matrix(1, outputLength, 0);
	activation = NULL;
	dActivation = NULL;
}
Layer::Layer(int neuronLength){
	weight = NULL;
	bias = NULL;
	neurons = Matrix(1, neuronLength, 0);
	activation = NULL;
	dActivation = NULL;
	isOnlyNeuron = true;
}

/*__end_constructor__*/
Matrix Layer::forward(Matrix& input){
	neurons = input.matmul(weight) + bias;
	neurons = activation(neurons);
	return neurons;
}
Matrix Layer::forward(Matrix input){
	neurons = input.matmul(weight) + bias;
	neurons = activation(neurons);
	return neurons;
}

/*__getter__*/
Matrix Matrix::getOutput(){ return neurons; }
Matrix Matrix::getWeight(){ return weight; }
Matrix Matrix::getBias(){ return bias; }

/*__setter__*/
void Matrix::setWeight(Matrix& newWeight){
	weight = newWeight;
}
void Matrix::setBias(Matrix& newBias){
	bias = newBias;
}
void Matrix::setActivation(Matrix (*activationFunc)(Matrix& a)){
	activation = activationFunc;
}
void Matrix::setActivation(Matrix (*activationFunc)(Matrix& a), 
		Matrix (*dActivationFunc)(Matrix& activated)){
	activation = activationFunc;
	dActivation = dActivationFunc;
}
void Matrix::setDActivation(Matrix (*dActivationFunc)(Matrix& activated)){
	dActivation = dActivationFunc;
}
