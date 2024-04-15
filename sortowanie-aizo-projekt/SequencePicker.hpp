#ifndef SEQUENCEPICKER_H
#define SEQUENCEPICKER_H
#include <iostream>

enum Sequence {
	S_KNUTH = 1,
	S_SEDGEWICK = 2
};

class SequencePicker
{
	public:
		static Sequence pick();
};

#endif
