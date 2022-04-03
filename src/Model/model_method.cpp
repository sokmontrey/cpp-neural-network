#include "./model.hh"

Matrix Model::forward(Matrix& input){
	layers[0].setNeuron(input);
	for(int i=1; i<size; i++){
		layers[i].forward(layers[i-1].getNeuron());
	}
	this->output = layers[size-1].getNeuron();
	return this->output;
}
Matrix Model::forward(Matrix&& input){
	layers[0].setNeuron(input);
	for(int i=1; i<size; i++){
		layers[i].forward(layers[i-1].getNeuron());
	}
	this->output = layers[size-1].getNeuron();
	return this->output;
}
Matrix Model::forward(vector<vector<double>> input){
	layers[0].setNeuron(Matrix(input));
	for(int i=1; i<size; i++){
		layers[i].forward(layers[i-1].getNeuron());
	}
	this->output = layers[size-1].getNeuron();
	return this->output;
}
