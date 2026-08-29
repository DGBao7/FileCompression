#ifndef ANALYZEPATH_H
#define ANALYZEPATH_H
#include <vector>
#include <string>

std::vector<std::string> Choppath(const std::string& path);

std::string RewritePath(std::vector<std::string> part_path);

std::vector<std::string> ChopName(std::string file);

#endif