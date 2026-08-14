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
#include "Huffman/Node.h"
#include "Huffman/Huffman.h"
#include "IO/FileWritter.h"
#include "Utils/BitCalculating.h"
#include "UI/UI.h"
#include "IO/ReadEncodeFile.h"
#include "Utils/BitModify.h"

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
    std::map<uint8_t , std::string> tableHuffman;

    GenerateCode(tree , code , tableHuffman);

    // std::cout << "\n";

    // for (auto pair : tableHuffman)
    // {
    //     std::cout
    //         << static_cast<int>(pair.first)
    //         << " : "
    //         << pair.second
    //         << std::endl;
    // }

    std::string bitline = BitLining(data , tableHuffman);

    // std::cout << "\n" << bitline;

    std::vector<std::string> tableBit = BitSplitting(bitline , condition);
    std::string pad = tableBit[tableBit.size() - 1];
    tableBit.pop_back();

    std::cout << "\n";

    for (size_t i = 0; i < tableBit.size(); i ++)
    {
        std::cout << tableBit[i] << "\n";
    }

    std::vector<int> tableDec = BitToDecimal(tableBit);

    // std::cout << "\n";

    // for (size_t i = 0; i < tableDec.size(); i ++) 
    // {
    //     std::cout << tableDec[i] << "\n";
    // }

    std::vector<uint8_t> tableUint8_t = DecimalToBinary(tableDec);

    writing = false;
    std::cout << "\n";
    std::cout << "Input size = " << data.size() << " bytes\n";
    std::cout << "Output size = " << tableUint8_t.size() << " bytes\n";

    WriteCompressFile("Data/output.bin" , tableUint8_t , pad);
}

void Expression()
{
    bool condition = false;

    std::vector<uint8_t> tableUint8_t = ReadEncodeFile("Data/output.bin");

    // Remove pad number
    int pad = tableUint8_t[tableUint8_t.size() - 1];
    tableUint8_t.pop_back();

    std::cout << "\n";
    for (size_t i = 0; i < tableUint8_t.size(); i ++)
    {
        std::cout << static_cast<int>(tableUint8_t[i]) << " ";
    }

    std::cout << "\n";
    std::string bitline = DecimalToBit(tableUint8_t);
    std::cout << bitline;

    std::cout << "\n";
    std::vector<std::string> tableBit = BitSplitting(bitline , condition);
    for (size_t i = 0; i < tableBit.size(); i ++)
    {
        std::cout << tableBit[i] << "\n";
    }

    std::cout << "\n";
    tableBit[tableBit.size() - 1] = RemovePad(tableBit[tableBit.size() - 1] , pad);
    for (size_t i = 0; i < tableBit.size(); i ++)
    {
        std::cout << tableBit[i] << "\n";
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

    int mh;
    std::cin >> mh;

    if (mh == 1)
    {
        Compression();
    }
    else 
    {
        Expression();
    }
}