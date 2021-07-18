#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include <stdlib.h>
#include <math.h>
#include "utility.hpp"
#define EPS 1e-11
template <typename T>
class dynamic_array
{
public:
    dynamic_array();
    dynamic_array(const dynamic_array& arr);
    ~dynamic_array();
    void push_back(const T& sym);
    size_t size() const;
    T& operator[] (const size_t index);
    T operator[] (const size_t index) const;
    T remove(const size_t index);
    void reserve(const size_t capacity);
private:
    T* array;
    size_t _size;
    size_t _capacity;
    inline double log2(double n);
    inline int high_bit_log2(uint n);
    inline int closest_two_power(uint n);
};
#include "dynamic_array.cpp"
#endif
