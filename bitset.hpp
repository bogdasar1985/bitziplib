#ifndef BITSET
#define BITSET
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
class bitset
{
public:
    bitset();
    ~bitset();
    void set(unsigned n);
    void reset(unsigned n);
    void flip();
    char* to_string() const;
    void set_size(size_t sz); // Dangerous method!
private:
    size_t size;
    char byte;
};
#endif
