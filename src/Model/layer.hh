#ifndef LAYER_HH
#define LAYER_HH

#include <iostream>
#include <vector>
#include <string>

#include "../Matrix/matrix.hh"

class Layer{
	private:
		Matrix weight;
		Matrix bias;
		Matrix neuron;
		Matrix (*activation)(Matrix& x);

	public:
		Layer();
		Layer(int inputLength, int neuronLength);
		Layer(int inputLength, int neuronLength, Matrix (*func)(Matrix& x));

		/*__getter__*/
		Matrix getWeight();
		Matrix getBias();
		Matrix getNeuron();
};

#endif
