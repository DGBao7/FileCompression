#ifndef BITMODIFY_H
#define BITMODIFY_H
#include <string>
#include <vector>
#include <cstdint>
#include <map>

std::string BitLining(std::vector<uint8_t> data , std::map<uint8_t , std::string> tableHuffman);

std::vector<std::string> BitSplitting(std::string bitline , bool option);

std::vector<int> BitToDecimal(std::vector<std::string> tableBit);

std::string RemovePad(std::string line , int pad);

#endif