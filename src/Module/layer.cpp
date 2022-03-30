#include "layer.hpp"

Layer::Layer() = default;

Layer::Layer(
  int inputLength, 
  int outputLength, 
  Matrix (*activationFunc)(Matrix& a), 
  Matrix (*dActivationFunc)(Matrix& activated)
){
}
