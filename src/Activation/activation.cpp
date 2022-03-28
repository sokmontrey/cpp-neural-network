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