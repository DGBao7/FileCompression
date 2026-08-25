#include "Huffman.h"
#include "Node.h"
#include <vector>
#include <cstdint>
#include <string>
#include <map>
#include <iostream>
#include "AnalyzeResult.h"

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

Node* CreateNodeTree(std::vector<int> table) 
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

void GenerateCode(Node* tree , std::string code , std::map<uint8_t , std::string>& tableHuffman) 
{
    if (tree == nullptr)
    {
        return;
    }

    if (tree -> left == nullptr && tree -> right == nullptr) 
    {
        tableHuffman[tree -> byte] = code;
    }

    GenerateCode(tree -> left , code + "0" , tableHuffman);
    GenerateCode(tree -> right , code + "1" , tableHuffman);
}

Node* RebuildTree(Ar res)
{
    Node* tree = new Node{0 , 0 , nullptr , nullptr};

    for (int i = 0; i < res.table_size; i++)
    {
        Node* current = tree;

        for (char bit : res.data_table[i])
        {
            if (bit == '0')
            {
                if (current->left == nullptr)
                {
                    current->left = new Node{0 , 0 , nullptr , nullptr};
                }

                current = current->left;
            }
            else if (bit == '1')
            {
                if (current->right == nullptr)
                {
                    current->right = new Node{0 , 0 , nullptr , nullptr};
                }

                current = current->right;
            }
        }

        current->byte = static_cast<uint8_t>(res.table_char[i]);
    }

    return tree;
}