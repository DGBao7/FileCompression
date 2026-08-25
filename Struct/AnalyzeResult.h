#ifndef ANALYZERESULT_H
#define ANALYZERESULT_H
#include <vector>
#include <cstdint>


typedef struct AnalyzeResult
{
    int table_size;
    std::vector<char> table_char;
    std::vector<std::vector<char>> data_table;
    std::vector<uint8_t> compressed_bytes;
} Ar;

#endif