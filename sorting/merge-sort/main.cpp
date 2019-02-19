#include <iostream>
#include <vector>
#include "mergeSortVectors.h"

//using namespace std;

int main()
{
    std::vector<int> A = {1, 5, 3, 7, 9, 8, 11, 6, 4, 13, -5, -559, 2059, 5505, 1011};
    std::vector<int> B = {5, 3, 2, 6, 0};

    std::vector<int> sA = mergeSort(A);
    std::vector<int> sB = mergeSort(B);

    std::cout << "\n" << std::endl;
	for (int num : sA)
		std::cout << num << " ";
	std::cout << "\n" << std::endl;

	return 0;
}
