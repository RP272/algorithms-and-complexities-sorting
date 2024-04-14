#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "SortingAlgorithm.hpp"

template <typename T>
class HeapSort : public SortingAlgorithm<T>
{
	public:
		HeapSort(T* data_to_sort, int number_of_elements) : SortingAlgorithm<T>(data_to_sort, number_of_elements) {};

		void heap_create_down(T* tab, int tab_len) {
			for (int i = (tab_len- 2) / 2; i >= 0; --i) {
				heap_fix_down(tab, i, tab_len);
			}
		}

		void heap_fix_down(T* data_to_sort, int index, int number_of_elements) {
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
			for (int i = 0, k = this->number_of_elements; i < this->number_of_elements; i++, k--) {
				this->heap_create_down(this->data_to_sort, k);
				this->swap(this->data_to_sort, 0, k - 1);
			}
		}
};

#endif