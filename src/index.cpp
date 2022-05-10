#include <iostream>
#include <vector>

using namespace std;

#include "./Matrix/matrix.hh"

int main(){
	Matrix m({2,3}, {-1,1, 5});
	m.print();
	cout << endl;
}
