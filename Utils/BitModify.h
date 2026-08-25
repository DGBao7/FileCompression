#ifndef BITMODIFY_H
#define BITMODIFY_H
#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include "Node.h"

std::string BitLining(std::vector<uint8_t> data , std::map<uint8_t , std::string> tableHuffman);

std::vector<std::string> BitSplitting(std::string bitline , bool option);

std::vector<int> BitToDecimal(std::vector<std::string> tableBit);

std::vector<char> RemovePad(std::vector<char> line , int pad);

std::string DecodeCompressData(std::vector<std::vector<char>> data_table , Node* tree);

std::vector<std::vector<char>> StaticCastChar(std::vector<uint8_t> compressed_data);

#endif