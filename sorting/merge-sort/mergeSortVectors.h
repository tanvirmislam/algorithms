#ifndef __mergeSortVectors_H__
#define __mergeSortVectors_H__

#include <vector>


std::vector<int> mergeSortedVectors(const std::vector<int> &vec1, const std::vector<int> &vec2);
std::vector<int> mergeSort(const std::vector<int> &vec);
std::vector<int> mergeSort(const std::vector<int> &vec1, const std::vector<int> &vec2);


std::vector<int> mergeSortedVectors(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
	unsigned int i = 0, j = 0;
	std::vector<int> mergedVector;

	while ( (i < vec1.size()) && (j < vec2.size()) )
	{
		if ( vec1.at(i) < vec2.at(j) )
		{
			mergedVector.push_back( vec1.at(i) );
			i++;
		}
		else if ( vec2.at(j) < vec1.at(i) )
		{
			mergedVector.push_back( vec2.at(j) );
			j++;
		}
		else
		{
			mergedVector.push_back( vec1.at(i) );
			mergedVector.push_back( vec2.at(j) );
			i++;
			j++;
		}
	}

	while (i < vec1.size())
    {
        mergedVector.push_back( vec1.at(i) );
        i++;
    }

    while (j < vec2.size())
    {
        mergedVector.push_back( vec2.at(j) );
        j++;
    }

	return mergedVector;

}



std::vector<int> mergeSort(const std::vector<int> &vec)
{
    std::size_t const halfSize_1 = vec.size() / 2;
    std::vector<int> firstHalf_1 (vec.begin(), vec.begin() + halfSize_1);
    std::vector<int> secondHalf_1 (vec.begin() + halfSize_1, vec.end());

    std::vector<int> ans = mergeSort(firstHalf_1, secondHalf_1);

    return ans;
}


std::vector<int> mergeSort(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    if (vec1.size() == 1 && vec2.size() == 1)
    {
        std::vector<int> mergedVec = mergeSortedVectors(vec1, vec2);
        return mergedVec;
    }

    std::vector<int> sortedFirstHalf;
    std::vector<int> sortedSecondHalf;

    if (vec1.size() != 1)
    {
        std::size_t const halfSize_1 = vec1.size() / 2;
        std::vector<int> firstHalf_1 (vec1.begin(), vec1.begin() + halfSize_1);
        std::vector<int> secondHalf_1 (vec1.begin() + halfSize_1, vec1.end());

        sortedFirstHalf = mergeSort(firstHalf_1, secondHalf_1);
    }
    else
        sortedFirstHalf = std::move(vec1);

    if (vec2.size() != 1)
    {
        std::size_t const halfSize_2 = vec2.size() / 2;
        std::vector<int> firstHalf_2 (vec2.begin(), vec2.begin() + halfSize_2);
        std::vector<int> secondHalf_2 (vec2.begin() + halfSize_2, vec2.end());

        sortedSecondHalf = mergeSort(firstHalf_2, secondHalf_2);
    }
    else
        sortedSecondHalf = std::move(vec2);


    return mergeSortedVectors(sortedFirstHalf, sortedSecondHalf);

}




#endif //__mergeSortVectors_H__
