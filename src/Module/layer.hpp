#include <iostream>
#include <vector>

#include "../Matrix/matrix.hpp"

using namespace std;

class Layer{
  private:
    Matrix weight;
    Matrix bias;
    Matrix output;
};
