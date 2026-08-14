#include "FileWritter.h"
#include <string>
#include <map>
#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>

void WriteCompressFile(const std::string& path , std::vector<uint8_t> tableUint8_t , std::string pad)
{
    tableUint8_t.push_back(static_cast<uint8_t>(std::stoi(pad)));

    std::ofstream file(path , std::ios::binary);

    file.write(reinterpret_cast<char*>(tableUint8_t.data()) , tableUint8_t.size());

    std::cout << "\n" <<
                "Writting Successfully" <<
                "\n"; 

    file.close();
}