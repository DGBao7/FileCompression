#ifndef NODE_H
#define NODE_H
#include <cstdint>
#include <queue>

struct Node
{
    uint8_t byte;
    int frequency;

    Node* left;
    Node* right;
};

struct Compare
{
    bool operator()(Node* a , Node* b) 
    {
        return a->frequency > b->frequency;
    }
};

#endif