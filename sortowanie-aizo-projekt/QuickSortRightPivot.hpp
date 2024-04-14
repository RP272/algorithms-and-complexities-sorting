#ifndef QUICKSORTRIGHTPIVOT_H
#define QUICKSORTRIGHTPIVOT_H
#include "QuickSort.hpp"

template <typename T>
class QuickSortRightPivot : public QuickSort<T>
{
public:
	QuickSortRightPivot(T* data_to_sort, int number_of_elements) : QuickSort<T>(data_to_sort, number_of_elements) {};

	int partition(int left, int right) override {
		T pivot = this->data_to_sort[right];
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
