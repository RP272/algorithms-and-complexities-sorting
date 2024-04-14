#ifndef SORTINGSETUP_H
#define SORTINGSETUP_H
#include "InsertionSort.hpp"
#include "HeapSort.hpp"
#include "QuickSort.hpp"
#include "PivotPicker.hpp"
#include "QuickSortLeftPivot.hpp"
#include "QuickSortRightPivot.hpp"
#include "QuickSortMiddlePivot.hpp"
#include "QuickSortRandomPivot.hpp"

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
			int decision; 
			Pivot pivot;
			while (true) 
			{
				std::cout << "Wybierz algorytm sortowania lub zakoncz dzialanie programu: ";
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
						HeapSort<T>* heap_sort = new HeapSort<T>(this->data_to_sort, this->number_of_elements);
						std::cout << "Przed sortowaniem: ";
						heap_sort->print_table();
						heap_sort->sort();
						std::cout << "Po sortowaniu: ";
						heap_sort->print_table();
						break;
					}
					case 3: {
						break;
					}
					case 4: {
						pivot = PivotPicker::pick();
						QuickSort<T>* quick_sort = nullptr;
						switch (pivot)
						{
							case P_LEFT: {
								quick_sort = new QuickSortLeftPivot<T>(this->data_to_sort, this->number_of_elements);
								break;
							}
							case P_RIGHT: {
								quick_sort = new QuickSortRightPivot<T>(this->data_to_sort, this->number_of_elements);
								break;
							}
							case P_MIDDLE: {
								quick_sort = new QuickSortMiddlePivot<T>(this->data_to_sort, this->number_of_elements);
								break;
							}
							case P_RANDOM: {
								quick_sort = new QuickSortRandomPivot<T>(this->data_to_sort, this->number_of_elements);
								break;
							}
						}
						std::cout << "Przed sortowaniem: ";
						quick_sort->print_table();
						quick_sort->sort();
						std::cout << "Po sortowaniu: ";
						quick_sort->print_table();
						break;
					}
					case 5: {
						return;
					}
				}
			}
			
		}
};

#endif
