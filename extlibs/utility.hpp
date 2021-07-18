#ifndef UTILITY
#define UTILITY
template <typename T>
void swap(T& first, T& second)
{
    T tmp = first;
    first = second;
    second = tmp;
}
#endif
