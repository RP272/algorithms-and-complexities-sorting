#ifndef QUICKSORTCONSTRUCTOR_H
#define QUICKSORTCONSTRUCTOR_H
#include "QuickSortLeftPivot.hpp"
#include "QuickSortRightPivot.hpp"
#include "QuickSortMiddlePivot.hpp"
#include "QuickSortRandomPivot.hpp"


template <typename T>
class QuickSortConstructor {
	public:
		static QuickSort<T>* CreateInstance(T* data_to_sort, int number_of_elements, Pivot p)
		{
			switch (p)
			{
				case P_LEFT: {
					return new QuickSortLeftPivot<T>(data_to_sort, number_of_elements);
				}
				case P_RIGHT: {
					return new QuickSortRightPivot<T>(data_to_sort, number_of_elements);
				}
				case P_MIDDLE: {
					return new QuickSortMiddlePivot<T>(data_to_sort, number_of_elements);
				}
				case P_RANDOM: {
					return new QuickSortRandomPivot<T>(data_to_sort, number_of_elements);
				}
			}
			return nullptr;
		};
};

#endif