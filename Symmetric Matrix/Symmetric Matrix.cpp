#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
	void SetN(int n) {
		this->n = n;
	}
	int GetN() {
		return n;
	}
	int GetEle(int i, int j) {
		return matrix[i][j];
	}
	void Push(vector<int> row) {
		matrix.push_back(row);
	}
private:
	int n;
	vector<vector<int> > matrix;
};

bool IsElementSymmetric(Matrix* matrix, int row, int col) {
	int n = matrix->GetN();
	int center = n / 2;
	int tRow = row > center ? center - (row - center) : center + (center - row);
	int tCol = col > center ? center - (col - center) : center + (center - col);
	return matrix->GetEle(row, col) == matrix->GetEle(tRow, tCol);
}

bool IsSymmetric(Matrix* matrix) {
	int n = matrix->GetN();
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (!IsElementSymmetric(matrix, row, col))
				return false;
		}
	}
	return true;
}

int main()
{
	int testNum = 0;
	cin >> testNum;

	vector<Matrix*> matrixes;
	for (int i = 0; i < testNum; i++) {
		Matrix *matrix = new Matrix();
		int n = 0;
		cout << "N = ";
		cin >> n;
		matrix->SetN(n);

		int num = 0;
		for (int rowNum = 0; rowNum < n; rowNum++) {
			vector<int> row;
			for (int colNum = 0; colNum < n; colNum++) {
				cin >> num;
				row.push_back(num);
			}
			matrix->Push(row);
		}

		matrixes.push_back(matrix);
	}

	for (int i = 0; i < matrixes.size(); i++) {
		string output = IsSymmetric(matrixes[i]) ? "Symmetric" : "Non-symmetric";
		cout << "Test #" << i + 1 << ": " << output.c_str() << endl;
	}
}

