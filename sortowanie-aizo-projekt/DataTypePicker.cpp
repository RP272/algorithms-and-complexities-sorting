#include <iostream>
#include "DataTypePicker.hpp"

DataType DataTypePicker::pick() {
	std::cout << "1 -> Integer" << std::endl;
	std::cout << "2 -> Float" << std::endl;
	std::cout << "3 -> Char" << std::endl;
	int selection;
	while(true)
	{
		std::cout << "Wybierz typ danych, z którym chcesz pracowaæ:" << std::endl;
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			return DT_INTEGER;
		case 2:
			return DT_FLOAT;
		case 3:
			return DT_CHAR;
		default:
			std::cout << "Niew³aœciwy wybór" << std::endl;
			break;
		}
	}
}