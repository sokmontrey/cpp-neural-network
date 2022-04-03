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
		Matrix output;

		//including input layer
		vector<Layer> layers;
		Matrix (*lossFunc)(Matrix& output, Matrix& target, bool isDerivative);

	public:
		Model();
		Model(vector<int> shape, vector<Matrix (*)(Matrix& a, bool isDerivative)> activations);
		Model(vector<Layer> layers);

		/*__neural net method__*/
		Matrix forward(Matrix& input);
		Matrix forward(Matrix&& input);
		Matrix forward(vector<vector<double>> input);

		/*__loss__*/
		double loss(vector<vector<double>> target);
		Matrix matrixLoss(vector<vector<double>> target);
		Matrix dMatrixLoss(vector<vector<double>> target);
		double loss(Matrix& target);
		Matrix matrixLoss(Matrix& target);
		Matrix dMatrixLoss(Matrix& target);
		double loss(Matrix&& target);
		Matrix matrixLoss(Matrix&& target);
		Matrix dMatrixLoss(Matrix&& target);

		/*__getter__*/
		vector<Matrix> getWeight();
		vector<Matrix> getBias();
		vector<Matrix> getNeuron();
		Matrix getOutput();

		/*__setter__*/
		void setActivation(vector<Matrix (*)(Matrix& a, bool isDerivative)> activations);
		void setLoss(Matrix (*lossFunc)(Matrix& output, Matrix& target, bool isDerivative));

		void print();
};

#endif
