#include "stdafx.h"
#include "DetCalc.h"


double DetCalc::CalcDet(Matrix matrix){
	int size = matrix.GetSize();
	if (size == 1)
	{
		return matrix.GetElem(0, 0);
	}
	if (size == 2)
	{
		return matrix.GetElem(0, 0) * matrix.GetElem(1, 1) - matrix.GetElem(0, 1) * matrix.GetElem(1, 0);
	}
	double sign = 1.0, result = 0.0;
	for (int i = 0; i < size; i++)
	{
		Matrix minor = GetMinor(matrix, i, size);
		result += sign * matrix.GetElem(0, i) * CalcDet(minor);
		sign = -sign;
	}
	return result;
}


Matrix DetCalc::GetMinor(Matrix matrix, int pos, int size){
	Matrix result = Matrix(size - 1);
	for (int i = 1; i < size; i++)
	{
		for (int j = 0, col = 0; j < size; j++)
		{
			if (j == pos)
				continue;
			result.PutElem(i - 1, col, matrix.GetElem(i, j));
			col++;
		}
	}
	return result;
}