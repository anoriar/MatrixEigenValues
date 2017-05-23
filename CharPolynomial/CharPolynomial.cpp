// CharPolynomial.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "FileReader.h"
#include "Matrix.h"




void print_matrix(double** matrix){
	int size = sizeof(matrix) / sizeof(matrix[0]);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}


int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
			throw "Not valid number of arguments";
		cout << "Hello world!" << endl;
		FileReader filereader;
		Matrix matrix = filereader.read_file(argv[1]);
	
		matrix.Print();
		return 0;
	}
	catch (char *e)
	{
		cout << "An exception occurred. Exception. " << e << '\n';
	}
	
}


