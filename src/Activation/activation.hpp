#include <iosteam>
#include <vector>
#include <cmath>

using namespace std;

class Activation{
    public:
        double sigmoid(double x);
        double tanh(double x);
        double relu(double x);

        double dSigmoid(double x);
        double dTanh(double x);
        double dRelu(double x);
};