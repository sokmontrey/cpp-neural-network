#include <iostream>
#include <vector>

using namespace std;

#include "./Matrix/matrix.hh"
#include "./Activation/activation.hh"

int main(){
	cout << Activation::sigmoid(1) << endl;
	cout << Activation::sigmoid(1, true)<< endl;
	cout << Activation::sigmoid(1, true, false)<< endl;
	cout << endl;
}
