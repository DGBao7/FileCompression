#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>
#include <cstdint>

std::vector<uint8_t> ReadBinaryFile(const std::string& path);

#endif