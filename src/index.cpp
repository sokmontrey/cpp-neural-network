#include "./Matrix/matrix.hh"
#include "./Activation/activation.hh"
#include "./Model/layer.hh"
#include "./Model/model.hh"
#include "./Loss/loss.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	
	//Model m({2,3,2}, {Activation::matrixSigmoid, Activation::matrixSigmoid});
	Model m({
			Layer(2),
			Layer(2,3),
			Layer(3,2)
			});

	m.setActivation({Activation::matrixSigmoid, Activation::matrixSigmoid});
	m.setLoss(Loss::mse);
	m.forward({{1,2}}).print();
	m.getOutput().print();
	cout << m.loss(Matrix({{1,1}})) << endl;
	m.matrixLoss(Matrix({{1,1}})).print();

  //test v2
}
