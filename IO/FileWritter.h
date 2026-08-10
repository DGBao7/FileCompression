#ifndef FILEWRITTER_H
#define FILEWRITTER_H
#include <string>
#include <cstdint>
#include <map>
#include <vector>

std::string BitLining(std::map<uint8_t , std::string> tableHuffman);

std::vector<std::string> BitSplitting(std::string bitline);

std::vector<int> BitToDec(std::vector<std::string> tableBit);

#endif