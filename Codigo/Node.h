#pragma once
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Node {
    private:
        T dato;
        Node<T>* next;
    public:
        Node(T dato) {
            this->dato = dato;
            this->next = nullptr;
        }
        T getDato() {
            return this->dato;
        }
        void setDato(T dato) {
            this->dato = dato;
        }

        void setNext(Node<T>* next) {
            this->next = next;
        }

        Node<T>* getNext() {
            return this->next;
        }

        ~Node() = default;
};
