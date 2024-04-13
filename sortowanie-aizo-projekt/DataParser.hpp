#ifndef DATAPARSER_H
#define DATAPARSER_H
#include <iostream>
#include <fstream>
#include "FileReaderResult.hpp"

class DataParser {
public:
    static int* parse_int(FileReaderResult result);
    static float* parse_float(FileReaderResult result);
};

#endif