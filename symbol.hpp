#ifndef SYMBOL
#define SYMBOL
#include <stdlib.h>
struct symbol
{
    symbol() : sym(-1), count(0) {};
    symbol(char _s) : sym(_s), count(1) {};
    symbol(char _s, size_t _count) : sym(_s), count(_count) {};
    bool operator<(const symbol& symb) const
    {
        return count < symb.count;
    }
    bool operator>(const symbol& symb) const
    {
        return count > symb.count;
    }
    bool operator<=(const symbol& symb) const
    {
        return count <= symb.count;
    }
    char sym;
    size_t count;
};
#endif
