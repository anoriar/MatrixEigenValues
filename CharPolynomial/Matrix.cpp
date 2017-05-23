#include "stdafx.h"
#include "FileReader.h"


Matrix::Matrix(int size)
{
	this->size = size;
	this->matrix = new double*[size];
	for (int i = 0; i < size; i++){
		this->matrix[i] = new double[size];
	}

}


Matrix::~Matrix()
{
}


void Matrix::PutElem(int i, int j, double elem){
	if (i >= this->size || j >= this->size || i < 0 || j < 0)
		throw "Not valid position";
	this->matrix[i][j] = elem;
}

double Matrix::GetElem(int i, int j){
	if (i >= this->size || j >= this->size || i < 0 || j < 0)
		throw "Not valid position";
	if (matrix[i][j]){
		throw "This value is not exists";
	}
		
	return this->matrix[i][j];
}

int Matrix::GetSize(){
	return this->size;
}

void Matrix::Print(){
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size; j++){
			cout << this->matrix[i][j] << " ";
		}
		cout << endl;
	}
}