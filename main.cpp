#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <atomic>
#include <thread>

#include "IO/FileReader.h"
#include "Data/FrequencyTable.h"
#include "Huffman/Node.h"
#include "Huffman/Huffman.h"
#include "IO/FileWritter.h"
#include "Utils/BinaryToDecimal.h"
#include "UI/Waiting.h"

void Confirm() 
{
    getchar();
    getchar();
}

int main() 
{
    std::atomic<bool> writing = true;

    std::thread loading(Loading , std::ref(writing));

    std::vector<uint8_t> data = ReadBinaryFile("Data/input.txt");

    // for (int i = 0; i < data.size(); i ++) {
    //     std::cout << static_cast<int>(data[i]) << " ";
    // }

    // std:: cout << "\n";

    std::vector<int> table = BuildTable(data);
    
    // for (int i = 0; i < 256; i ++) 
    // {
    //     if (table[i] != 0)
    //     {
    //         std::cout << i << " " << table[i] << "\n";
    //     }
    // }

    // std::cout << "\n";

    Node* tree = CreateTree(table);

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

    std::vector<std::string> tableBit = BitSplitting(bitline);

    // std::cout << "\n";

    // for (size_t i = 0; i < tableBit.size(); i ++)
    // {
    //     std::cout << tableBit[i] << "\n";
    // }

    std::vector<int> tableDec = BitToDec(tableBit);

    // std::cout << "\n";

    // for (size_t i = 0; i < tableDec.size(); i ++) 
    // {
    //     std::cout << tableDec[i] << "\n";
    // }

    std::vector<uint8_t> tableUint8_t = DecToBit(tableDec);

    writing = false;
    std::cout << "\n";
    std::cout << "Input size = " << data.size() << " bytes\n";
    std::cout << "Output size = " << tableUint8_t.size() << " bytes\n";

    WriteBitFile("Data/output.bin" , tableUint8_t);

    Confirm();
}