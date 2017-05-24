#pragma once
#include "Matrix.h"
class Matrix;
#include "DetCalc.h"
class DetCalc;
#include "Polynom.h"
class Polynom;


class CharacteristicsPolynom : public Polynom
{
public:
	CharacteristicsPolynom(Matrix matrix);
	~CharacteristicsPolynom();
	void CharacteristicsPolynom::CalcCoefs(Matrix matrix);
	vector<vector<int>> CharacteristicsPolynom::CalcCombinations(int N, int K);

};

