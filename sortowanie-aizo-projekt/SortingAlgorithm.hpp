#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

template <typename T>
class SortingAlgorithm
{
	protected:
		int number_of_elements;
		T* data_to_sort;
	
	public:
		SortingAlgorithm(T* data_to_sort, int number_of_elements) {
			this->data_to_sort = new T[number_of_elements];
			std::memcpy(this->data_to_sort, data_to_sort, sizeof(T) * number_of_elements);
			this->number_of_elements = number_of_elements;
		}

		virtual void sort() = 0;

		void swap(T* data_to_sort, int a, int b) {
			T tmp;
			tmp = data_to_sort[a];
			data_to_sort[a] = data_to_sort[b];
			data_to_sort[b] = tmp;
		}

		void print_table() {
			for (int i = 0; i < this->number_of_elements; i++) {
				std::cout << this->data_to_sort[i] << " ";
			}
			std::cout << std::endl;
		}
};

#endif