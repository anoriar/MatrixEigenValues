#include "stdafx.h"
#include "FileReader.h"


Matrix::Matrix(int size)
{
	this->size = size;
	matrix = vector<vector<double>>(size);

	//this->matrix = new double*[size];
	for (int i = 0; i < size; i++){
		matrix[i].resize(size);
	}

}


Matrix::~Matrix()
{
}


void Matrix::PutElem(int i, int j, double elem){
	if (i >= this->size || j >= this->size || i < 0 || j < 0){
		string msg = "Position: " + std::to_string(i) + " " + std::to_string(j) + " not exists";
		throw std::runtime_error(msg);
	}
	this->matrix[i][j] = elem;
}

double Matrix::GetElem(int i, int j){
	if (i >= this->size || j >= this->size || i < 0 || j < 0){
		string msg = "Position: " + std::to_string(i) + " " + std::to_string(j) + " not exists";
		throw std::runtime_error(msg);
	}
		
		
	return this->matrix[i][j];
}

int Matrix::GetSize(){
	return this->size;
}

void Matrix::Print(){
	cout << "Matrix:" << endl;
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size; j++){
			cout << this->matrix[i][j] << " ";
		}
		cout << endl;
	}
}