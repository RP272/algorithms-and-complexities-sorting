#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "SortingAlgorithm.hpp"

template <typename T>
class InsertionSort : public SortingAlgorithm<T>
{
	public:
		InsertionSort(T* data_to_sort, int number_of_elements) : SortingAlgorithm<T>(data_to_sort, number_of_elements) {};

		void sort() override
		{
			int i = 1;
			int j;
			while (i < this->number_of_elements) {
					j = i;
					while (j > 0 && this->data_to_sort[j] < this->data_to_sort[j-1]) {
							this->swap(this->data_to_sort, j, j - 1);
							j--;
					}
				i++;
			}
		}

		void sort_first_n_elements(int n) 
		{
			int i = 1;
			int j;
			while (i < n) {
				j = i;
				while (j > 0 && this->data_to_sort[j] < this->data_to_sort[j - 1]) {
					this->swap(this->data_to_sort, j, j - 1);
					j--;
				}
				i++;
			}
		}
};

#endif