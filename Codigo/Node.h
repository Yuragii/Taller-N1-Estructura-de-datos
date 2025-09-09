#pragma once
#include <bits/stdc++.h>
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
        getDato() {
            return this->dato;
}
        ~Node() {
        }
};
