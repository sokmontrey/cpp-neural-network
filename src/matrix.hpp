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
		~Matrix();

		double& operator()(int row, int col);

		//sclar operator
		Matrix operator+(double scalar);

		Matrix transpose();

		void print() const;
};
