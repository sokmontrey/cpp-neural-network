#include "activation.hpp"

double Activation::sigmoid(double x){
    return 1.0 / (1.0 + exp(-x));
}
double Activation::tanh(double x){
    return (2.0 / (1.0 + exp(-2 * x))) - 1.0;
}
double Activation::relu(double x){
    return max(0.0, x);
}

double Activation::dSigmoid(double x){
    double activated = Activation::sigmoid(x);
    return activated * (1.0 - activated);
}
double Activation::dTanh(double x){
    double activated = Activation::tanh(x);
    return 1.0 - pow(activated, 2);
}
double Activation::dRelu(double x){
    return (x>0 ? 1 : 0);
}
