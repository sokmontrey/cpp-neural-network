#include "./Matrix/matrix.hh"
#include "./Activation/activation.hh"
#include "./Model/layer.hh"
#include "./Model/model.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	
	//Model m({2,3,2}, {Activation::matrixSigmoid, Activation::matrixSigmoid});
	Model m({
			Layer(2),
			Layer(2,3),
			Layer(3,2)
			});

	m.setActivation({Activation::matrixSigmoid, Activation::matrixSigmoid});
	m.print();
	cout << "\n-----------------\n";
	m.forward(Matrix({{1,1}})).print();
	//TODO: abiguis bug
	cout << "\n-----------------\n";
	m.print();
}
