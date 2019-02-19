#include <iostream>
#include <vector>
#include <random>
#include <time.h>

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

void swapVal(vector<int>& v, int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int partition(vector<int>& nums, int left, int right, int pivotVal) {
	while (left <= right) {
		while (nums[left] < pivotVal) {
			left++;
		}
		while (nums[right] > pivotVal) {
			right--;
		}

		if (left <= right) {
			swapVal(nums, left, right);
			left++;
			right--;
		}
	}

	return left;
}

void quicksort(vector<int>& nums, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivotIndex  = (start + (rand() % (int)(end - start + 1)));
	int splitPoint  = partition(nums, start, end, nums[pivotIndex]);
	quicksort(nums, start, splitPoint-1);
	quicksort(nums, splitPoint, end);
}


void quicksort(vector<int>& nums) {
	srand(time(NULL));
	quicksort(nums, 0, nums.size()-1);
}


int main() {
	vector<int> nums = {22, 45, 12, 8, -10, 6, -72, 81, 0, 33, 18, 50, 14};
	quicksort(nums);
	cout << nums;
	return 0;
}