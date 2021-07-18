// Implementation of priority queue, based on heap
#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include "dynamic_array.hpp"
#include "tree_node.hpp"
#include "utility.hpp"
#include <stdio.h>
class hf_priority_queue
{
public:
    hf_priority_queue();
    hf_priority_queue(size_t size);
    hf_priority_queue(const hf_priority_queue& queue);
    ~hf_priority_queue();
    hf_priority_queue& operator=(const hf_priority_queue& queue);
    void add(const tree_node& sym);
    tree_node extract_min();
    tree_node top() const;
    size_t size() const;
    void serialize(FILE* fl) const;
    void deserialize(FILE *fl, size_t pq_size);
private:
    void shiftUp(long index);
    void shiftDown(long index);
    dynamic_array<tree_node> _heap;
};
#endif
