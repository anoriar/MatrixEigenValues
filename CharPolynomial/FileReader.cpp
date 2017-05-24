#include "stdafx.h"
#include "Matrix.h"


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}


Matrix FileReader::read_file(const std::string& filename){
	
	std::ifstream fin;
	fin.open(filename);
	if (!fin)
		throw "File not found";
	int n;

	fin >> n;
	Matrix matrix = Matrix(n);
	double elem;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> elem;
			matrix.PutElem(i, j, elem);
		}
	}

	return matrix;
}