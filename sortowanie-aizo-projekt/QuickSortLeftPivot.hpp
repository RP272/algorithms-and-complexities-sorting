#ifndef QUICKSORTLEFTPIVOT_H
#define QUICKSORTLEFTPIVOT_H
#include "QuickSort.hpp"

template <typename T>
class QuickSortLeftPivot : public QuickSort<T>
{
	public:
		QuickSortLeftPivot(T* data_to_sort, int number_of_elements) : QuickSort<T>(data_to_sort, number_of_elements) {};

		int partition(int left, int right) override {
			/*
			Pick the first element as pivot.
			*/
			T pivot = this->data_to_sort[left];
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