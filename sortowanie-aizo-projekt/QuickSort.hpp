#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortingAlgorithm.hpp"
#include "PivotPicker.hpp"

template <typename T>
class QuickSort : public SortingAlgorithm<T>
{
	/*
	This abstract class inherits from SortingAlgorithm.
	*/
	public:
		QuickSort(T* data_to_sort, int number_of_elements) : SortingAlgorithm<T>(data_to_sort, number_of_elements) {};

		/*
		Abstract method which is implemented in each of quicksort implementations, which has different variates of choosing pivots. The partition function is implemented in subclassed in order not to waste time execution on if statements which would pick the pivot element. This is used in order to measure time of only necessary actions which are responsible for the sorting of the elements.
		*/
		virtual int partition(int left, int right) = 0;
			
		
		void quicksort(int l, int p) {
			/*
			Revursive quickort method.
			It uses template method design pattern because of the fact that partition method is abstract and is implemented in each subclass independently.
			*/
			if (l >= p) return;
			int m = partition(l, p);
			/*
			Below if statements are implemented in order to prevent stack overflow from happening, when input data is already sorted and edge elements are used as pivots.
			*/
			if (m - l < p - m - 1) {
				quicksort(l, m);
				quicksort(m + 1, p);
			}
			else {
				quicksort(m + 1, p);
				quicksort(l, m);
			}
		}

		void sort() override {
			quicksort(0, this->number_of_elements - 1);
		}
};

#endif