#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "SortingAlgorithm.hpp"

template <typename T>
class HeapSort : public SortingAlgorithm<T>
{
	public:
		HeapSort(T* data_to_sort, int number_of_elements) : SortingAlgorithm<T>(data_to_sort, number_of_elements) {};

		void heap_create_down(T* tab, int tab_len) {
			/*
			Function which uses Floyd's algorithm to create heap from array.
			*/
			for (int i = (tab_len - 2) / 2; i >= 0; --i) {
				heap_fix_down(tab, i, tab_len);
			}
		}

		void heap_fix_down(T* data_to_sort, int index, int number_of_elements) {
			/*
			Function which fixes heap in order to preserve heap parent child relationship, which specifies that parent's value can not be smaller than child's value.
			*/
			int left_child_index = 2 * index + 1;
			if (left_child_index > number_of_elements - 1) {
				return;
			}
			int right_child_index = 2 * index + 2;
			int swap_index = -1;
			if (data_to_sort[left_child_index] > data_to_sort[index]) {
				swap_index = left_child_index;
			}
			if (right_child_index <= number_of_elements-1 && 
				data_to_sort[right_child_index] > data_to_sort[index] && 
				data_to_sort[right_child_index] > data_to_sort[left_child_index]) {
				swap_index = right_child_index;
			}
			if (swap_index != -1) {
				this->swap(data_to_sort, swap_index, index);
				heap_fix_down(data_to_sort, swap_index, number_of_elements);
			}
		}

		void sort() override
		{
			/*
			Sorts the input data using heap data structure.
			*/
			this->heap_create_down(this->data_to_sort, this->number_of_elements);
			for (int i = this->number_of_elements - 1;  i > 0; i--) {
				this->swap(this->data_to_sort, 0, i);
				this->heap_fix_down(this->data_to_sort, 0, i);
			}
		}
};

#endif