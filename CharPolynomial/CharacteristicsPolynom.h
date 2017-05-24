#pragma once
#include "Matrix.h"
class Matrix;
#include "DetCalc.h"
class DetCalc;


class CharacteristicsPolynom
{
public:
	CharacteristicsPolynom();
	~CharacteristicsPolynom();
	void CharacteristicsPolynom::CalcCoefs(Matrix matrix);
	vector<vector<int>> CharacteristicsPolynom::CalcCombinations(int N, int K);

private:
	vector<double> coefs;
};

