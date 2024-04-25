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
	int selection;
	Sequence sequence;
	Pivot pivot;

public:
	SortingSetup() {};
	
	bool show_menu() {
		/*
		Let the user pick which algoritm to use.
		Work as long as 5 will not be selected.
		*/
		std::cout << "#######################################################" << std::endl;
		std::cout << "1. Sortowanie przez wstawianie" << std::endl;
		std::cout << "2. Sortowanie przez kopcowanie" << std::endl;
		std::cout << "3. Sortowanie Shella" << std::endl;
		std::cout << "4. Sortowanie szybkie" << std::endl;
		std::cout << "5. Zakoncz dzialanie programu" << std::endl;
		std::cout << "#######################################################" << std::endl;
		std::cout << "Wybierz algorytm sortowania lub zakoncz dzialanie programu: ";
		while (!(std::cin >> this->selection) || this->selection < 1 || this->selection > 5) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
		}
		if (this->selection == 5) return false;
		else if (this->selection == 3) {
			this->sequence = SequencePicker::pick();
		}
		else if (this->selection == 4) {
			this->pivot = PivotPicker::pick();
		}
		return true;
	}

	int run(T* data_to_sort, int number_of_elements, bool print_arrays) {
		/*
		Create sorting algorithm object based on user input.
		*/
		Pivot pivot;
		Sequence sequence;
		SortingAlgorithm<T>* algorithm = nullptr;
		switch (this->selection) {
			case 1: {
				algorithm = new InsertionSort<T>(data_to_sort, number_of_elements);
				break;
			}
			case 2: {
				algorithm = new HeapSort<T>(data_to_sort, number_of_elements);
				break;
			}
			case 3: {
				algorithm = ShellSortConstructor<T>::CreateInstance(data_to_sort, number_of_elements, this->sequence);
				break;
			}
			case 4: {
				algorithm = QuickSortConstructor<T>::CreateInstance(data_to_sort, number_of_elements, this->pivot);
				break;
			}
		}
		/*
		Print the array before sorting.
		*/
		if (print_arrays == true) {
			std::cout << "Tablica przed sortowaniem: ";
			algorithm->print_table();
		}
		/*
		Sort the array and measure the time consumption of it.
		*/
		auto t1 = std::chrono::high_resolution_clock::now();
		algorithm->sort();
		auto t2 = std::chrono::high_resolution_clock::now();
		/*
		Print the array after it has been sorted.
		Check if the array was correctly sorted aswell.
		*/
		if (print_arrays == true) {
			std::cout << "Tablica po sortowaniu: ";
			algorithm->print_table();
			algorithm->array_sorted();
		}
		auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		delete algorithm;
		return ms_int.count();
	}
};
#endif
