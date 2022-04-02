#ifndef MODEL_HH
#define MODEL_HH

#include <iostream>
#include <vector>

#include "../Matrix/matrix.hh"
#include "./layer.hh"

class Model{
	private:
		int size;
		vector<int> shape;
		//including input layer
		vector<Layer> layers;
	public:
		Model();
		Model(vector<int> shape, vector<Matrix (*)(Matrix& a, bool isDerivative)> activations);
		Model(vector<Layer> layers);

		/*__neural net method__*/
		Matrix forward(Matrix& input);
		Matrix forward(Matrix&& input);
		Matrix forward(vector<vector<double>> input);

		/*__getter__*/
		vector<Matrix> getWeight();
		vector<Matrix> getBias();
		vector<Matrix> getNeuron();

		/*__setter__*/
		void setActivation(vector<Matrix (*)(Matrix& a, bool isDerivative)> activations);

		void print();
};

#endif
