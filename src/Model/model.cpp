#include "./model.hh"

Model::Model() = default;
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
/*__neural net method__*/
Matrix Model::forward(Matrix& input){
	layers[0].setNeuron(input);
	for(int i=1; i<size; i++){
		layers[i].forward(layers[i-1].getNeuron());
	}
	return layers[size-1].getNeuron();
}
Matrix Model::forward(Matrix&& input){
	layers[0].setNeuron(input);
	for(int i=1; i<size; i++){
		layers[i].forward(layers[i-1].getNeuron());
	}
	return layers[size-1].getNeuron();
}

/*__getter__*/
vector<Matrix> Model::getWeight(){
	vector<Matrix> weights;
	for(int i=1; i<size; i++){
		weights.push_back(layers[i].getWeight());
	}
	return weights;
}
vector<Matrix> Model::getBias(){
	vector<Matrix> biases;
	for(int i=1; i<size; i++){
		biases.push_back(layers[i].getBias());
	}
	return biases;
}
vector<Matrix> Model::getNeuron(){
	vector<Matrix> neurons;
	for(int i=0; i<size; i++){
		neurons.push_back(layers[i].getNeuron());
	}
	return neurons;
}

/*__setter__*/
void Model::setActivation(vector<Matrix (*)(Matrix& a, bool isDerivative)> activations){
	for(int i=1; i<size; i++){
		this->layers[i].setActivation(activations[i-1]);
	}
}

void Model::print(){
	layers[0].getNeuron().print();
	for(int i=1; i<this->size; i++){
		layers[i].getWeight().print();
		layers[i].getBias().print();
		layers[i].getNeuron().print();
	}
}
