#ifndef ACTIVATION_HH
#define ACTIVATION_HH

#include <iostream>
#include <vector>
#include <cmath>

#include "../Matrix/matrix.hh"

using namespace std;

class Activation{
    public:
        static double sigmoid(double x);
        static double tanh(double x);
        static double relu(double x);

        static double dSigmoid(double activated);
        static double dTanh(double activated);
        static double dRelu(double activated);

		/*____matrix____*/

		/*__activation__*/
		static Matrix sigmoid(Matrix& a);
		static Matrix tanh(Matrix& a);
		static Matrix relu(Matrix& a);

		/*__derivative_activation__*/
		static Matrix dSigmoid(Matrix& a);
		static Matrix dTanh(Matrix& a);
		static Matrix dRelu(Matrix& a);
};

#endif
