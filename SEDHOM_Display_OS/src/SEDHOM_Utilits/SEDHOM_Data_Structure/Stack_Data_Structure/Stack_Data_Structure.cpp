//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
#include "Stack_Data_Structure.h"
//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
// -------- Stack implementation --------
template<typename T>
Stack<T>::Stack(int Stack_size)
{
    size = Stack_size;
    array = new T[size];
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] array;
}

template<typename T>
void Stack<T>::init_Stack(int Stack_size)
{
    delete[] array;
    size = Stack_size;
    array = new T[size];
    top = -1;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

template<typename T>
bool Stack<T>::isFull()
{
    return top == size - 1;
}

template<typename T>
void Stack<T>::push(T value)
{
    if (isFull()) return;
    array[++top] = value;
}

template<typename T>
T Stack<T>::pop()
{
    if (isEmpty()) return T();
    return array[top--];
}

template<typename T>
T Stack<T>::peek()
{
    if (isEmpty()) return T();
    return array[top];
}
//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
