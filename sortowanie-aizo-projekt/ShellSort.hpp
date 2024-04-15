#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "SortingAlgorithm.hpp"
#include <vector>

template <typename T>
class ShellSort : public SortingAlgorithm<T>
{
	protected:
		std::vector<int> distance_sequence;

	public:
		ShellSort(T* data_to_sort, int number_of_elements) : SortingAlgorithm<T>(data_to_sort, number_of_elements) {};

		void sort() override
		{
			int h, i, j;
			for(int x = this->distance_sequence.size() - 1; x >= 0; x--)
			{
				h = this->distance_sequence[x];
				i = h;
				while (i < this->number_of_elements) {
					j = i;
					while (j > h-1 && this->data_to_sort[j] < this->data_to_sort[j - h]) {
						this->swap(this->data_to_sort, j, j - h);
						j -= h;
					}
					i++;
				}
			}
		}
};

#endif