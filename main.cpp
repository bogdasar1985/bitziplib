/*
TODO:
    Вопрос:
    symbol и tree_node
    Агрегация или наследование
0*/
#include "huffman.hpp"
#include <stdio.h>
#include <string.h>
int main()
{
    const char* str = "abracadabra";
    size_t len = strlen(str);
    huffman s;
    for(int i = 0; i < len; i++)
    {
        s.add_symbol(str[i]);
    }
    s.build_tree(); // Should free memory
    return 0;
}