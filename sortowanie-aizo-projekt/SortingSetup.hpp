#ifndef SORTINGSETUP_H
#define SORTINGSETUP_H
#include "InsertionSort.hpp"

template<typename T>
class SortingSetup
{
	private:
		int number_of_elements;
		T* data_to_sort;

	public:
		SortingSetup(T* data_to_sort, int number_of_elements) {
			this->data_to_sort = data_to_sort;
			this->number_of_elements = number_of_elements;
		}

		void show_menu() {
			std::cout << "1. Sortowanie przez wstawianie" << std::endl;
			std::cout << "2. Sortowanie przez kopcowanie" << std::endl;
			std::cout << "3. Sortowanie Shella" << std::endl;
			std::cout << "4. Sortowanie szybkie" << std::endl;
			std::cout << "5. Zakoncz dzialanie programu" << std::endl;
			std::cout << "Wybierz algorytm sortowania lub zakoncz dzialanie programu: ";
			int decision; 
			std::cin >> decision;
			switch (decision) {
				case 1: {
					InsertionSort<T>* insertion_sort = new InsertionSort<T>(this->data_to_sort, this->number_of_elements);
					std::cout << "Przed sortowaniem: ";
					insertion_sort->print_table();
					insertion_sort->sort();
					std::cout << "Po sortowaniu: ";
					insertion_sort->print_table();
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				case 5: {

				}
			}
		}
};

#endif
