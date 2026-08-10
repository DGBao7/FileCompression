#include "BinaryToDecimal.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdint>

std::vector<int> BitToDec(std::vector<std::string> tableBit)
{
    std::vector<int> tableDec;

    for (size_t i = 0; i < tableBit.size(); i ++) 
    {
        int value = std::stoi(tableBit[i] , nullptr , 2);
        tableDec.push_back(value);
    }

    return tableDec;
}

std::vector<uint8_t> DecToBit(std::vector<int> tableDec) 
{
    std::vector<uint8_t> tableUint8_t;

    for (size_t i = 0; i < tableDec.size(); i ++) 
    {
        tableUint8_t.push_back(static_cast<uint8_t>(tableDec[i]));
    }
    
    return tableUint8_t;
}