#include "FileWritter.h"
#include <string>
#include <map>
#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>

void WriteCompressFile(
    const std::string& path ,
    std::vector<uint8_t> tableUint8_t ,
    std::string pad ,
    std::map<uint8_t , std::string> tableHuffman
)
{
    std::ofstream file(path , std::ios::binary);

    uint8_t tableSize = tableHuffman.size();

    file.write(
        reinterpret_cast<char*>(&tableSize),
        sizeof(tableSize)
    );

    for (const auto& [byte , code] : tableHuffman)
    {
        uint8_t codeLength = code.size();

        file.write(
            reinterpret_cast<const char*>(&byte),
            sizeof(byte)
        );

        file.write(
            reinterpret_cast<char*>(&codeLength),
            sizeof(codeLength)
        );

        file.write(
            code.data(),
            codeLength
        );
    }

    file.write(
        reinterpret_cast<char*>(tableUint8_t.data()),
        tableUint8_t.size()
    );

    uint8_t padding = static_cast<uint8_t>(std::stoi(pad));

    file.write(
        reinterpret_cast<char*>(&padding),
        sizeof(padding)
    );

    std::cout << "\nWritting Successfully\n";

    file.close();
}

void WriteDecompressedFile(
    const std::string& path ,
    std::string decompressed_data
)
{
    std::ofstream file(path , std::ios::binary);

    file << decompressed_data;

    std::cout << "\nDecompress Successfully\n";

    file.close();
}