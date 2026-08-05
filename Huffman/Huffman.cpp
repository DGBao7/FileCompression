#include "Huffman.h"
#include "Node.h"
#include <vector>
#include <cstdint>

std::vector<Node*> CreateNode(std::vector<int> table) 
{
    std::vector<Node*> node;

    for (size_t i = 0; i < table.size(); i ++) 
    {
        if (table[i] != 0) {
            node.push_back(new Node{static_cast<uint8_t>(i) , table[i] , nullptr , nullptr});
        }
    }

    return node;
}

std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

Node* CreateTree(std::vector<int> table) 
{
    std::vector<Node*> node = CreateNode(table);

    for (size_t i = 0; i < table.size(); i ++) 
    {
        if (table[i] == 0) {
            continue;
        }

        pq.push(new Node{
            static_cast<uint8_t>(i),
            table[i],
            nullptr,
            nullptr
        });
    }

    while (pq.size() > 1) 
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node{
            0,
            left->frequency + right->frequency,
            left,
            right
        };

        pq.push(parent);
    }

    return pq.top();
}