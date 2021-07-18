#ifndef HUFFMAN
#define HUFFMAN
#include "../src/huffman/hf_priority_queue.hpp"
#include "../extlibs/bitset.hpp"
#include <stdio.h>
namespace huffman
{
    struct huffman
    {
        hf_priority_queue pq;
        tree_node* root;
        huffman();
        ~huffman();
    };
    void add_symbol(huffman& huf, char sym);
    void build_tree(huffman& huf);
    bitset get_code(const huffman& huf,  char sym);
    void get_code(const huffman& huf, char sym, char** res);
    char get_symbol(const huffman& huf, char* code);
    tree_node find_node(const huffman& huf, char sym);
    size_t pq_size(const huffman& huf);

    namespace huffman_utils
    {
        void free_tree(tree_node* root);
        void set_parent_nodes(tree_node* root);
        void find_node(tree_node* root, char sym, tree_node** res);
    }
}
#endif
