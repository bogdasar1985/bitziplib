#ifdef HUFFMAN
#include "huffman.hpp"
huffman::huffman() = default;

huffman::~huffman() = default;

void huffman::add_symbol(char sym)
{
    _huff_tree.add(symbol(sym));
}

void huffman::build_tree()
{
    while(_huff_tree.size() != 1)
    {
        tree_node *node1 = new tree_node; 
        *node1 = _huff_tree.extract_min();
        tree_node *node2 = new tree_node;
        *node2 = _huff_tree.extract_min();
        tree_node *res_node = new tree_node;
        res_node->count = node1->count + node2->count;
        if(node1->count <= node2->count)
        {
            res_node->left = node1;
            res_node->right = node2;
        }
        else
        {
            res_node->left = node2;
            res_node->right = node1;
        }
        _huff_tree.add(*res_node);
    }
}
#endif