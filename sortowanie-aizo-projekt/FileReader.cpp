#include "FileReader.hpp"
#include "FileReaderResult.hpp"
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>

FileReaderResult FileReader::read(const std::string& filename) 
{
    std::string* filelines = nullptr;
    int number_of_elements = 0;
    std::ifstream input_file(filename);
    if (input_file.good()) {
        std::string line;
        // First line has to be a valid integer which indicates the number of elements
        std::getline(input_file, line);
        std::istringstream(line) >> number_of_elements;
        if (number_of_elements > 0) {
            // Read specified amount of lines from file and save them to memory
            filelines = new std::string[number_of_elements];
            for (int i = 0; i < number_of_elements; i++) {
                if (std::getline(input_file, line)) {
                    filelines[i] = line;
                }
            }
        }
    }
    input_file.close();
    FileReaderResult result;
    result.number_of_elements = number_of_elements;
    result.filelines = filelines;
    return result;
};