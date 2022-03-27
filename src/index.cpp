#include "matrix.hpp"

int main(){
	//Matrix<int> m1(2,2);
	Matrix m(20,20,0,1);
	m.print();
	Matrix m2 = m.transpose();
	m2.print();

	return 0;
}

