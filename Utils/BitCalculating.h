#ifndef BITCALCULATING_H
#define BITCALCULATING_H
#include <vector>
#include <string>
#include <cstdint>
#include <bitset>

std::vector<int> BitToDecimal(std::vector<std::string> tableBit);

std::vector<uint8_t> DecimalToBinary(std::vector<int> tableDec);

std::string DecimalToBit(std::vector<uint8_t> tableUint8_t);

#endif 