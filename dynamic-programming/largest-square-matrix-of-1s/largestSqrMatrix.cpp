#include <bits/stdc++.h>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int largestSqrMat(vector<vector<int>> matrix) {
	int maxSqr = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (i != 0 && j != 0 && matrix[i][j] != 0) {
				matrix[i][j] = min( min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1] ) + 1;
			}

			maxSqr = max(matrix[i][j], maxSqr);
		}
	}

	return maxSqr;
}


int main() {
	vector<vector<int>> matrix = {	{0, 0, 1, 0, 1} ,
									{0, 1, 1, 1, 0} ,
									{0, 1, 1, 1, 1} ,
									{1, 1, 1, 1, 0} };


	cout << largestSqrMat(matrix) << endl;
}