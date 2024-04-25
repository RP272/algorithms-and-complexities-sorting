#ifndef SHELLSORTCONSTRUCTOR_H
#define SHELLSORTCONSTRUCTOR_H
#include "ShellSortKnuthSequence.hpp"
#include "ShellSortSedgewickSequence.hpp"
#include "SequencePicker.hpp"

template <typename T>
class ShellSortConstructor {
	/*
	This is a static class which returns Shell sort objects based on the sequence picked by the user.
	*/
public:
	static ShellSort<T>* CreateInstance(T* data_to_sort, int number_of_elements, Sequence s)
	{
		switch (s)
		{
			case S_KNUTH: {
				return new ShellSortKnuthSequence<T>(data_to_sort, number_of_elements);
			}
			case S_SEDGEWICK: {
				return new ShellSortSedgewickSequence<T>(data_to_sort, number_of_elements);
			}
		}
		return nullptr;
	};
};

#endif