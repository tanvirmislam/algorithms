#include <iostream>
#include <vector>

using namespace std;

int fib_recursion(int n) {
	if (n <= 0) { return 0; }
	if (n == 1) { return 1; }

	return fib_recursion(n-1) + fib_recursion(n-2);
}

int fib_dp(int n) {
	vector<int> cache(n+1);
	cache[0] = 0;
	cache[1] = 1;

	for (int i = 2; i <= n; i++) {
		cache[i] = cache[i-1] + cache[i-2];
	}

	return cache[n];
}

int fib_dp_optimized(int n) {
	int n0 = 0;
	int n1 = 1;

	for (int i = 2; i <= n; i++) {
		int currentFib = n0 + n1;
		n0 = n1;
		n1 = currentFib;
	}

	return n1;
}

int main() {
	cout << fib_dp_optimized(6) << endl;
	return 0;
}