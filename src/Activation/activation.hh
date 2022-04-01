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
		static Matrix matrixSigmoid(Matrix& a);
		static Matrix matrixTanh(Matrix& a);
		static Matrix matrixRelu(Matrix& a);

		/*__derivative_activation__*/
		static Matrix dMatrixSigmoid(Matrix& a);
		static Matrix dMatrixTanh(Matrix& a);
		static Matrix dMatrixRelu(Matrix& a);
};

#endif
