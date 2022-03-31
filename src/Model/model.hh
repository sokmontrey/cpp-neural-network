#ifndef MODEL_HH
#define MODEL_HH

#include <iostream>
#include <vector>
#include <string>

#include "layer.hh"

class Model{
    private:
        vector<Layer> model;
        vector<int> layer;
        vector<string> activation;

    public:
        Model();
        Model(vector<int> layer, vector<string> activation);

        Matrix forward(Matrix& input);
        Matrix forward(Matrix input);
}

#endif
