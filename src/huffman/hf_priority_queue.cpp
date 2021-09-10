#include "hf_priority_queue.hpp"
hf_priority_queue::hf_priority_queue() {}

hf_priority_queue::hf_priority_queue(size_t size) { _heap.reserve(size); }

hf_priority_queue::hf_priority_queue(const hf_priority_queue& queue) : _heap(queue._heap) {}

hf_priority_queue::~hf_priority_queue() {}

hf_priority_queue& hf_priority_queue::operator=(const hf_priority_queue& queue)
{
    _heap = queue._heap;
    return *this;
}

void hf_priority_queue::add(const tree_node& sym)
{
    // If symbol exist, increment counter
    // If not, add a new symbol
    // Fix position
    for(size_t i = 0; i < _heap.size(); i++)
    {
        if(sym.sym == -1)
        {
            break;
        }
        if(_heap[i].sym == sym.sym)
        {
            _heap[i].count+=sym.count;
            shiftDown(i);
            return;
        }
    }
    _heap.push_back(sym);
    shiftUp(_heap.size() - 1);
}

tree_node hf_priority_queue::extract_min()
{
    tree_node sym = _heap[0];
    _heap[0] = _heap[_heap.size() - 1];
    _heap.remove(_heap.size() - 1);
    shiftDown(0);
    return sym;
}

void hf_priority_queue::shiftUp(long index)
{
    while(_heap[index] < _heap[(index - 1) / 2])
    {
        swap(_heap[index], _heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void hf_priority_queue::shiftDown(size_t index)
{
    while ((2 * index + 1) < _heap.size())
    {
        size_t left = 2 * index +1;
        size_t right = 2 * index + 2;
        int j = left;
        if((right < _heap.size()) && (_heap[right] < _heap[left]))
        {
            j = right;
        }
        if(_heap[index] <= _heap[j])
        {
            break;
        }
        swap(_heap[index], _heap[j]);
        index = j;
    }
}

size_t hf_priority_queue::size() const 
{
    return _heap.size();
}

tree_node hf_priority_queue::top() const
{
    return _heap[0];
}

void hf_priority_queue::serialize(FILE* fl) const
{
    for (size_t i = 0; i < _heap.size(); ++i)
    {
        char tmp = _heap[i].sym;
        size_t sz = _heap[i].count;
        fwrite(&tmp, sizeof(tmp), 1, fl);
        fwrite(&sz, sizeof(sz), 1, fl);
    }
}

void hf_priority_queue::deserialize(FILE* fl, size_t pq_size)
{
    for(size_t i = 0; i < pq_size; i++)
    {
        char ch_tmp = '\0';
        size_t sz = 0;
        fread(&ch_tmp, sizeof(ch_tmp), 1, fl);
        fread(&sz, sizeof(sz), 1, fl);
        _heap.push_back(symbol(ch_tmp, sz));
    }
}

