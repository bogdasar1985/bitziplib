// Implementation of priority queue, based on heap
#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include "dynamic_array.hpp"
#include "tree_node.hpp"
#include "utility.hpp"
class hf_priority_queue
{
public:
    hf_priority_queue();
    hf_priority_queue(size_t size);
    ~hf_priority_queue();
    void add(const tree_node& sym);
    tree_node extract_min();
    tree_node top() const;
    size_t size() const;
private:
    void shiftUp(long index);
    void shiftDown(long index);
    dynamic_array<tree_node> _heap;
};
#endif
