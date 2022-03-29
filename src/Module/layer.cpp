#include "layer.hpp"

Layer::Layer() = default;

Layer::Layer(int inputLength, int outputLength, Matrix (*activationFunc)(Matrix& a), (*dActivationFunc)(Matrix& activated)){
  this->weight = new Matrix(inputLength, outputLength, -1, 1, 2);
  this->bias = new Matrix(outputLength, 1, -1, 1, 2);
}
