#ifndef LAYER_HH
#define LAYER_HH

#include <iostream>
#include <vector>

#include "../Matrix/matrix.hh"

using namespace std;

/*
 * input = [[a1, a2, ... , an]]
 * output = neuron = [[o1, o2, ... , on]]
 */
class Layer{
	private:
		Matrix weight;
		Matrix bias;
		Matrix neurons;
		Matrix (*activation)(Matrix& a);
		Matrix (*dActivation)(Matrix& activated);
		bool isOnlyNeuron = false;

	public:
		Layer();
		Layer(
			int inputLength, 
			int outputLength, 
			Matrix (*activationFunc)(Matrix& a), 
			Matrix (*dActivationFunc)(Matrix& activated)
		);
		Layer(int inputLength, int outputLength);
		//create a layer that has neurons
		//use for input layer
		Layer(int neuronLength);

		Matrix forward(Matrix& input);
		Matrix forward(Matrix input);

		/*__getter__*/
		Matrix getNeurons();
		Matrix getWeight();
		Matrix getBias();

		/*__setter__*/
		void setNeurons(Matrix& newNeurons);
		void setWeight(Matrix& newWeight);
		void setBias(Matrix& newBias);
		void setActivation(Matrix (*activationFunc)(Matrix& a));
		void setActivation(Matrix (*activationFunc)(Matrix& a), 
				Matrix (*dActivationFunc)(Matrix& activated));

		void setDActivation(Matrix (*dActivationFunc)(Matrix& activated));
};
#endif
