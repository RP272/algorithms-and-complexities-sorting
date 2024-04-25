#include "SequencePicker.hpp"

Sequence SequencePicker::pick() {
	/*
	Pick the sequence which should be used for Shell sort.
	*/
	std::cout << "1. Sekwencja Knutha" << std::endl;
	std::cout << "2. Sekwencja Sedgewicka" << std::endl;
	std::cout << "Wybierz sekwencje: ";
	int sequence;
	while (!(std::cin >> sequence) || sequence < 1 || sequence > 2) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Niewlasciwy wybor. Wprowadz ponownie: ";
	}
	return Sequence(sequence);
}