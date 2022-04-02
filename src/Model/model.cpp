#include "./model.hh"

Model::Model() = default;
Model::Model(vector<int> shape){
	this->shape = shape;
	this->size = shape.size();
	this->layers.resize(size);
	this->layers[0] = Layer(shape[0]);
	for(int i=1; i<size; i++){
		this->layers[i] = Layer(shape[i-1], shape[i]);
	}
}
Model::Model(vector<int> shape, vector<Matrix (*)(Matrix& a, bool isDerivative)> activations){
	this->shape = shape;
	this->size = shape.size();
	this->layers.resize(size);
	this->layers[0] = Layer(shape[0]);
	for(int i=1; i<size; i++){
		this->layers[i] = Layer(shape[i-1], shape[i], activations[i-1]);
	}
}
Model::Model(vector<Layer> layers){
	this->size = layers.size();
	this->layers = layers;
	this->shape.resize(size);
	for(int i=0; i<size; i++){
		this->shape[i] = layers[i].getNeuronSize();
	}
}

void Model::setActivation(vector<Matrix (*)(Matrix& a, bool isDerivative)> activations){
	for(int i=1; i<size; i++){
		this->layers[i].setActivation(activations[i-1]);
	}
}
