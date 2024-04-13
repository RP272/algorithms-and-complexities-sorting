#include <iostream>
#include "FileReader.hpp"
#include "FileReaderResult.hpp"

int main()
{
    std::cout << "Hello World" << std::endl;
    std::string filename;
    std::cin >> filename;
    FileReaderResult result = FileReader::read(filename);
    std::cout << "After reading" << std::endl;
    for (int i = 0; i < result.number_of_elements; i++) {
        std::cout << *(result.filelines + i) << std::endl;
    }
    std::cout << "Press enter to continue";
    std::cin.ignore();
    std::cin.get();
}