#ifndef SHELLSORTSEDGEWICKSEQUENCE_H
#define SHELLSORTSEDGEWICKSEQUENCE_H
#include "ShellSort.hpp"
#include <cmath>

template <typename T>
class ShellSortSedgewickSequence : public ShellSort<T>
{
public:
	ShellSortSedgewickSequence(T* data_to_sort, int number_of_elements) : ShellSort<T>(data_to_sort, number_of_elements)
	{
		this->distance_sequence.push_back(1);
		int k = 1;
		int coefficient;
		while ((coefficient = (pow(4, k) + 3 * pow(2, k-1) + 1)) < number_of_elements) {
			this->distance_sequence.push_back(coefficient);
			k++;
		}
	};
};

#endif