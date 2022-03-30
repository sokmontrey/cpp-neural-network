#ifndef LAYER_HH
#define LAYER_HH

#include <iostream>
#include <vector>

#include "../Matrix/matrix.hh"

using namespace std;

/*
 * input = [[a1, a2, ... , an]]
 * output = [[o1, o2, ... , on]]
 */
class Layer{
  private:
    Matrix weight;
    Matrix bias;
    Matrix output;
    Matrix (*activation)(Matrix& a);
    Matrix (*dActivation)(Matrix& activated);
  
  public:
    Layer();
    Layer(
      int inputLength, 
      int outputLength, 
      Matrix (*activationFunc)(Matrix& a), 
      Matrix (*dActivationFunc)(Matrix& activated)
    );
  
    Matrix forward(Matrix& input);
    Matrix forward(Matrix input);
  
    /*__getter__*/
    Matrix getOutput();
    Matrix getWeight();
    Matrix getBias();
  
    /*__setter__*/
    void setWeight(Matrix& newWeight);
    void setBias(Matrix& newBias);
};
#endif
