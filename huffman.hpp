#ifndef HUFFMAN
#define HUFFMAN
#include "priority_queue.hpp"
#include "bitset.hpp"
#include <stdio.h>
class huffman
{
public:
    huffman();
    ~huffman();
    void add_symbol(char sym);
    tree_node* build_tree();
    static void free_tree(tree_node* root);
    static bitset get_code(tree_node* root, char sym);
private:
    static void find_node(tree_node* root, char sym, tree_node** res);
    void set_parent_nodes(tree_node* root);
    priority_queue pq;
};
#endif