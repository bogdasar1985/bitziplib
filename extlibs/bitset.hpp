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
    void flip(unsigned i);
    bool operator[](unsigned i) const;
    void to_string(char** res) const;
    void set_size(size_t sz); // Dangerous method!
    size_t get_size() const;
private:
    size_t size;
    char byte;
};
#endif
