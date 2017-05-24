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

	//  ����������� ����������  �����
	
	coefs[coefIndex] = DetCalc::CalcDet(matrix);

	coefIndex++;

	//������ ������������� �� n-1 ������� �� 1
	for (int k = 1; k < n; k++)
	{
		double coef = 0.0;
		vector<vector<int>> combinations = CalcCombinations(n, k);
		for (std::vector<vector<int>>::iterator it = combinations.begin(); it != combinations.end(); ++it) {
			vector<int> oneComb = *it;
			/* std::cout << *it; ... */
			//�������, �������� � ���� ���������� ����� ������������ �������� � �����
			Matrix tempMatrix = Matrix(n - k);

			int tempi = 0;
			int tempj = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (std::find(oneComb.begin(), oneComb.end(), i + 1) != oneComb.end() &&
						std::find(oneComb.begin(), oneComb.end(), j + 1) != oneComb.end())
					{
						tempMatrix.PutElem(i, j, matrix.GetElem(i, j));
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
		//���� ������� � ������������ ��������, �� ����� �������� �� -1 ����������� 
		if (k % 2 != 0)
			coef *= -1.0;
		coefs[coefIndex] = coef;
		coefIndex++;

	}

	//����������� � ������� ������� 
	if (n % 2 != 0)
		coefs[coefIndex] = -1.0;
	else
		coefs[coefIndex] = 1.0;

	for (std::vector<double>::iterator it = coefs.begin(); it != coefs.end(); ++it) {
		 std::cout << *it;
	}

}

vector<vector<int>> CharacteristicsPolynom::CalcCombinations(int N, int K){
	vector<vector<int>> result;
	vector<int> arr = { 1, 2, 3 };
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

