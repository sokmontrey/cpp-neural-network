#ifndef MODEL_HH
#define MODEL_HH

#include <iostream>
#include <vector>
#include <string>

#include "layer.hh"
#include "../Matrix/matrix.hh"
#include "../Activation/activation.hh"

class Model{
    private:
		 vector<Layer> sequential;
		vector<int> layers;
		Matrix output;

    public:
        Model();
        Model(vector<int> layers);
		  Model(vector<Layer> sequential);

        Matrix predict(Matrix& input);
        Matrix predict(Matrix input);

		  /*__setter__*/
		  void setActivation(vector<string> activation);
}

#endif
