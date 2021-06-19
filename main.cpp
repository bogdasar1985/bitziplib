#include "huffman.hpp"
#include <stdio.h>
#include <string.h>
int main()
{
    const char* str = "Bogdasar";
    size_t len = strlen(str);
    huffman s;
    for(size_t i = 0; i < len; i++)
    {
        s.add_symbol(str[i]);
    }
    auto tree = s.build_tree();
    char* bitstr = NULL;

    for(size_t i = 0; i < strlen(str); i++)
    {
        bitset bts = huffman::get_code(tree, str[i]);
        bitstr = bts.to_string();
        printf("%c %s\n", str[i], bitstr);
        delete[] bitstr;
    }
    huffman::free_tree(tree);
    return 0;
}
