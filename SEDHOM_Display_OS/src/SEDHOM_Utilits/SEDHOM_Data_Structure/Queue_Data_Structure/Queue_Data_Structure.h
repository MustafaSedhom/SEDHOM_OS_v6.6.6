//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
#ifndef SEDHOM_QUEUE_DATA_STRUCTURE_H
#define SEDHOM_QUEUE_DATA_STRUCTURE_H
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
template<typename T>
class Queue
{
private:
    T* array;
    int size;
    int front;
    int rear;
    int count;

public:
    Queue() : array(nullptr), size(0), front(0), rear(-1), count(0) {}
    Queue(int Queue_size);
    ~Queue();

    void init_Queue(int Queue_size);
    bool enqueue(T value);
    T dequeue();

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == size; }
    int getCount() { return count; }
};
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
#endif //SEDHOM_QUEUE_DATA_STRUCTURE_H
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB