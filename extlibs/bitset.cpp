#include "bitset.hpp"
#warning Do not use bitset, bug there!
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

void bitset::to_string(char** res) const
{
    int count = 0;
    for(size_t i = size; i > 0; i--)
    {
        *(*res + count) = (((byte >> (i-1)) & 1) + '0');
        count++;
    }
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

void bitset::flip(unsigned i)
{
    byte ^= (1 << i);
}

bool bitset::operator[](unsigned i) const
{
    return (((1 << 1) - 1) & (this->byte >> (i - 1)));
}