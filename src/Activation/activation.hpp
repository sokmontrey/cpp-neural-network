#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Activation{
    public:
        static double sigmoid(double x);
        static double tanh(double x);
        static double relu(double x);

        static double dSigmoid(double x);
        static double dTanh(double x);
        static double dRelu(double x);
};
