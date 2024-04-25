#ifndef QUICKSORTRANDOMPIVOT_H
#define QUICKSORTRANDOMPIVOT_H
#include "QuickSort.hpp"
#include <random>

template <typename T>
class QuickSortRandomPivot : public QuickSort<T>
{
public:
	QuickSortRandomPivot(T* data_to_sort, int number_of_elements) : QuickSort<T>(data_to_sort, number_of_elements) {};

	int partition(int left, int right) override {
		/*
		Pick a random element as pivot.
		*/
		srand(time(NULL));
		int index = left + rand() % (right - left);
		T pivot = this->data_to_sort[index];
		int l = left;
		int r = right;
		while (true) {
			while (this->data_to_sort[l] < pivot) ++l;
			while (this->data_to_sort[r] > pivot) --r;
			if (l < r) {
				this->swap(this->data_to_sort, l, r);
				++l;
				--r;
			}
			else {
				if (r == right) r--;
				return r;
			}
		}
	}
};

#endif
