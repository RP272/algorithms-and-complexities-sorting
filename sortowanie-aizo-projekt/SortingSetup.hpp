#ifndef SORTINGSETUP_H
#define SORTINGSETUP_H
#include "InsertionSort.hpp"
#include "HeapSort.hpp"
#include "PivotPicker.hpp"
#include "QuickSortConstructor.hpp"
#include "SequencePicker.hpp"
#include "ShellSortConstructor.hpp"
#include <chrono>

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
		int decision;
		Pivot pivot;
		Sequence sequence;
		SortingAlgorithm<T>* algorithm = nullptr;
		while (true)
		{
			std::cout << "#######################################################" << std::endl;
			std::cout << "1. Sortowanie przez wstawianie" << std::endl;
			std::cout << "2. Sortowanie przez kopcowanie" << std::endl;
			std::cout << "3. Sortowanie Shella" << std::endl;
			std::cout << "4. Sortowanie szybkie" << std::endl;
			std::cout << "5. Zakoncz dzialanie programu" << std::endl;
			std::cout << "#######################################################" << std::endl;
			std::cout << "Wybierz algorytm sortowania lub zakoncz dzialanie programu: ";
			std::cin >> decision;
			switch (decision) {
			case 1: {
				algorithm = new InsertionSort<T>(this->data_to_sort, this->number_of_elements);
				break;
			}
			case 2: {
				algorithm = new HeapSort<T>(this->data_to_sort, this->number_of_elements);
				break;
			}
			case 3: {
				sequence = SequencePicker::pick();
				algorithm = ShellSortConstructor<T>::CreateInstance(this->data_to_sort, this->number_of_elements, sequence);
				break;
			}
			case 4: {
				pivot = PivotPicker::pick();
				algorithm = QuickSortConstructor<T>::CreateInstance(this->data_to_sort, this->number_of_elements, pivot);
				break;
			}
			case 5: {
				return;
			}
			}
			//algorithm->print_table();
			auto t1 = std::chrono::high_resolution_clock::now();
			algorithm->sort();
			auto t2 = std::chrono::high_resolution_clock::now();
			//algorithm->print_table();
			auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
			algorithm->array_sorted();
			std::cout << ms_int.count() << "ms" << std::endl;
			delete algorithm;
		}
	}
};
#endif
