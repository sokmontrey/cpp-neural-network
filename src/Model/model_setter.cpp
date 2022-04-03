#include "./model.hh"

void Model::setActivation(vector<Matrix (*)(Matrix& a, bool isDerivative)> activations){
	for(int i=1; i<size; i++){
		this->layers[i].setActivation(activations[i-1]);
	}
}

void Model::setLoss(Matrix (*lossFunc)(
			Matrix& output, 
			Matrix& target, 
			bool isDerivative
		)){ this->lossFunc = lossFunc; }

void Model::print(){
	layers[0].getNeuron().print();
	for(int i=1; i<this->size; i++){
		layers[i].getWeight().print();
		layers[i].getBias().print();
		layers[i].getNeuron().print();
	}
}
