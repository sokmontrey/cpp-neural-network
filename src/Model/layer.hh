#ifndef LAYER_HH
#define LAYER_HH

#include <iostream>
#include <vector>

#include "../Matrix/matrix.hh"

class Layer{
	private:
		Matrix weight;
		Matrix bias;
		Matrix neuron;
		Matrix (*activation)(Matrix& x, bool isDerivative) = nullptr;

	public:
		Layer();
		Layer(int inputLength, int neuronLength);
		Layer(int inputLength, int neuronLength, Matrix (*func)(Matrix& x, bool isDerivative));
		Layer(int neuronLength);

		/*__neural network method__*/
		Matrix forward(Matrix& input);
		Matrix forward(Matrix input);
		Matrix forward(vector<vector<double>> input);

		/*__getter__*/
		int getNeuronSize();
		Matrix getWeight();
		Matrix getBias();
		Matrix getNeuron();

		/*__setter__*/
		void setWeight(Matrix& newWeight);
		void setBias(Matrix& newBias);

		void setWeight(Matrix newWeight);
		void setBias(Matrix newBias);

		void setActivation(Matrix (*func)(Matrix& x, bool isDerivative));
};

#endif
