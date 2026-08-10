#include "BinaryToDecimal.h"
#include <vector>
#include <string>
#include <iostream>

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