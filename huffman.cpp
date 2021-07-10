#include "huffman.hpp"
huffman::huffman::huffman() : root(NULL) {}

huffman::huffman::~huffman() 
{
    if(root)
        huffman_utils::free_tree(root);
}

void huffman::add_symbol(huffman &huf, char sym)
{
    huf.pq.add(tree_node(sym));
}

void huffman::build_tree(huffman& huf)
{
    tree_node* res_node = NULL;
    while(huf.pq.size() != 1)
    {
        tree_node *node1 = new tree_node; 
        *node1 = huf.pq.extract_min();
        tree_node *node2 = new tree_node;
        *node2 = huf.pq.extract_min();
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
        huf.pq.add(*res_node);
        if(huf.pq.size() != 1)
        {
            delete res_node;
        }
    }
    huffman_utils::set_parent_nodes(res_node);
    huf.root = res_node;
}

void huffman::huffman_utils::free_tree(tree_node* root)
{
    if(root != NULL)
    {
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }
}

bitset huffman::get_code(huffman& huf, char sym)
{
    tree_node* find = NULL;
    bitset bitset;
    int count = 0;
    int size = 0;
    huffman_utils::find_node(huf.root, sym, &find);
    tree_node* curr = find;
    if(find == NULL)
    {
        bitset.set_size(0);
        return bitset;
    }

    while (curr != huf.root)
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

void huffman::get_code(huffman& huf, char sym, char** res)
{
    tree_node* find = NULL;
    int count = 0;
    int size = 0;
    huffman_utils::find_node(huf.root, sym, &find);
    tree_node* curr = find;
    if(find == NULL)
    {
        *res = NULL;
        return;
    }

    while (curr != huf.root)
    {
        tree_node* tmp = curr;
        curr = curr->parent;
        if(tmp == curr->left)
        {
            *(*res + count) = '0';
        }
        if(tmp == curr->right)
        {
            *(*res + count) = '1';
        }
        count++;
        size++;
    }
}

void huffman::huffman_utils::set_parent_nodes(tree_node* root)
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

void huffman::huffman_utils::find_node(tree_node* root, char sym, tree_node** res)
{
    if(root != NULL)
    {
        find_node(root->left, sym, res);
        find_node(root->right, sym, res);
        if(root->sym == sym)
            *res = root;
    }
}

tree_node huffman::find_node(huffman& huf, char sym)
{
    tree_node *res = NULL;
    huffman_utils::find_node(huf.root, sym, &res);
    if(res == NULL)
    {
        tree_node tmp;
        tmp.sym = -1;
        tmp.count = 0;
        tmp.left = NULL;
        tmp.right = NULL;
        tmp.parent = NULL;
        return tmp;
    };
    return *res;
}

size_t huffman::pq_size(huffman& huf)
{
    return huf.pq.size();
}