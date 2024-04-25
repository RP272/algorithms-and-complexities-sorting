#ifndef GENERATEDDATAPARTIALSORTER
#define GENERATEDDATAPARTIALSORTER
#include <iostream>
#include "QuickSortConstructor.hpp"

enum PartialSort {
	PS_ASC_SORTED = 1,
	PS_DESC_SORTED = 2,
	PS_ONETHIRD_SORTED= 3,
	PS_TWOTHIRD_SORTED = 4,
	PS_INITIAL = 5
};

template <typename T>
class GeneratedDataPartialSorter 
{
	private:
		T* source_pointer;
		PartialSort partial_sort;
		QuickSort<T>* qs;

	public:
		GeneratedDataPartialSorter(PartialSort ps = PS_ASC_SORTED) {
			/*
			Pick the way you want the initial data to be sorted.
			*/
			std::cout << "1. Posortowane rosnaco" << std::endl;
			std::cout << "2. Posortowane malejaco" << std::endl;
			std::cout << "3. 33% pierwszych elementow posortowane rosnaco" << std::endl;
			std::cout << "4. 66% pierwszych elementow posortowane rosnaco" << std::endl;
			std::cout << "5. Nie zmieniaj kolejnosci wygenerowanych danych" << std::endl;
			std::cout << "Podaj poczatkowe posortowanie danych: ";
			int selection;
			while (!(std::cin >> selection) || selection < 1 || selection > 5) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
			}
			this->partial_sort = PartialSort(selection);
			this->qs = nullptr;
		}

		T* sort(T* data_to_sort, int number_of_elements) {
			this->source_pointer = data_to_sort;
			this->qs = QuickSortConstructor<T>::CreateInstance(data_to_sort, number_of_elements, P_LEFT);
			switch (this->partial_sort) {
				case PS_ASC_SORTED: {
					/*
					Sort the input data using quicksort.
					*/
					this->qs->sort();
					break;
				};
				case PS_DESC_SORTED: {
					/*
					Sort the input data using quicksort and then reverse the order of the elements.
					*/
					this->qs->sort();
					for (int i = 0; i < this->qs->number_of_elements / 2; i++) {
						this->qs->swap(this->qs->get_data_to_sort(), i, this->qs->number_of_elements - i - 1);
					}
					break;
				};
				case PS_ONETHIRD_SORTED: {
					/*
					Sort the input data using quicksort and shuffle the part of the array.
					*/
					this->qs->sort_first_n_elements(this->qs->number_of_elements / 3);
					break;
				};
				case PS_TWOTHIRD_SORTED: {
					/*
					Sort the input data using quicksort and shuffle the part of the array.
					*/
					this->qs->sort_first_n_elements(2 * this->qs->number_of_elements / 3);
					break;
				}
				case PS_INITIAL: {
					break;
				};
			}
			/*
			Copy the sorted array from quicksort object to the place pointed in memory by source pointer passed in as argument in the generated data partial sorter constructor.
			*/
			std::memcpy(this->source_pointer, this->qs->get_data_to_sort(), sizeof(T) * this->qs->number_of_elements);
			delete this->qs;
			return this->source_pointer;
		}
};
#endif