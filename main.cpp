#include "priority_queue.hpp"
#include "tree_node.hpp"
#include <iostream>

int main()
{
    priority_queue<tree_node> sd;
    for (size_t i = 0; i < 5; i++)
    {
        sd.add(symbol('a'));
    }
    
    sd.add(symbol('b', 4));

    sd.add(symbol('c', 89));

    for (size_t i = 0; i < 2; i++)
    {
        /* code */
        sd.add(symbol('d', 3));
        sd.add(symbol('d', 3));
    }
    


    sd.add(symbol('e', 9));

    sd.add(symbol('q', 100));

    sd.add(symbol('s', 89));
    sd.add(symbol('s', 19));

    sd.add(symbol('z', 56));

    sd.add(symbol('n', 133));

    for(int i = 0; i < 9; i++)
    {
        auto tmp = sd.extract_min();
        printf("%c : %ld\n", tmp.sym, tmp.count);
    }
    return 0;
}