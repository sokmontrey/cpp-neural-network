#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Matrix{
	private:
		int rows;
		int cols;

		vector<vector<double>> matrix;
	public:
		Matrix();
		Matrix(int rows, int cols, double value);
		Matrix(int rows, int cols, double min, double max);
		~Matrix();

		void print() const;
};


