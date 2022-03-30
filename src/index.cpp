#include "./Matrix/matrix.hh"
#include "./Module/layer.hh"
#include "./Activation/activation.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	Matrix m(2,3,3);

	cout << Activation::sigmoid(3) << endl;
}