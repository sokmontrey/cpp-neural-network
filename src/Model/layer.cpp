#include "layer.hh"

Layer::Layer() = default;
Layer::Layer(int inputLength, int neuronLength){
	this->weight = Matrix(inputLength, neuronLength, {-1,1,0.1});
	this->bias = Matrix(1, neuronLength, {-1,1,0.5});
	this->neuron = Matrix(1, neuronLength, 0.0);
}
Layer::Layer(int inputLength, int neuronLength, Matrix (*func)(Matrix& x, bool isDerivative)){
	this->weight = Matrix(inputLength, neuronLength, {-1,1,0.1});
	this->bias = Matrix(1, neuronLength, {-1,1,0.5});
	this->neuron = Matrix(1, neuronLength, 0.0);
	this->activation = func;
}
Layer::Layer(int neuronLength){
	this->neuron = Matrix(1, neuronLength, 0.0);
}
/*__neural network method__*/
Matrix Layer::forward(Matrix& input){
	this->neuron = input.matmul(this->weight) + this->bias;
	if(this->activation != nullptr){
		this->neuron = this->activation(this->neuron, false);
	}
	return this->neuron;
}
Matrix Layer::forward(Matrix input){
	this->neuron = input.matmul(this->weight) + this->bias;
	if(this->activation != nullptr){
		this->neuron = this->activation(this->neuron, false);
	}
	return this->neuron;
}
Matrix Layer::forward(vector<vector<double>> input){
	this->neuron = Matrix(input).matmul(this->weight) + this->bias;
	if(this->activation != nullptr){
		this->neuron = this->activation(this->neuron, false);
	}
	return this->neuron;
}

/*__getter__*/
int Layer::getNeuronSize(){
	return this->neuron.getCols();
}

Matrix Layer::getWeight(){ return this->weight; }
Matrix Layer::getBias(){ return this->bias; }
Matrix Layer::getNeuron(){ return this->neuron; }

/*__setter__*/
void Layer::setNeuron(Matrix& newNeuron){ neuron = newNeuron; }
void Layer::setNeuron(Matrix&& newNeuron){ neuron = newNeuron; }

void Layer::setWeight(Matrix& newWeight){ weight = newWeight; }
void Layer::setBias(Matrix& newBias){ bias = newBias; }

void Layer::setWeight(Matrix newWeight){ weight = newWeight; }
void Layer::setBias(Matrix newBias){ bias = newBias; }

void Layer::setActivation(Matrix (*func)(Matrix& x, bool isDerivative)){ 
	activation = func; 
}
