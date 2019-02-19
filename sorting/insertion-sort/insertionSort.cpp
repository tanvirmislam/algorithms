#include <iostream>
#include <vector>

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

// Insertion sort
void insertionSort(vector<int>& v) {
	int i, j, key;
	for (i = 0; i < v.size(); i++) {
		key = v[i];
		j = i - 1;

		// Sort comparing to the key
		while (j >= 0 && v[j] > key) {
			v[j+1] = v[j];
			j--;
		}

		v[j+1] = key;
	}
}

int main() {
	vector<int> nums = {25, -5, 3, 5, 2, 4, 9, 7, 8, 66, 0};
	insertionSort(nums);
	cout << nums;
}