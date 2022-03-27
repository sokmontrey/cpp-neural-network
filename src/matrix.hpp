#include <iostream>
#include <random>
#include <vector>

using namespace std;
class Matrix{
	private:
		int rows;
		int cols;
		vector<vector<double>> matrix;
	public:
		Matrix();
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, double value);
		Matrix(int rows, int cols, double min, double max, double seed);
		Matrix(int rows, int cols, vector<vector<double>> matrix);
		~Matrix();

		double& operator()(int row, int col);

		/*__scalar_operator__*/
		Matrix operator+(double scalar);
		Matrix operator*(double scalar);
		Matrix operator-(double scalar);
		Matrix operator/(double scalar);

		/*__matrix_operator__*/
		Matrix operator**(Matrix& matrix);
		Matrix operator*(Matrix& matrix);
		Matrix operator+(Matrix& matrix);
		Matrix operator-(Matrix& matrix);

		Matrix operator-();

		Matrix transpose();

		void print() const;
};
