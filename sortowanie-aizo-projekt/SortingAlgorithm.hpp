#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

template <typename T>
class SortingAlgorithm
{
	public:
		int number_of_elements;
		T* data_to_sort;

		SortingAlgorithm(T* data_to_sort, int number_of_elements) {
			this->data_to_sort = new T[number_of_elements];
			std::memcpy(this->data_to_sort, data_to_sort, sizeof(T) * number_of_elements);
			this->number_of_elements = number_of_elements;
		}

		~SortingAlgorithm() {
			delete this->data_to_sort;
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

		void array_sorted() {
			bool sorted = true;
			for (int i = 1; i < this->number_of_elements; i++) {
				if (this->data_to_sort[i] < this->data_to_sort[i - 1]) {
					sorted = false;
					break;
				}
			}
			if (sorted == true) {
				std::cout << "Dane posortowane poprawnie" << std::endl;
			}
			else {
				std::cout << "Dane nie zostaly posortowane ppoprawnie" << std::endl;
			}
		}

		void sort_first_n_elements(int n) {
			for (int i = 0; i < n; i++) {
				for (int j = this->number_of_elements - 1; j > i; j--) {
					if (this->data_to_sort[j] < this->data_to_sort[j - 1]) {
						this->swap(this->data_to_sort, j, j - 1);
					}
				}
			}
		}

		T* get_data_to_sort() {
			return this->data_to_sort;
		}
};

#endif