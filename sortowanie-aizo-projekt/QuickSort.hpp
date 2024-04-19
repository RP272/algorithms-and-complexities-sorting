#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortingAlgorithm.hpp"
#include "PivotPicker.hpp"

template <typename T>
class QuickSort : public SortingAlgorithm<T>
{
	public:
		QuickSort(T* data_to_sort, int number_of_elements) : SortingAlgorithm<T>(data_to_sort, number_of_elements) {};

		virtual int partition(int left, int right) = 0;
			
		void quicksort(int l, int p) {
			if (l >= p) return;
			int m = partition(l, p);
			quicksort(l, m);
			quicksort(m + 1, p);
		}

		void sort() override {
			quicksort(0, this->number_of_elements - 1);
		}
};

#endif