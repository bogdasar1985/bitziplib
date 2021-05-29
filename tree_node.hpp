#ifndef TREE_NODE
#define TREE_NODE
#include "symbol.hpp"
struct tree_node : public symbol
{
    tree_node() : symbol(), parent(NULL), left(NULL), right(NULL) {};
    tree_node(symbol sym) : symbol(sym), parent(NULL), left(NULL), right(NULL) {};
    symbol* parent;
    symbol* left;
    symbol* right;
};
#endif