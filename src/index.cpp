#include "./Matrix/matrix.hh"
#include "./Model/layer.hh"
#include "./Activation/activation.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	Matrix m(2,3);
	m.print();
}
