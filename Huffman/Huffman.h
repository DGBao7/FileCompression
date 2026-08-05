#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Node.h"
#include <vector>

extern std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
Node* CreateTree(std::vector<int> table);

#endif