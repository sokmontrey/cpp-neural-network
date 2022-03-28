#include <iosteam>
#include <vector>
#include <cmath>

using namespace std;

class Activation{
    public:
        double sigmoid(double x){
            return 1.0 / (1.0 + exp(-x));
        }
        double tanh(double x){
            return (2.0 / (1.0 + exp(-2 * x))) - 1.0;
        }
        double relu(double x){
            return max(0.0, x);
        }
};