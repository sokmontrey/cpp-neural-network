#include "./Matrix/matrix.hpp"

int main(){
	//g++ index.cpp ./Matrix/*.cpp ./Activation/*.cpp
	Matrix m(2,3,3);
	m.print();
	m = Matrix(3,2,1);
	m.print();
}
