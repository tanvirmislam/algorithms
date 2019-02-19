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


int knapsack_recursive(vector<pair<int,int>>& v, int at, int currentVal, int currentWeight, const int maxWeight) {
	if (at >= v.size()) {
		return currentVal;
	}

	if (currentWeight < maxWeight) {
		int valIncluding = 0, valExcluding = 0;

		if (currentWeight + v[at].first <= maxWeight) {
			valIncluding = knapsack_recursive(v, at+1, currentVal + v[at].second, currentWeight + v[at].first, maxWeight);
		}
		valExcluding = knapsack_recursive(v, at+1, currentVal, currentWeight, maxWeight);
		
		return max(valIncluding, valExcluding);	
	}

	return 0;	
}


int knapsack_recursive(vector<pair<int,int>>& v, const int maxWeight) {
	return knapsack_recursive(v, 0, 0, 0, maxWeight);
}

/*

(1, 1), (3, 4), (4, 5), (5, 7)
m = 7

  0 1 2 3 4 5 6 7
0 0 0 0 0 0 0 0 0
1 0 1 1 1 1 1 1 1
2 0 1 1 *
3 0
4 0

*max(if we select, if we dont select)
*max(v + M[i-1][remaining w], M[i-1][w])

*/


int knapsack_dp(vector<pair<int,int>>& v, const int maxWeight) {
	// Cache matrix of size row+1, col+1
	vector<vector<int>> cache(v.size()+1, vector<int>(maxWeight+1));

	// printMatrix(cache);

	for (int i = 1; i < v.size()+1; i++) {
		int w   = v[i-1].first;
		int val = v[i-1].second;

		for (int j = 1; j < maxWeight+1; j++) {
			// cout << "at (" << i << "," << j << ") => ";
			if (j < w) {
				// cout << "cache[" << i << "][" << j << "] = cache[" << i-1 << "][" << j << "]" << endl;
				cache[i][j] = cache[i-1][j];
			}
			else {
				// cout << "cache[" << i << "][" << j << "] = max(" << val << " + cache[" << i-1 << "][" << j-w << "], cache[" << i-1 << "][" << j << "]" << endl;
				cache[i][j] = max(val + cache[i-1][j-w], cache[i-1][j]);
			}
		}
	}

	printMatrix(cache);

	return cache[v.size()][maxWeight];
}


int main() {
	vector<pair<int,int>> v = {make_pair(1, 1), make_pair(3, 4), make_pair(4, 5), make_pair(7, 5)};
	cout << knapsack_dp(v, 7) << endl;
}