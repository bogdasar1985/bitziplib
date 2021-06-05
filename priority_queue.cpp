#ifdef PRIORITY_QUEUE
#include "priority_queue.hpp"
template <typename T>
priority_queue<T>::priority_queue() : _heap(), is_heapify(false) {};

template <typename T>
priority_queue<T>::priority_queue(size_t size) : _heap(), is_heapify(false) { _heap.reserve(size); };

template <typename T>
priority_queue<T>::~priority_queue() = default;

template <typename T>
void priority_queue<T>::add(const T& sym)
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
            _heap[i].count++;
            //heapify(i);
            is_heapify = false;
            return;
        }
    }
    _heap.push_back(sym);
}

template <typename T>
T priority_queue<T>::extract_min()
{
    if(!is_heapify)
        heapify(0);
        is_heapify = true;
    symbol sym = _heap[0];
    swap(_heap[0], _heap[_heap.size()-1]);
    _heap.remove(_heap.size() - 1);
    is_heapify = false;
    return sym;
}

template <typename T>
void priority_queue<T>::heapify(size_t index)
{
    size_t leftChild;
    size_t rightChild;
    size_t smallestChild;

    while(true)
    {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallestChild = index;
        if (leftChild < _heap.size() && _heap[leftChild] < _heap[smallestChild]) 
        {
            smallestChild = leftChild;
        }

        if (rightChild < _heap.size() && _heap[rightChild] < _heap[smallestChild])
        {
            smallestChild = rightChild;
        }

        if (smallestChild == index) 
        {
            break;
        }

        T temp = _heap[index];
        _heap[index] = _heap[smallestChild];
        _heap[smallestChild] = temp;
        index = smallestChild;
    }
};

template <typename T>
size_t priority_queue<T>::size() const 
{
    return _heap.size();
};
#endif