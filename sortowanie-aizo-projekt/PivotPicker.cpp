#include "PivotPicker.hpp"

Pivot PivotPicker::pick() {
	std::cout << "1. Lewy" << std::endl;
	std::cout << "2. Prawy" << std::endl;
	std::cout << "3. Srodkowy" << std::endl;
	std::cout << "4. Losowy" << std::endl;
	std::cout << "Wybierz pivot: ";
	int pivot;
	while (!(std::cin >> pivot) || pivot < 1 || pivot > 4) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
	}
	return Pivot(pivot);
}
