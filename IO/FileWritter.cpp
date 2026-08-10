#include "FileWritter.h"
#include <string>
#include <map>
#include <cstdint>
#include <vector>
#include <iostream>

std::string BitLining(std::map<uint8_t , std::string> tableHuffman)
{
    std::string bitline = "";

    for (auto pair : tableHuffman) 
    {
        bitline += pair.second;
    }

    return bitline;
};

std::vector<std::string> BitSplitting(std::string bitline) 
{
    int counter = 0;
    std::string line = "";
    std::vector<std::string> tableBit;

    for (size_t i = 0; i < bitline.size(); i ++) 
    {
        if (counter < 8) 
        {
            counter ++;
            line += bitline[i];
            continue;
        }

        tableBit.push_back(line);
        line = bitline[i];
        counter = 1;
    }

    if (line.size() > 0) 
    {
        while (line.size() < 8)
        {
            line += "0";
        }
        
        tableBit.push_back(line);
    }

    return tableBit;
}