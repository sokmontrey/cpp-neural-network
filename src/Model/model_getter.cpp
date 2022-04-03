#include "./model.hh"

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
Matrix Model::getOutput(){ return this->output; }

