#ifndef TREE_NODE
#define TREE_NODE
#include "symbol.hpp"
#include <cstddef>
struct tree_node : public symbol
{
    tree_node() : symbol(), parent(NULL), left(NULL), right(NULL) {};
    tree_node(char _sym) : symbol(_sym), parent(NULL), left(NULL), right(NULL) {};
    tree_node(char _sym, size_t size) : symbol(_sym, size), parent(NULL), left(NULL), right(NULL) {};
    tree_node* parent;
    tree_node* left;
    tree_node* right;
};
#endif
