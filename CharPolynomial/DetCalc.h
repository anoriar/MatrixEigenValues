#pragma once
#include "Matrix.h"
class Matrix;

class DetCalc
{

	public:
		static double CalcDet(Matrix matrix);
		static Matrix GetMinor(Matrix matrix, int pos, int size);

	private:

		DetCalc() {}
};

