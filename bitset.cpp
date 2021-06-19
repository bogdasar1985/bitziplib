#include "bitset.hpp"
bitset::bitset() : size(8), byte(0x0) {}

bitset::~bitset() {}

void bitset::set(unsigned n)
{
    byte |= (1 << n);
}

void bitset::reset(unsigned n)
{
    byte &= ~(1 << n);
}

char* bitset::to_string() const
{
    char *tmp = new char[sizeof(char) * 8 + 1];
    memset(tmp, '\0', sizeof(char) * 8 + 1);
    int count = 0;
    for(size_t i = size; i > 0; i--)
    {
        tmp[count] = (((byte >> (i-1)) & 1) + '0');
        count++;
    }
    return tmp;
}

void bitset::set_size(size_t sz)
{
    size = sz;
}

void bitset::flip()
{
    for(int i = 0; i < sizeof(byte) * 8; i++)
    {
        byte ^= (1 << i);
    }
}
