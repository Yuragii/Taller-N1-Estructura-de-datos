#pragma once;
template <typename T>
class Node {
    private:
        T dato;
        Node<T>* next;
    public:
        Node (T dato);
        T getDato();
        ~Node() {
        }
};
