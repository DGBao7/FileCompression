#include "BitModify.h"

std::string BitLining(std::vector<uint8_t> data , std::map<uint8_t , std::string> tableHuffman)
{
    std::string bitline = "";

    for (size_t i = 0; i < data.size(); i ++)
    {
        bitline += tableHuffman[data[i]];
    }

    return bitline;
};

std::vector<std::string> BitSplitting(std::string bitline , bool option) 
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

    if (option)
    {
        std::string pad = std::to_string(8 - line.size());

        if (line.size() > 0) 
        {
            while (line.size() < 8)
            {
                line += "0";
            }
            
            tableBit.push_back(line);
        }

        tableBit.push_back(pad);

        return tableBit;
    }

    if (line.size() > 0)
    {
        tableBit.push_back(line);
    }    

    return tableBit;
}

std::string RemovePad(std::string line , int pad)
{
    std::vector<char> nuclear;

    for (size_t i = 0; i < line.size(); i ++)
    {
        nuclear.push_back(line[i]);
    }

    while (nuclear.size() > line.size() - pad)
    {
        nuclear.pop_back();
    }

    line = "";
    for (size_t i = 0; i < nuclear.size(); i ++)
    {
        line += nuclear[i];
    }

    return line;
}