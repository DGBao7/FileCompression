#ifndef FILEWRITTER_H
#define FILEWRITTER_H
#include <string>
#include <cstdint>
#include <map>
#include <vector>

std::string BitLining(std::vector<uint8_t> data , std::map<uint8_t , std::string> tableHuffman);

std::vector<std::string> BitSplitting(std::string bitline);

std::vector<int> BitToDec(std::vector<std::string> tableBit);

void WriteBitFile(const std::string& path , std::vector<uint8_t> tableUint8_t);

#endif