#include "./Matrix/matrix.hh"
#include "./Model/layer.hh"
#include "./Activation/activation.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	Layer l(2,3,Matrix::relu, Matrix::dSigmoid);
	l.forward(Matrix({1,2})).print();
}
