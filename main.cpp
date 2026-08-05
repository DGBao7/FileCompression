#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>

#include "IO/FileReader.h"
#include "Data/FrequencyTable.h"
#include "Huffman/Node.h"
#include "Huffman/Huffman.h"

void Confirm() 
{
    getchar();
    getchar();
}

int main() 
{
    std::vector<uint8_t> data = ReadBinaryFile("Data/input.txt");

    for (int i = 0; i < data.size(); i ++) {
        std::cout << static_cast<int>(data[i]) << " ";
    }

    std:: cout << "\n";

    std::vector<int> table = BuildTable(data);
    
    for (int i = 0; i < 256; i ++) 
    {
        if (table[i] != 0)
        {
            std::cout << i << " " << table[i] << "\n";
        }
    }

    std::cout << "\n";

    Node* tree = CreateTree(table);

    std::cout << tree -> frequency;

    Confirm();
}