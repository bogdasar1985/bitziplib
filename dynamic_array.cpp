#ifdef DYNAMIC_ARRAY
#include "dynamic_array.hpp"
template <typename T>
dynamic_array<T>::dynamic_array() : _size(0), _capacity(16)
{
    array = new T[16];
};

template <typename T>
dynamic_array<T>::~dynamic_array()
{
    delete[] array;
};

template <typename T>
size_t dynamic_array<T>::size() const
{
    return _size;
};

template <typename T>
T& dynamic_array<T>::operator[](const size_t index)
{
    return array[index];
};

template <typename T>
void dynamic_array<T>::reserve(const size_t capacity)
{
    if(capacity < _capacity)
    {
        return;
    }

    T* new_buf = new T[capacity];
    for(size_t i = 0; i < _size; i++)
    {
        new_buf[i] = array[i];
    }

    _capacity = capacity;
    delete[] array;
    array = new_buf;
};

template <typename T>
void dynamic_array<T>::push_back(const T& sym)
{
    if(_size >= _capacity)
    {
        reserve(closest_two_power(_capacity));
    }
    array[_size++] = sym;
};

template <typename T>
T dynamic_array<T>::remove(const size_t index)
{
    if(index == _size - 1)
    {
        _size--;
    }
    else
    {
        for(size_t i = index; i < _size-1; i++)
        {
            swap(array[i], array[i + 1]);
        }
        _size--;
    }
    return *(array+index);
};

template <typename T>
inline double dynamic_array<T>::log2(double n)
{
    return log(n) / log(2.0);    
}

template <typename T>
inline int dynamic_array<T>::high_bit_log2(uint n) 
{
  return (int)(log2((double)n) + EPS);
}

template <typename T>
inline int dynamic_array<T>::closest_two_power(uint n) 
{
    int t = high_bit_log2(n);
    n = 0;
    n |= (1 << (t+1));
    return n;
}

#endif