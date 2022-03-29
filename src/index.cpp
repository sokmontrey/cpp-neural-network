#include "./Matrix/matrix.hpp"

int main(){
	Matrix m(3,3,-1, 1, 1);
	m.print();
	//use g++ to compile this file and all the files in the Matrix folder and Activation folder
	//g++ index.cpp -I./Matrix -I./Activation
}
