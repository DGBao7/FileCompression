#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <atomic>
#include <thread>
#include <bitset>

#include "IO/ReadInputFile.h"
#include "Data/FrequencyTable.h"
#include "Node.h"
#include "Huffman/Huffman.h"
#include "IO/FileWritter.h"
#include "Utils/BitCalculating.h"
#include "UI/UI.h"
#include "IO/ReadEncodeFile.h"
#include "Utils/BitModify.h"
#include "Utils/AnalyzeData.h"
#include "AnalyzeResult.h"

void Confirm() 
{
    getchar();
    getchar();
}

void Compression()
{
    bool condition = true;

    std::atomic<bool> writing = true;

    std::thread loading(Writting , std::ref(writing));

    std::vector<uint8_t> data = ReadBinaryFile("Data/input.txt");

    // for (int i = 0; i < data.size(); i ++) {
    //     std::cout << static_cast<int>(data[i]) << " ";
    // }

    // std:: cout << "\n";

    std::vector<int> table = BuildFrequencyTable(data);
    
    // for (int i = 0; i < 256; i ++) 
    // {
    //     if (table[i] != 0)
    //     {
    //         std::cout << i << " " << table[i] << "\n";
    //     }
    // }

    // std::cout << "\n";

    Node* tree = CreateNodeTree(table);

    // std::cout << tree -> frequency;

    std::string code = "";
    std::map<uint8_t , std::string> table_huffman;

    GenerateCode(tree , code , table_huffman);

    // std::cout << "\n";

    // for (auto pair : table_huffman)
    // {
    //     std::cout
    //         << static_cast<int>(pair.first)
    //         << " : "
    //         << pair.second
    //         << std::endl;
    // }

    std::string bitline = BitLining(data , table_huffman);

    // std::cout << "\n" << bitline;

    std::vector<std::string> table_bit = BitSplitting(bitline , condition);
    std::string pad = table_bit[table_bit.size() - 1];
    table_bit.pop_back();

    std::cout << "\n";

    // for (size_t i = 0; i < table_bit.size(); i ++)
    // {
    //     std::cout << table_bit[i] << "\n";
    // }

    std::vector<int> table_dec = BitToDecimal(table_bit);

    // std::cout << "\n";

    // for (size_t i = 0; i < table_dec.size(); i ++) 
    // {
    //     std::cout << table_dec[i] << "\n";
    // }

    std::vector<uint8_t> table_uint8t = DecimalToBinary(table_dec);

    writing = false;
    std::cout << "\n";
    std::cout << "Input size = " << data.size() << " bytes\n";
    std::cout << "Output size = " << table_uint8t.size() << " bytes\n";

    WriteCompressFile("Data/output.bin" , table_uint8t , pad , table_huffman);
}

void Expression()
{
    bool condition = false;

    std::vector<uint8_t> data = ReadEncodeFile("Data/output.bin");

    // Remove pad number
    // int pad = table_uint8t[table_uint8t.size() - 1];
    // table_uint8t.pop_back();

    // std::cout << "\n";
    // for (size_t i = 0; i < table_uint8t.size(); i ++)
    // {
    //     std::cout << static_cast<int>(table_uint8t[i]) << " ";
    // }

    // std::cout << "\n";
    // std::string bitline = DecimalToBit(table_uint8t);
    // std::cout << bitline;

    // std::cout << "\n";
    // std::vector<std::string> table_bit = BitSplitting(bitline , condition);
    // for (size_t i = 0; i < table_bit.size(); i ++)
    // {
    //     std::cout << tableBit[i] << "\n";
    // }

    // std::cout << "\n";
    // tableBit[tableBit.size() - 1] = RemovePad(tableBit[tableBit.size() - 1] , pad);
    // for (size_t i = 0; i < tableBit.size(); i ++)
    // {
    //     std::cout << tableBit[i] << "\n";
    // }

    for (size_t i = 0; i < data.size(); i ++)
    {
        std::cout << static_cast<int>(data[i]) << " ";
    }

    Ar res = AnalyzeData(data);
    std::cout <<  "\n";
    for (size_t i = 0; i < res.data_table.size(); i ++)
    {
        std::cout << "\n";
        for (size_t j = 0; j < res.data_table[i].size(); j ++)
        {
            std::cout << static_cast<int>(res.data_table[i][j]) << " ";
        }
    }

    std::cout << "\n" << res.table_size;
    
    std::cout << "\n";
    for (size_t i = 0; i < res.table_char.size(); i ++)
    {
        std::cout << res.table_char[i] << " ";
    }

    Confirm();
}

int main()
{
    // // if (OptionSelect() == 1)
    // // {   
    // //     Compression();
    // // }
    // // else
    // // {
    // //     Expression();
    // // }

    int mh = 2;
    // std::cin >> mh;

    if (mh == 1)
    {
        Compression();
    }
    else 
    {
        Expression();
    }
}