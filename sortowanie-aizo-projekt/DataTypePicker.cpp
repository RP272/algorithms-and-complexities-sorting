#include <iostream>
#include "DataTypePicker.hpp"

DataType DataTypePicker::pick() {
	std::cout << "1. Integer" << std::endl;
	std::cout << "2. Float" << std::endl;
	std::cout << "3. Char" << std::endl;
	std::cout << "Wybierz typ danych, z ktorym chcesz pracowac: ";
	int selection;
    while (!(std::cin >> selection) || selection < 1 || selection > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
    }
	return DataType(selection);
}