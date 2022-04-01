#include "model.hh"

Model::Model() = default;
Model::Model(vector<int> layers){
	this->layers = layers;
	sequential.resize(layers.size());
	sequential[0] = new Layer(layers[0]);
	for(int i=1; i<layers.size(); i++){
		sequential[i] = new Layer(layers[i-1], layers[i]);
	}
}
Model::Model(vector<Layer> sequential){
	this->sequential = sequential;
}
Matrix Model::predict(Matrix input){
	//TODO: in LAYER class create setter to set input
	sequential[0].setNeurons(input);
	for(int i=1; i<layers.size(); i++){
		sequential[i].forward(sequential[i-1].getNeurons());
	}
	return sequential[layer.size()-1].getNeurons();
}
Matrix Model::predict(Matrix& input){
	//TODO: in LAYER class create setter to set input
	sequential[0].setNeurons(input);
	for(int i=1; i<layers.size(); i++){
		sequential[i].forward(sequential[i-1].getNeurons());
	}
	return sequential[layer.size()-1].getNeurons();
}
/*__setter__*/
void Model::setActivation(vector<string> activation){
	for(int i=1; i<layers.size(); i++){
		Matrix (*actFunc)(Matrix& a) = NULL;
		Matrix (*dActFunc)(Matrix& a) = NULL;
		if(activation[i-1] == "sigmoid"){
			actFunc = Activation::matrixSigmoid;
			dActFunc = Activation::dMatrixSigmoid;
		}else if(activation[i-1] == "relu"){
			actFunc = Activation::matrixRelu;
			dActFunc = Activation::dMatrixRelu;
		}else if(activation[i-1] == "tanh"){
			actFunc = Activation::matrixTanh;
			dActFunc = Activation::dMatrixTanh;
		}
		sequential[i].setActivation(actFunc, dActFunc);
	}
}
