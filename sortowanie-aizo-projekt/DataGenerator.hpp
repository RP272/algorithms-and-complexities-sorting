#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

class DataGenerator
{
	public:
		static int* generate_integers(int tab_size);
		static float* generate_floats(int tab_size);
		static char* generate_chars(int tab_size);
};

#endif