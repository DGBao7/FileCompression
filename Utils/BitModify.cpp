#include "BitModify.h"
#include "Node.h"
#include <iostream>

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

std::vector<char> RemovePad(std::vector<char> line , int pad)
{  
    if (pad == 0)
    {
        return line;
    }
    else
    {
        for (int i = 0; i < pad; i ++)
        {
            line.pop_back();
            // line.insert(line.begin() , '0');
        }
    }

    return line;
}

std::vector<std::vector<char>> StaticCastChar(std::vector<uint8_t> compressed_data)
{
    std::vector<std::vector<char>> compressed_bytes;
    compressed_data.pop_back();

    for (size_t i = 0; i < compressed_data.size(); i ++)
    {
        compressed_bytes.push_back({});
        int decima = static_cast<int>(compressed_data[i]);

        while (decima > 0)
        {
            char decimai = static_cast<char>(decima % 2 + 48);
            decima /= 2;
            compressed_bytes[i].insert(compressed_bytes[i].begin() , decimai);
        }

        while (compressed_bytes[i].size() < 8)
        {
            compressed_bytes[i].insert(compressed_bytes[i].begin() , '0');
        }
    }

    return compressed_bytes;
}

std::string DecodeCompressData(std::vector<std::vector<char>> data_table , Node* tree)
{
    std::string output = "";
    Node* searching = tree;

    for (size_t i = 0; i < data_table.size(); i ++)
    {
        for (size_t j = 0; j < data_table[i].size(); j ++)
        {
            if (data_table[i][j] == '0')
            {
                searching = searching -> left;
            }
            else 
            {
                searching = searching -> right;
            }

            if (searching -> left == nullptr && searching -> right == nullptr)
            {
                output += static_cast<char>(searching -> byte);
                searching = tree;
            }
        }
    }

    return output;
}