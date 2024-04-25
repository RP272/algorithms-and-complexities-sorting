#include "ActionDataBundler.hpp"
#include <string>
#include "FileReader.hpp"
#include "FileReaderResult.hpp"
#include "DataParser.hpp"
#include "SortingSetup.hpp"
#include "DataGenerator.hpp"
#include "GeneratedDataPartialSorter.hpp"

void ActionDataBundler::bundle(DataType datatype, ActionType actiontype) {
    /*
    This function is responsible for managing the action combined with datatype picked by user.
    */
    FileReaderResult result;
    PartialSort partial_sort;
    int tab_size = 0;
    int number_of_elements = 0;
    if (actiontype == AT_READ) {
        /*
        If reading from file was picked, user is prompted for filename.
        If the file exists, data from it is read and saved as a result.
        Otherwise correct output is presented to the user.
        */
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
        /*
        If data generation was picked as an action, user is prompted for array size.
        */
        std::cout << "Podaj rozmiar tablicy do wygenerowania: ";
        std::cin >> tab_size;
        number_of_elements = tab_size;
    }
    else if (actiontype == AT_BENCHMARK_TEST) {
        /*
        This part of the code is responsible for benchmark tests.
        It runs specified sorting algorithm 100 times on different data, and outputs the average time in miliseconds
        needed to sort the array.
        The calculations are made for sizes specified in the array_sizes tab.
        */
        int* array_sizes = new int[7] {15000, 30000, 50000, 100000, 200000, 500000, 1000000};
        switch (datatype) {
            case DT_INTEGER: {
                GeneratedDataPartialSorter<int>* gdps = new GeneratedDataPartialSorter<int>();
                SortingSetup<int>* sorting_setup = new SortingSetup<int>();
                sorting_setup->show_menu();
                int* integers = nullptr;
                int sum_of_sorting_times;
                int array_size;
                int sorting_time;
                for (int i = 0; i < 7; i++) {
                    array_size = array_sizes[i];
                    sum_of_sorting_times = 0;
                    for (int j = 0; j < 100; j++) {
                        integers = DataGenerator::generate_integers(array_size);
                        integers = gdps->sort(integers, array_size);
                        sorting_time = sorting_setup->run(integers, array_size, false);
                        std::cout << j + 1 << " :: " << sorting_time << " ms" << std::endl;
                        sum_of_sorting_times += sorting_time;
                        delete integers;
                    }
                    sum_of_sorting_times /= 100;

                    std::cout << "Array size: " << array_size << ". Average sorting time: " << sum_of_sorting_times << "ms" << std::endl;
                }
                break;
            }
            case DT_FLOAT: {
                GeneratedDataPartialSorter<float>* gdps = new GeneratedDataPartialSorter<float>();
                SortingSetup<float>* sorting_setup = new SortingSetup<float>();
                sorting_setup->show_menu();
                float* floats = nullptr;
                int sum_of_sorting_times;
                int array_size;
                int sorting_time;
                for (int i = 0; i < 7; i++) {
                    array_size = array_sizes[i];
                    sum_of_sorting_times = 0;
                    for (int j = 0; j < 100; j++) {
                        floats = DataGenerator::generate_floats(array_size);
                        floats = gdps->sort(floats, array_size);
                        sorting_time = sorting_setup->run(floats, array_size, false);
                        std::cout << j + 1 << " :: " << sorting_time << " ms" << std::endl;
                        sum_of_sorting_times += sorting_time;
                        delete floats;
                    }
                    sum_of_sorting_times /= 100;

                    std::cout << "Array size: " << array_size << ". Average sorting time: " << sum_of_sorting_times << "ms" << std::endl;
                }
                break;
            }
            case DT_CHAR: {
                GeneratedDataPartialSorter<char>* gdps = new GeneratedDataPartialSorter<char>();
                SortingSetup<char>* sorting_setup = new SortingSetup<char>();
                sorting_setup->show_menu();
                char* chars = nullptr;
                int sum_of_sorting_times;
                int array_size;
                int sorting_time;
                for (int i = 0; i < 7; i++) {
                    array_size = array_sizes[i];
                    sum_of_sorting_times = 0;
                    for (int j = 0; j < 100; j++) {
                        chars = DataGenerator::generate_chars(array_size);
                        chars = gdps->sort(chars, array_size);
                        sorting_time = sorting_setup->run(chars, array_size, false);
                        std::cout << j + 1 << " :: " << sorting_time << " ms" << std::endl;
                        sum_of_sorting_times += sorting_time;
                        delete chars;
                    }
                    sum_of_sorting_times /= 100;

                    std::cout << "Array size: " << array_size << ". Average sorting time: " << sum_of_sorting_times << "ms" << std::endl;
                }
                break;
            }
        }
        return;
    }

    switch (datatype)
    {
    case DT_INTEGER:
    {
        /*
        After the initial data setup was done, here comes the main one.
        Based on the type of action picked by the user, data array is created.
        After data has been generated it is then partially sorted acording to user's choice.
        After that data is passed to sorting setup, where user can pick different algorithms to test.
        */
        int* integers = nullptr;
        if (actiontype == AT_READ) integers = DataParser<int>::parse(result);
        else if (actiontype == AT_GENERATE) {
            integers = DataGenerator::generate_integers(tab_size);
            GeneratedDataPartialSorter<int>* generated_data_partial_sorter = new GeneratedDataPartialSorter<int>();
            integers = generated_data_partial_sorter->sort(integers, number_of_elements);
            delete generated_data_partial_sorter;
        }
        SortingSetup<int>* sorting_setup = new SortingSetup<int>();
        while (sorting_setup->show_menu()) {
            sorting_setup->run(integers, number_of_elements, true);
        }
        delete sorting_setup;
        break;
    }
    case DT_FLOAT:
    {

        /*
        After the initial data setup was done, here comes the main one.
        Based on the type of action picked by the user, data array is created.
        After data has been generated it is then partially sorted acording to user's choice.
        After that data is passed to sorting setup, where user can pick different algorithms to test.
        */
        float* floats = nullptr;
        if (actiontype == AT_READ) floats = DataParser<float>::parse(result);
        else if (actiontype == AT_GENERATE) {
            floats = DataGenerator::generate_floats(tab_size);
            GeneratedDataPartialSorter<float>* generated_data_partial_sorter = new GeneratedDataPartialSorter<float>();
            floats = generated_data_partial_sorter->sort(floats, number_of_elements);
            delete generated_data_partial_sorter;
        }
        SortingSetup<float>* sorting_setup = new SortingSetup<float>();
        while (sorting_setup->show_menu()) {
            sorting_setup->run(floats, number_of_elements, true);
        }
        delete sorting_setup;
        break;
    }
    case DT_CHAR:
    {
        /*
        After the initial data setup was done, here comes the main one.
        Based on the type of action picked by the user, integers array is created.
        After data has been generated it is then partially sorted acording to user's choice.
        After that data is passed to sorting setup, where user can pick different algorithms to test.
        */
        char* chars = nullptr;
        if (actiontype == AT_READ) chars = DataParser<char>::parse(result);
        else if (actiontype == AT_GENERATE) {
            chars = DataGenerator::generate_chars(tab_size);
            GeneratedDataPartialSorter<char>* generated_data_partial_sorter = new GeneratedDataPartialSorter<char>();
            chars = generated_data_partial_sorter->sort(chars, number_of_elements);
            delete generated_data_partial_sorter;
        }
        SortingSetup<char>* sorting_setup = new SortingSetup<char>();
        while (sorting_setup->show_menu()) {
            sorting_setup->run(chars, number_of_elements, true);
        }
        delete sorting_setup;
        break;
    }
    }
}