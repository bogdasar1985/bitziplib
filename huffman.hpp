#ifndef HUFFMAN
#define HUFFMAN
#include "priority_queue.hpp"
#include "bitset.hpp"
#include <stdio.h>
/**
class huffman
{
public:
    huffman();
    ~huffman();
    void add_symbol(char sym);
    void build_tree();
    bitset get_code(char sym) const;
    tree_node find_node(char sym) const;
    size_t pq_size() const;
private:
    static void free_tree(tree_node* root);
    static void find_node(tree_node* root, char sym, tree_node** res);
    void set_parent_nodes(tree_node* root);
    priority_queue pq;
    tree_node* root;
};
*/
namespace huffman
{
    struct huffman
    {
        priority_queue pq;
        tree_node* root;
        huffman();
        ~huffman();
    };
    void add_symbol(huffman& huf, char sym);
    void build_tree(huffman& huf);
    bitset get_code(huffman& huf,  char sym);
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
