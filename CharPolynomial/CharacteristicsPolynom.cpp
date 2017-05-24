#include "stdafx.h"
#include "CharacteristicsPolynom.h"



CharacteristicsPolynom::CharacteristicsPolynom(Matrix matrix)
{
	this->degree = matrix.GetSize();
	CalcCoefs(matrix);
	
	CalcRealRoots();
}

CharacteristicsPolynom::~CharacteristicsPolynom()
{
}


void CharacteristicsPolynom::CalcCoefs(Matrix matrix){
	int matrixSize = matrix.GetSize();
	int polySize = matrixSize + 1;
	//double[] coefs = new double[n + 1];
	int coefIndex = 0;

	//  коэффициент свободного  члена
	coefs.push_back(DetCalc::CalcDet(matrix));
	coefIndex++;
	int k = 1;
	//расчет коээфициентов от n-1 степени до 1
	for (k = 1; k < matrixSize; k++)
	{
		double coef = 0.0;
		vector<vector<int>> combinations = CalcCombinations(matrixSize, k);
		for (std::vector<vector<int>>::iterator it = combinations.begin(); it != combinations.end(); ++it) {
			vector<int> oneComb = *it;
			/* std::cout << *it; ... */
			//матрица, хранящая в себе подматрицы после вычеркивания столбцов и строк
			Matrix tempMatrix = Matrix(matrixSize - k);

			int tempi = 0;
			int tempj = 0;
			for (int i = 0; i < matrixSize; i++)
			{
				for (int j = 0; j < matrixSize; j++)
				{
					if (std::find(oneComb.begin(), oneComb.end(), i) == oneComb.end() &&
						std::find(oneComb.begin(), oneComb.end(), j) == oneComb.end())
					{
						
						tempMatrix.PutElem(tempi, tempj, matrix.GetElem(i, j));
						tempj++;
						if (tempj == tempMatrix.GetSize())
						{
							tempi++;
							tempj = 0;
						}
					}
				}

			}
			coef += DetCalc::CalcDet(tempMatrix);
			
		}
		//если степень у коэффициента нечетная, то нужно умножать на -1 коэффициент 
		if (k % 2 != 0)
			coef *= -1.0;
		coefs.push_back(coef);
		coefIndex++;

	}

	//коэффициент у старшей степени 
	if (k % 2 != 0)
		coefs.push_back(-1.0);
	else
		coefs.push_back(1.0);
	
}

vector<vector<int>> CharacteristicsPolynom::CalcCombinations(int N, int K){
	vector<vector<int>> result;
	vector<int> arr = vector<int>(K);

	int index = 0;

	std::string bitmask(K, 1); // K leading 1's
	bitmask.resize(N, 0); // N-K trailing 0's

	// print integers and permute bitmask
	do {
		for (int i = 0; i < N; ++i) // [0..N-1] integers
		{
			if (bitmask[i]){
				arr[index] = i;
				index++;
				//std::cout << " " << i;
			}
		}
		result.push_back(arr);
		index = 0;
		//std::cout << std::endl;
	} while (std::prev_permutation(bitmask.begin(), bitmask.end()));


	return result;
	
}

