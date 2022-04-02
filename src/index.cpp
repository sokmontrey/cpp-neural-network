#include "./Matrix/matrix.hh"
#include "./Activation/activation.hh"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	
	Matrix m({{0,1}});
	m.print();
	m.exp().print();
}
