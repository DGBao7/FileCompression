#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <atomic>
#include <thread>
#include <bitset>
#include <filesystem>

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
#include "Utils/AnalyzePath.h"

void Confirm() 
{
    getchar();
    getchar();
}

void Compression(
    const std::string& file_path ,
    const std::string& path ,
    const std::string& file_name ,
    const std::string& file_extension
)
{
    bool condition = true;

    Writing();

    std::vector<uint8_t> data = ReadFile(path);

    std::cout << "\n";
    std::cout << "Input size = " << data.size() << " bytes\n";

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

    std::cout << "Output size = " << table_uint8t.size() << " bytes\n";
    // std::cout << pad << "\n";

    std::string loc_path = path + "\\" + file_name + ".bon";

    WriteCompressFile(loc_path , table_uint8t , pad , table_huffman);
}

void Expression(
    const std::string& file_path ,
    const std::string& path ,
    const std::string& file_name ,
    const std::string& file_extension
)
{
    bool condition = false;

    std::vector<uint8_t> data = ReadEncodeFile(path);

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

    // for (size_t i = 0; i < data.size(); i ++)
    // {
    //     std::cout << static_cast<int>(data[i]) << " ";
    // }

    Ar res = AnalyzeData(data);
    // std::cout <<  "\n";
    // for (size_t i = 0; i < res.data_table.size(); i ++)
    // {
    //     std::cout << "\n";
    //     for (size_t j = 0; j < res.data_table[i].size(); j ++)
    //     {
    //         std::cout << res.data_table[i][j] << " ";
    //     }
    // }

    // std::cout << "\n" << res.table_size;
    
    // std::cout << "\n";
    // for (size_t i = 0; i < res.table_char.size(); i ++)
    // {
    //     std::cout << res.table_char[i] << " ";
    // }

    Node* tree = RebuildTree(res);

    int pad = static_cast<int>(res.compressed_bytes[res.compressed_bytes.size() - 1]);

    std::vector<std::vector<char>> compressed_bytes = StaticCastChar(res.compressed_bytes);

    compressed_bytes[compressed_bytes.size() - 1] = RemovePad(compressed_bytes[compressed_bytes.size() - 1] , pad);

    // for (size_t i = 0; i < compressed_bytes.size(); i ++)
    // {
    //     std::cout << "\n";
    //     for (size_t j = 0; j < compressed_bytes[i].size(); j ++)
    //     {
    //         std::cout << compressed_bytes[i][j] << " ";
    //     }
    // }

    std::string decompressed_data = DecodeCompressData(compressed_bytes , tree);
    // std::cout << "\n" << decompressed_data;

    // std::cout << "\n";
    // std::cout << decompressed_data;

    std::string loc_path = path + "\\" + file_name + ".txt";

    WriteDecompressedFile("Data/output.txt" , decompressed_data);

    Confirm();
}

int main()
{
    std::string path = TakePath();
    // std::string path = "Data/input.txt";

    std::vector<std::string> part_path = Choppath(path);
    
    // std::cout << "\n";
    // for (int i = 0; i < part_path.size(); i ++)
    // {
    //     std::cout << part_path[i] << " ";
    // }

    std::vector<std::string> file = ChopName(part_path[part_path.size() - 1]);
    part_path.pop_back();
    
    std::string loc_path = RewritePath(part_path);

    std::string file_name = file[0];
    std::string file_extension = file[1];
    std::cout << "\n";
    std::cout << path;

    // std::cout << "\n";
    // std::cout << path;
    // std::cout << "\n";
    // std::cout << file_name;
    // std::cout << "\n";
    // std::cout << file_extension;
    // std::cout << "\n";
    // std::cout << loc_path;

    if (file_extension == ".bon")
    {
        Expression(
            path ,
            loc_path ,
            file_name ,
            file_extension
        );
    }
    else
    {
        Compression(
            path ,
            loc_path ,
            file_name ,
            file_extension
        );
    }
}