#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Node.h"
#include <vector>
#include <map>
#include <string>
#include <cstdint>

extern std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

Node* CreateTree(std::vector<int> table);

void GenerateCode(Node* tree , std::string code , std::map<uint8_t , std::string>& tableHuffman);

#endif