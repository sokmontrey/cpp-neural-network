#include <iosteam>
#include <vector>
#include <cmath>

using namespace std;

class Activation{
    public:
        double sigmoid(double x);
        double tanh(double x);
        double relu(double x);

        //parameter must be output from activation func
        //(activated)
        double dSigmoid(double activated);
        double dTanh(double activated);
        double dRelu(double activated);
};