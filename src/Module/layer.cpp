#include "layer.hh"

Layer::Layer() = default;

Layer::Layer(
  int inputLength, 
  int outputLength, 
  Matrix (*activationFunc)(Matrix& a), 
  Matrix (*dActivationFunc)(Matrix& activated)
){
  this->weight = Matrix(inputLength,outputLength,{-1,1,1});
  this->bias = Matrix(outputLength,1,{-1,1,1});
  this->output = Matrix(outputLength, 1, 0);
  
  this->activation = activationFunc;
  this->dActivation = dActivationFunc;
}
