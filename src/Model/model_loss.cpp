#include "./model.hh"

double Model::loss(vector<vector<double>> target){
	return this->lossFunc(this->output, target, false).sum();
}
Matrix Model::matrixLoss(vector<vector<double>> target){
	return this->lossFunc(this->output, target, false);
}
Matrix Model::dMatrixLoss(vector<vector<double>> target){
	return this->lossFunc(this->output, target, true);
}

double Model::loss(Matrix& target){
	return this->lossFunc(this->output, target, false).sum();
}
Matrix Model::matrixLoss(Matrix& target){
	return this->lossFunc(this->output, target, false);
}
Matrix Model::dMatrixLoss(Matrix& target){
	return this->lossFunc(this->output, target, true);
}

double Model::loss(Matrix&& target){
	return this->lossFunc(this->output, target, false).sum();
}
Matrix Model::matrixLoss(Matrix&& target){
	return this->lossFunc(this->output, target, false);
}
Matrix Model::dMatrixLoss(Matrix&& target){
	return this->lossFunc(this->output, target, true);
}
