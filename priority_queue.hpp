// Implementation of priority queue, based on heap

#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include "dynamic_array.hpp"
#include "symbol.hpp"
#include "utility.hpp"
template <typename T>
class priority_queue
{
public:
    priority_queue();
    priority_queue(size_t size);
    ~priority_queue();
    void add(const T& sym);
    T extract_min();
    size_t size() const;
private:
    void heapify(size_t index);
    //std::vector<T> heap;
    dynamic_array<T> _heap;
    bool is_heapify;
};
#include "priority_queue.cpp"
#endif