//LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
#include "LinkedList_Data_Structure.h"
//LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
// -------- LinkedList implementation --------
template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

template<typename T>
void LinkedList<T>::add_end(T val)
{
    Node<T>* newNode = new Node<T>(val);
    if(head == nullptr)
    {
        head = newNode;
        return ;
    }
    else
    {
        Node<T>* temp = head;
        while ( temp->next = nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
//LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL