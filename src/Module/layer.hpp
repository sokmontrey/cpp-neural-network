#include <iostream>
#include <vector>

#include "../Matrix/matrix.hpp"

using namespace std;

class Layer{
  private:
    Matrix weight;
    Matrix bias;
    Matrix output;
    Matrix (*activationFunction)(Matrix& a);
    Matrix (*dActivationFunction)(Matrix& activated);
  
  public:
    Layer();
    Layer(int inputLength, int outputLength, Matrix (*activationFunc)(Matrix& a), Matrix (*dActivationFunc)(Matrix& activated));
  
    Matrix forward(Matrix& input);
  
    /*__getter__*/
    Matrix getOutput();
    Matrix getWeight();
    Matrix getBias();
  
    /*__setter__*/
    void setWeight(Matrix& newWeight);
    void setBias(Matrix& newBias);
};
