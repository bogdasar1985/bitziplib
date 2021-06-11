/*
TODO:
    Вопрос:
    symbol и tree_node
    Агрегация или наследование
0*/
#include "huffman.hpp"
#include "tree_node.hpp"
#include <stdio.h>
int main()
{
    priority_queue sd;
    for (size_t i = 0; i < 5; i++)
    {
        sd.add(symbol('a'));
    }
    
    sd.add(symbol('b', 6));

    sd.add(symbol('c', 89));

    for (size_t i = 0; i < 2; i++)
    {
        //code
        sd.add(symbol('d', 3));
        sd.add(symbol('d', 3));
    }


    sd.add(symbol('e', 9));

    sd.add(symbol('q', 100));

    sd.add(symbol('s', 89));
    sd.add(symbol('s', 19));

    sd.add(symbol('z', 56));

    sd.add(symbol('n', 133));

    size_t sz = sd.size();
    for(int i = 0; i < sz; i++)
    {
        auto tmp = sd.extract_min();
        printf("%c %ld\n", tmp.sym, tmp.count);
    }
    return 0;
}