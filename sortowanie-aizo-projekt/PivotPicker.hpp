#ifndef PIVOTPICKER_H
#define PIVOTPICKER_H
#include <iostream>

enum Pivot {
	P_LEFT = 1,
	P_RIGHT = 2,
	P_MIDDLE = 3,
	P_RANDOM = 4
};

class PivotPicker
{
	public:
		static Pivot pick();
};

#endif
