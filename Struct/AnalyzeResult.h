#ifndef ANALYZERESULT_H
#define ANALYZERESULT_H
#include <vector>
#include <cstdint>


typedef struct AnalyzeResult
{
    int table_size;
    std::vector<char> table_char;
    std::vector<std::vector<uint8_t>> data_table;
} Ar;

#endif