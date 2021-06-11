#ifndef HUFFMAN
#define HUFFMAN
#include "priority_queue.hpp"
#include "tree_node.hpp"
#include <stdio.h>
class huffman
{
public:
    huffman();
    ~huffman();
    void add_symbol(char sym);
    void build_tree();
private:
    void _print(tree_node *node);
    priority_queue _huff_tree;
};
#include "huffman.cpp"
#endif