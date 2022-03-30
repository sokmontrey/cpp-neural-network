#ifndef ACTIVATION_HH
#define ACTIVATION_HH

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Activation{
    public:
        static double sigmoid(double x);
        static double tanh(double x);
        static double relu(double x);

        static double dSigmoid(double activated);
        static double dTanh(double activated);
        static double dRelu(double activated);
};

#endif