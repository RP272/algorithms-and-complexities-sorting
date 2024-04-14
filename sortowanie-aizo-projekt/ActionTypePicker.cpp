#include <iostream>
#include "ActionTypePicker.hpp"

ActionType ActionTypePicker::pick() {
	std::cout << "1. Wczytaj dane z pliku" << std::endl;
	std::cout << "2. Wygeneruj dane" << std::endl;
	int selection;
	while (true)
	{
		std::cout << "Wybierz akcje, ktora chcesz przeprowadzic: ";
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			return AT_READ;
		case 2:
			return AT_GENERATE;
		default:
			std::cout << "Niewlasciwy wybor" << std::endl;
			break;
		}
	}
}