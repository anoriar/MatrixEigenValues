#pragma once

class Polynom
{
	public:
		Polynom();
		Polynom(vector<double> coefs);
		~Polynom();
		vector<double> GetCoefs();
		vector<double> GetRoots();
		void PrintPolynom();
		void PrintRoots();
		double GetValue(int n, double x, double *k);
		
	protected:
		int degree;
		vector<double> coefs;
		vector<double> roots;

		void CalcRealRoots();
		void Polynom::StepUp(int level, double **A, double **B, int *currentRootsCount);
		double Polynom::Dihot(int degree, double edgeNegativ, double edgePositiv, double *kf);

};

