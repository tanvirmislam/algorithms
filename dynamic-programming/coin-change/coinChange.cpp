#include <bits/stdc++.h>

using namespace std;

// Print vector using cout
ostream& operator<< (ostream& out, const vector<int>& v) {
	out << "[ ";
	for (auto& i : v) {
		out << i << " ";
	}
	out << "]\n";
	return out;
}

// coins
const vector<int> coins = {10, 1, 6};

// recursive approach
int coinChange_recursion(int val) {
	if (val == 0) {
		return 0;
	}

	int minCount = INT_MAX;
	int count;

	for (int i : coins) {
		if ((val - i) >= 0) {
			count = coinChange_recursion(val-i);
			minCount = min(minCount, count);
		}
	}

	return minCount + 1;
}


// dynamic programming
int coinChange_dp(int val) {
	/*
		coins = {10, 6, 1}
		value = 12

			0 1 2 3 4 5 6 7 8 9 10 11 12
		1	0 1 2 3 4 5 6 7 8 9 10 11 12

		10	0 1 2 3 4 5 6 7 8 9 1  2  3

		6	0 1 2 6 4 5 1 2 3 4 1  2  2 
	*/

	vector<int> cache(val + 1);
	
	cache[0] = 0;
	for (int i = 1; i < val + 1; i++) {
		cache[i] = INT_MAX;
	}

	for (int i = 0; i < (val+1); i++) {
		for (auto& c : coins) {
			if (i-c >= 0) {
				cache[i] = min(cache[i-c]+1, cache[i]);
			}
		}
	}

	cout << cache;
	return cache[val];
}



int main() {
	cout << coinChange_dp(12) << endl;
	return 0;
}