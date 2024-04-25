#include <iostream>
#include "ActionTypePicker.hpp"

ActionType ActionTypePicker::pick() {
	/*
	*Pick which action would you like to perform.
	*/
	std::cout << "1. Wczytaj dane z pliku" << std::endl;
	std::cout << "2. Wygeneruj dane" << std::endl;
	std::cout << "3. Test wydajnosci algorytmu" << std::endl;
	std::cout << "Wybierz opcje: ";
	int selection;
	while (!(std::cin >> selection) || selection < 1 || selection > 3) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
	}
	return ActionType(selection);
}