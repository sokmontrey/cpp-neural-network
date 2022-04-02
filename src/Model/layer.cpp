#include "layer.hh"

Layer::Layer() = default;
Layer::Layer(int inputLength, int neuronLength){
	this->weight = Matrix(inputLength, neuronLength, {-1,1,0.1});
	this->bias = Matrix(1, neuronLength, {-1,1,0.5};
	this->neuron = Matrix(1, neuronLength, 0.0);
}
Layer::Layer(int inputLength, int neuronLength, Matrix (*func)(Matrix& x)){
	this->weight = Matrix(inputLength, neuronLength, {-1,1,0.1});
	this->bias = Matrix(1, neuronLength, {-1,1,0.5};
	this->neuron = Matrix(1, neuronLength, 0.0);
	this->activation = func;
}

/*__getter__*/
Matrix Layer::getWeight(){ return this->weight; }
Matrix Layer::getBias(){ return this->bias; }
Matrix Layer::getNeuron(){ return this->neuron; }

/*__setter__*/
void Layer::setWeight(Matrix& newWeight){ weight = newWeight; }
void Layer::setBias(Matrix& newBias){ bias = newBias; }

void Layer::setWeight(Matrix newWeight){ weight = newWeight; }
void Layer::setBias(Matrix newBias){ bias = newBias; }
