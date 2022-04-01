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
	//
}

/*__setter__*/
void Model::setActivation(vector<string> activation){
	for(int i=1; i<layers.size(); i++){
		Matrix (*actFunc)(Matrix& a) = NULL;
		Matrix (*dActFunc)(Matrix& a) = NULL;
		if(activation[i-1] == "sigmoid"){
			actFunc = Activation::sigmoid;
			dActFunc = Activation::dSigmoid;
		}else if(activation[i-1] == "relu"){
			actFunc = Activation::relu;
			dActFunc = Activation::dRelu;
		}else if(activation[i-1] == "tanh"){
			actFunc = Activation::tanh;
			dActFunc = Activation::dTanh;
		}
		sequential[i].setActivation(actFunc, dActFunc);
	}
}
