#include "stdafx.h"
#include "CharacteristicsPolynom.h"


CharacteristicsPolynom::CharacteristicsPolynom()
{
	
}


CharacteristicsPolynom::~CharacteristicsPolynom()
{
}

void CharacteristicsPolynom::CalcCoefs(Matrix matrix){
	int n = matrix.GetSize();
	//double[] coefs = new double[n + 1];
	int coefIndex = 0;

	//  коэффициент свободного  члена
	
	coefs[coefIndex] = DetCalc::CalcDet(matrix);

	coefIndex++;

	//расчет коээфициентов от n-1 степени до 1
	for (int k = 1; k < n; k++)
	{
		double coef = 0.0;
		
		foreach(int[] c in Combinations(n, k))
		{
			//матрица, хранящая в себе подматрицы после вычеркивания столбцов и строк
			double[, ] tempMatrix = new double[n - k, n - k];
			int tempi = 0;
			int tempj = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (!c.Contains(i + 1) && !c.Contains(j + 1))
					{
						tempMatrix[tempi, tempj] = matrix[i, j];
						tempj++;
						if (tempj == tempMatrix.GetLength(0))
						{
							tempi++;
							tempj = 0;
						}
					}
				}

			}
			coef += DetRec(tempMatrix);
		}
		//если степень у коэффициента нечетная, то нужно умножать на -1 коэффициент 
		if (k % 2 != 0)
			coef *= -1.0;
		coefs[coefIndex] = coef;
		coefIndex++;

	}

	//коэффициент у старшей степени 
	if (n % 2 != 0)
		coefs[coefIndex] = -1.0;
	else
		coefs[coefIndex] = 1.0;

}

vector<int*> CharacteristicsPolynom::CalcCombinations(int N, int K){
	vector<int*> result;
	int arr[] = {1, 2, 3};
	result.push_back(arr);

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

