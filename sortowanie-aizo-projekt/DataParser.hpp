#ifndef DATAPARSER_H
#define DATAPARSER_H
#include <iostream>
#include <fstream>
#include "FileReaderResult.hpp"
#include <sstream>

template<typename T>
class DataParser {
public:
	static T* parse(FileReaderResult result) {
		/*
		Very simple and straightforward function to parse strings from file.
		If the structure of the file doesn't follow rules specified in project instruction, 
		then results may not match our expectations. On the other hand if the text file is correct,
		then data will also be parsed correctly.
		*/
		T* parsed_data = new T[result.number_of_elements];
		T parsed_element;
		for (int i = 0; i < result.number_of_elements; i++) {
			std::istringstream(result.filelines[i]) >> parsed_element;
			parsed_data[i] = parsed_element;
		}
		return parsed_data;
	}
};

#endif