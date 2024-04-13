#ifndef DATATYPEPICKER_H
#define DATATYPEPICKER_H

enum DataType
{
	DT_INTEGER = 1,
	DT_FLOAT = 2,
	DT_CHAR = 3
};

class DataTypePicker
{
	public:
		static DataType pick();
};

#endif