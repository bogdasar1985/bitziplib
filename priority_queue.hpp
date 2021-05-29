// Implementation of priority queue, based on heap

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include <vector>
#include "symbol.hpp"
template <typename T>
class priority_queue
{
public:
    priority_queue();
    priority_queue(size_t size);
    ~priority_queue();
    void add(const T& sym);
    T extract_min();
private:
    void heapify(size_t index);
    std::vector<T> heap;
    bool is_heapify;
};
#include "priority_queue.cpp"
#endif