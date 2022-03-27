#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Matrix{
	private:
		int rows;
		int cols;

		vector<vector<double>> matrix;
		bool isInitialized = false;
	public:
		Matrix();
		Matrix(int rows, int cols);
		~Matrix();

		void randomize(double min, double max, double seed);

		double& operator()(int row, int col);

		void transpose() const;
		void print() const;
};


