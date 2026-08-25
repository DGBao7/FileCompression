#include "AnalyzeData.h"
#include <map>
#include <vector>
#include <cstdint>
#include "AnalyzeResult.h"
#include <iostream>

Ar AnalyzeData(std::vector<uint8_t> data)
{
    Ar res;

    res.table_size = static_cast<int>(data[0]);

    data.erase(data.begin());

    for (int i = 0; i < res.table_size; i ++)
    {
        res.table_char.push_back(static_cast<char>(data[0]));
        data.erase(data.begin());

        int counter = static_cast<int>(data[0]);
        data.erase(data.begin());

        res.data_table.push_back(
            std::vector<char>(
                data.begin() ,
                data.begin() + counter
            )
        );

        data.erase(
            data.begin() ,
            data.begin() + counter
        );
    }

    for (size_t i = 0; i < data.size(); i ++)
    {
        res.compressed_bytes.push_back(data[i]);
    }

    return res;
}