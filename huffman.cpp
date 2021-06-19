#include "huffman.hpp"
huffman::huffman() {}

huffman::~huffman() {}

void huffman::add_symbol(char sym)
{
    pq.add(tree_node(sym));
}

tree_node* huffman::build_tree()
{
    tree_node* res_node = NULL;
    while(pq.size() != 1)
    {
        tree_node *node1 = new tree_node; 
        *node1 = pq.extract_min();
        tree_node *node2 = new tree_node;
        *node2 = pq.extract_min();
        res_node = new tree_node;
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
        pq.add(*res_node);
        if(pq.size() != 1)
        {
            delete res_node;
        }
    }
    set_parent_nodes(res_node);
    return res_node;
}

void huffman::free_tree(tree_node* root)
{
    if(root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }
}

bitset huffman::get_code(tree_node* root, char sym)
{
    tree_node* find = NULL;
    bitset bitset;
    int count = 0;
    int size = 0;
    find_node(root, sym, &find);
    tree_node* curr = find;
    if(find == NULL)
    {
        throw "Can't find node!";
    }

    while (curr != root)
    {
        tree_node* tmp = curr;
        curr = curr->parent;
        if(tmp == curr->left)
        {
            bitset.reset(count);
        }
        if(tmp == curr->right)
        {
            bitset.set(count);
        }
        count++;
        size++;
    }
    bitset.set_size(size);
    return bitset;
}

void huffman::set_parent_nodes(tree_node* root)
{
    if(root != NULL)
    {
        if(root->left)
            root->left->parent = root;
        if(root->right)
            root->right->parent = root;
        set_parent_nodes(root->left);
        set_parent_nodes(root->right);
    }
}

void huffman::find_node(tree_node* root, char sym, tree_node** res)
{
    if(root != NULL)
    {
        find_node(root->left, sym, res);
        find_node(root->right, sym, res);
        if(root->sym == sym)
            *res = root;
    }
}
