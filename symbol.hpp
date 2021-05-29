#ifndef SYMBOL
#define SYMBOL
#include <stdlib.h>
struct symbol
{
    symbol() : sym(-1), count(0) {};
    symbol(char s) : sym(s), count(1) {};
    symbol(char s, size_t count) : sym(s), count(count) {};
    const bool operator<(const symbol& symb) const
    {
        return count < symb.count;
    };
    const bool operator>(const symbol& symb) const
    {
        return count > symb.count;
    };
    size_t count;
    char sym;
};
#endif