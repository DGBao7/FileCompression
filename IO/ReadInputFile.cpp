#include "ReadInputFile.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstdint>

std::vector<uint8_t> ReadBinaryFile(const std::string& path)
{
    std::ifstream file(path , std::ios::binary);

    if (!file)
    {
        return {};
    }

    file.seekg(0 , std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0 , std::ios::beg);

    std::vector<uint8_t> data(size);

    if (size > 0)
    {
        file.read(reinterpret_cast<char*>(data.data()) , size);
    }

    return data;
}