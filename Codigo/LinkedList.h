#pragma once;
#include "Node.h"
template <typename T>
class LinkedList {
    private:
        Node<T>* head;
    public:
        LinkedList();
        void append(T dato);
        void display();
 
        Node<T>* getHead();

        Node<T>* find(T dato);

        void borrarDato(T dato);

        ~LinkedList();
};