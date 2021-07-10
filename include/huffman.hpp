#ifndef HUFFMAN
#define HUFFMAN
#include "../hf_priority_queue.hpp"
#include "../bitset.hpp"
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
    bitset get_code(huffman& huf,  char sym);
    void get_code(huffman& huf, char sym, char** res);
    tree_node find_node(huffman& huf, char sym);
    size_t pq_size(huffman& huf);

    namespace huffman_utils
    {
        void free_tree(tree_node* root);
        void set_parent_nodes(tree_node* root);
        void find_node(tree_node* root, char sym, tree_node** res);
    }
}
#endif
