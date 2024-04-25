#ifndef SHELLSORTKNUTHSEQUENCE_H
#define SHELLSORTKNUTHSEQUENCE_H
#include "ShellSort.hpp"
#include <cmath>

template <typename T>
class ShellSortKnuthSequence : public ShellSort<T>
{
	public:
		ShellSortKnuthSequence(T* data_to_sort, int number_of_elements) : ShellSort<T>(data_to_sort, number_of_elements)
		{
			/*
			Generate distance sequence for input array based on Knuth implementation.
			*/
			int k = 1;
			int max = ceil(number_of_elements / 3);
			int coefficient;
			while ( (coefficient = ((pow(3, k) - 1) / 2)) < max) {
				this->distance_sequence.push_back(coefficient);
				k++;
			}
		};
};

#endif