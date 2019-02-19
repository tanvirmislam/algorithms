#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

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
	if (v.empty()) {
		return;
	}

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

// bucketSort
vector<int> bucketSort(vector<int>& v) {
	vector<int> sorted;
	
	if (v.empty()) {
		return sorted;
	}

	// n buckets, where # of buckets =  ceil(max/10) - floor(min/10)  + 1;
	int minVal = v[0], maxVal = v[0], n = v.size();
	for (auto& i : v) {
		minVal = min(minVal, i);
		maxVal = max(maxVal, i);
	}

	int numberOfBuckets = ceil(maxVal/10) - floor(minVal/10)  + 1;
	vector<vector<int>> buckets(numberOfBuckets);

	cout << "min: " << minVal << endl;
	cout << "max: " << maxVal << endl;
	cout << "bucket: " << numberOfBuckets << "\n" << endl;

	for (auto& i : v) {
		int bucketIndex = floor(i / 10);

		cout << "i = " << i << endl;
		cout << "bucketIndex = " << bucketIndex << "\n" << endl;

		buckets[bucketIndex].push_back(i);
	}

	for (auto& vec : buckets) {
		insertionSort(vec);
		for (auto& i : vec) {
			cout << "adding " << i << endl;
			sorted.push_back(i);
		}
	}
	cout << endl;

	return sorted;
}


int main() {
	// vector<int> nums = {25, 3, 5, 2, 4, 9, 7, 8, 66, 0};
	vector<int> nums = {22, 45, 12, 8, 10, 6, 72, 81, 33, 18, 50, 14};
	vector<int> sortedNums = bucketSort(nums);
	cout << sortedNums;
}