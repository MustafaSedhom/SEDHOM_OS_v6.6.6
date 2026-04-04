//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
#include "Queue_Data_Structure.h"
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
// -------- Queue implementation --------
template<typename T>
Queue<T>::Queue(int Queue_size)
{
    size = Queue_size;
    array = new T[size];
    front = 0;
    rear = -1;
    count = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] array;
}

template<typename T>
void Queue<T>::init_Queue(int Queue_size)
{
    delete[] array;
    size = Queue_size;
    array = new T[size];
    front = 0;
    rear = -1;
    count = 0;
}

template<typename T>
bool Queue<T>::enqueue(T value)
{
    if (isFull()) return false;
    rear = (rear + 1) % size;
    array[rear] = value;
    count++;
    return true;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (isEmpty()) return T();
    T value = array[front];
    front = (front + 1) % size;
    count--;
    return value;
}
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
