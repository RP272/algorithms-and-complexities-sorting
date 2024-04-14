#include "ActionDataBundler.hpp"
#include <string>
#include "FileReader.hpp"
#include "FileReaderResult.hpp"
#include "DataParser.hpp"
#include "SortingSetup.hpp"

void ActionDataBundler::bundle(DataType datatype, ActionType actiontype) {
    if (actiontype == AT_READ) {
        std::string filename;
        std::cout << "Podaj nazwe pliku, z ktorego chcesz zaczytac dane: ";
        std::cin >> filename;
        FileReaderResult result = FileReader::read(filename);
        if (result.filelines == nullptr) {
            std::cout << "Nie znaleziono pliku o podanej nazwie" << std::endl;
            return;
        }
        switch (datatype)
        {
            case DT_INTEGER:
            {
                int* parsed_integers = DataParser<int>::parse(result);
                SortingSetup<int>* sorting_setup = new SortingSetup<int>(parsed_integers, result.number_of_elements);
                sorting_setup->show_menu();
                break;
            }
            case DT_FLOAT:
            {
                float* parsed_floats = DataParser<float>::parse(result);
                SortingSetup<float>* sorting_setup = new SortingSetup<float>(parsed_floats, result.number_of_elements);
                sorting_setup->show_menu();
                break;
            }
            case DT_CHAR:
            {
                char* parsed_chars = DataParser<char>::parse(result);
                SortingSetup<char>* sorting_setup = new SortingSetup<char>(parsed_chars, result.number_of_elements);
                sorting_setup->show_menu();
                break;
            }
        }
    }
    else if (actiontype == AT_GENERATE) {

    }
}