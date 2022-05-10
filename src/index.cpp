#include <iostream>
#include <vector>

using namespace std;

#include "./Matrix/matrix.hh"

int main(){
	Matrix a(vector<vector<double>> {{1,2,3}, {4,5,6}});
	Matrix b(vector<vector<double>>{{1,2,3}, {1,2,3}});
	Matrix::add(a, b).print();
	Matrix::mul(a, b).print();
	Matrix::add(a, 10).print();
	Matrix::mul(b, 10).print();
	cout << endl;
}
