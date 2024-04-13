#include <iostream>,
#include "FileReader.hpp"
#include "FileReaderResult.hpp"
#include "DataParser.hpp"
#include "DataTypePicker.hpp"

int main()
{
    DataType datatype = DataTypePicker::pick();
    
    /*std::string filename;
    std::cin >> filename;
    FileReaderResult result = FileReader::read(filename);
    std::cout << "After reading" << std::endl;
    for (int i = 0; i < result.number_of_elements; i++) {
        std::cout << result.filelines[i] << std::endl;
    }
    std::cout << "After parsing" << std::endl;
    char* parsed_data = DataParser<char>::parse(result);
    if (parsed_data != nullptr) {
        for (int j = 0; j < result.number_of_elements; j++) {
            std::cout << parsed_data[j] << std::endl;
        }
    }
    std::cout << "Press enter to continue";
    std::cin.ignore();
    std::cin.get();*/
}