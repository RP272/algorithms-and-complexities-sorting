#include "ActionDataBundler.hpp"
#include <string>
#include "FileReader.hpp"
#include "FileReaderResult.hpp"
#include "DataParser.hpp"
#include "SortingSetup.hpp"
#include "DataGenerator.hpp"

void ActionDataBundler::bundle(DataType datatype, ActionType actiontype) {
    FileReaderResult result;
    int tab_size = 0;
    int number_of_elements = 0;
    if (actiontype == AT_READ) {
        std::string filename;
        std::cout << "Podaj nazwe pliku, z ktorego chcesz zaczytac dane: ";
        std::cin >> filename;
        result = FileReader::read(filename);
        number_of_elements = result.number_of_elements;
        if (result.filelines == nullptr) {
            std::cout << "Nie znaleziono pliku o podanej nazwie" << std::endl;
            return;
        }
    }
    else if (actiontype == AT_GENERATE) {
        std::cout << "Podaj rozmiar tablicy do wygenerowania: ";
        std::cin >> tab_size;
        number_of_elements = tab_size;
    }

    switch (datatype)
    {
    case DT_INTEGER:
    {
        int* integers = nullptr;
        if (actiontype == AT_READ) integers = DataParser<int>::parse(result);
        else if (actiontype == AT_GENERATE) integers = DataGenerator::generate_integers(tab_size);
        SortingSetup<int>* sorting_setup = new SortingSetup<int>(integers, number_of_elements);
        sorting_setup->show_menu();
        break;
    }
    case DT_FLOAT:
    {
        float* floats = nullptr;
        if (actiontype == AT_READ) floats = DataParser<float>::parse(result);
        else if (actiontype == AT_GENERATE) floats = DataGenerator::generate_floats(tab_size);
        SortingSetup<float>* sorting_setup = new SortingSetup<float>(floats, number_of_elements);
        sorting_setup->show_menu();
        break;
    }
    case DT_CHAR:
    {
        char* chars = nullptr;
        if (actiontype == AT_READ) chars = DataParser<char>::parse(result);
        else if (actiontype == AT_GENERATE) chars = DataGenerator::generate_chars(tab_size);
        SortingSetup<char>* sorting_setup = new SortingSetup<char>(chars, number_of_elements);
        sorting_setup->show_menu();
        break;
    }
    }
}