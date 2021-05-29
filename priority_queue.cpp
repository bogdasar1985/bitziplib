#ifdef PRIORITY_QUEUE
#include "priority_queue.hpp"
template <typename T>
priority_queue<T>::priority_queue() : heap(), is_heapify(false) {};

template <typename T>
priority_queue<T>::priority_queue(size_t size) : heap(), is_heapify(false) { heap.reserve(size); };

template <typename T>
priority_queue<T>::~priority_queue() = default;

template <typename T>
void priority_queue<T>::add(const T& sym)
{
    // Если символ есть, то инкрементируем
    // Если нет, то добавляем
    // Проверяем правильность его положения
    for(size_t i = 0; i < heap.size(); i++)
    {
        if(sym.sym == -1)
        {
            break;
        }
        if(heap[i].sym == sym.sym)
        {
            heap[i].count++;
            //heapify(i);
            is_heapify = false;
            return;
        }
    }
    heap.push_back(sym);
}

template <typename T>
T priority_queue<T>::extract_min()
{
    if(!is_heapify)
        heapify(0);
        is_heapify = true;
    symbol sym = heap[0];
    std::swap(heap[0], heap[heap.size()-1]);
    heap.erase(heap.end()-1);
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
        if (leftChild < heap.size() && heap[leftChild] < heap[smallestChild]) 
        {
            smallestChild = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallestChild])
        {
            smallestChild = rightChild;
        }

        if (smallestChild == index) 
        {
            break;
        }

        T temp = heap[index];
        heap[index] = heap[smallestChild];
        heap[smallestChild] = temp;
        index = smallestChild;
    }
}
#endif