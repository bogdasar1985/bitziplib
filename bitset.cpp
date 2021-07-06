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
    char *tmp = new char[size + 1];
    memset(tmp, '\0', size + 1);
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

size_t bitset::get_size() const
{
    return size;
}

void bitset::flip()
{
    for(size_t i = 0; i < sizeof(byte) * 8; i++)
    {
        byte ^= (1 << i);
    }
}
