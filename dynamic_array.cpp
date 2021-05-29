#ifdef DYNAMIC_ARRAY
#include "dynamic_array.hpp"
template <typename T>
dynamic_array<T>::dynamic_array() : _size(0), _capacity(1)
{
    array = new T[1];
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
        reserve(_capacity * 2);
    }
    array[_size++] = sym;
};

template <typename T>
T* dynamic_array<T>::erase(const size_t index)
{
    if(index == _size - 1)
    {
        _size--;
    }
    else
    {
        // Тут короче дописать, как в reserve почти
        T* new_buf = new T[_capacity];
        size_t j = 0;
        for(size_t i = 0; i < _size; i++)
        {
            if(i == index)
            {
                continue;
            }
            new_buf[j] = array[i];
            j++;
        }
        delete[] array; 
        array = new_buf;
        _size--;
    }
    return array;
};
#endif