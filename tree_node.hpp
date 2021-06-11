#ifndef TREE_NODE
#define TREE_NODE
#include "symbol.hpp"
struct tree_node : public symbol
{
    tree_node() : symbol(), parent(NULL), left(NULL), right(NULL) {};
    tree_node(symbol sym) : symbol(sym), parent(NULL), left(NULL), right(NULL) {};
    tree_node* parent;
    tree_node* left;
    tree_node* right;
};
#endif