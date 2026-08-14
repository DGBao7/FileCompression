#include <vector>
#include <cstdint>

std::vector<int> BuildFrequencyTable(const std::vector<uint8_t> data) 
{
    std::vector<int> table(256 , 0);

    for (int i = 0; i < data.size(); i ++) 
    {
        table[static_cast<int>(data[i])] += 1;
    }

    return table;
}