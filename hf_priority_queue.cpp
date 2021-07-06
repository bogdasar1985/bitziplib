#include "hf_priority_queue.hpp"
hf_priority_queue::hf_priority_queue() {}

hf_priority_queue::hf_priority_queue(size_t size) { _heap.reserve(size); }

hf_priority_queue::~hf_priority_queue() {}

void hf_priority_queue::add(const tree_node& sym)
{
    // Если символ есть, то инкрементируем
    // Если нет, то добавляем
    // Проверяем правильность его положения
    for(size_t i = 0; i < _heap.size(); i++)
    {
        if(sym.sym == -1)
        {
            break;
        }
        if(_heap[i].sym == sym.sym)
        {
            _heap[i].count+=sym.count;
            //heapify(i);
            //is_heapify = false;
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

void hf_priority_queue::shiftDown(long index)
{
    while ((2 * index + 1) < _heap.size())
    {
        int left = 2 * index +1;
        int right = 2 * index + 2;
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
