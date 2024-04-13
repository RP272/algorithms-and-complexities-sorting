#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>
#include "FileReaderResult.hpp"

class FileReader {
public:
    static FileReaderResult read(const std::string& filename);
};

#endif