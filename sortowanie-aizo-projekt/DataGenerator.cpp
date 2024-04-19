#include "DataGenerator.hpp"
#include "RandomIntegerGenerator.hpp"
#include "RandomFloatGenerator.hpp"

int* DataGenerator::generate_integers(int tab_size) {
	int* integers = new int[tab_size];
	RandomIntegerGenerator rng(-100000, 100000);
	for (int i = 0; i < tab_size; i++) {
		integers[i] = rng.generate();
	}
	return integers;
}

float* DataGenerator::generate_floats(int tab_size) {
	float* floats = new float[tab_size];
	RandomFloatGenerator rng(-100000, 100000);
	for (int i = 0; i < tab_size; i++) {
		floats[i] = rng.generate();
	}
	return floats;
}

char* DataGenerator::generate_chars(int tab_size) {
	char* chars = new char[tab_size];
	RandomIntegerGenerator rng(-128, 127);
	for (int i = 0; i < tab_size; i++) {
		chars[i] = rng.generate();
	}
	return chars;
}
