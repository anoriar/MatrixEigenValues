// CharPolynomial.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "FileReader.h"
#include "Matrix.h"
#include "CharacteristicsPolynom.h"

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
		CharacteristicsPolynom charPol;
		charPol.CalcCoefs(matrix);
		return 0;
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what();
	}
	
}


