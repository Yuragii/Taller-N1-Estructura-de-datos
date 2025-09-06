#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
Node<T>::Node(T dato) {
    this->dato = dato;
    this->next = nullptr;
}
template <typename T>
T Node<T>::getDato() {
    return this->dato;
}