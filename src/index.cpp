#include "matrix.hpp"

int main(){
	Matrix m(2,3,2);
	m.print();
	m = m + 3;
	m.print();
}
