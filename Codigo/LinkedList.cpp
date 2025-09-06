#include "LinkedList.h"
#include <bits/stdc++.h>
using namespace std;
template <typename T>

LinkedList<T>::LinkedList() {
    this->head = nullptr;
}
template <typename T>
void LinkedList<T>::append(T dato) {
    Node<T>* newNode = new Node<T>(dato);
    if (this->head == nullptr) {
        this->head = newNode;
    } else {
        Node<T>* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
template <typename T>
void LinkedList<T>::display() {
    Node<T>* current = this->head;
    while (current != nullptr) {
        cout << current->getDato() << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}
template <typename T>
Node<T>* LinkedList<T>::getHead() {
    return this->head;
}
template <typename T>
Node<T>* LinkedList<T>::find(T dato) {
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (current->getDato() == dato) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
template <typename T>
LinkedList<T>::~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
            }
        }
template <typename T>
void LinkedList<T>::borrarDato(T dato) {
    if (head == nullptr) return; // Lista vacía

    if (head->getDato() == dato) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr && current->next->getDato() != dato) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}


