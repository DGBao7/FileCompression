#ifndef FILEWRITTER_H
#define FILEWRITTER_H
#include <string>
#include <cstdint>
#include <map>
#include <vector>

void WriteCompressFile(
    const std::string& path , 
    std::vector<uint8_t> tableUint8_t , 
    std::string pad ,
    std::map<uint8_t , std::string> tableHufman
);

#endif