#pragma once
#include "FileReader.h"

class Matrix
{

public:
	Matrix(int size);
	~Matrix();
	void Matrix::PutElem(int i, int j, double elem);
	double Matrix::GetElem(int i, int j);
	int Matrix::GetSize();
	void Matrix::Print();

private:
	double **matrix;
	int size;
};

