#pragma once
#include "Matrix.h"
class Matrix;

class FileReader
{
	public:
		FileReader();
		~FileReader();
		Matrix FileReader::read_file(const std::string& filename);
};

