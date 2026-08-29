#ifndef DATA_H
#define DATA_H
#include <cstdint>
#include <vector>
#include <string>

typedef struct FileChopping
{
    std::vector<uint8_t> input;
    std::string file_name;
    std::string extension;
} Fc;

#endif