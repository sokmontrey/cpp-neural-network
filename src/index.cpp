#include "./Matrix/matrix.hh"
#include "./Activation/activation.hh"
#include "./Model/layer.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	
	Layer l(2,3, Activation::matrixRelu);
	l.forward({{1,2}}).print();
}
