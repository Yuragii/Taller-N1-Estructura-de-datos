#pragma once
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template <typename T>
class LinkedList {
    private:
        Node<T>* head;
    public:

        LinkedList() {
            this->head = nullptr;
    }

    void append(T dato) {
        Node<T>* newNode = new Node<T>(dato);
        if (this->head == nullptr) {
            this->head = newNode;
        } else {
            Node<T>* current = this->head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    void display() {
        Node<T>* current = this->head;
        while (current != nullptr) {
            cout << current->getDato() << " -> ";
            current = current->getNext();
        }
        cout << "nullptr" << endl;
    }

    Node<T>* getHead()  {
        return this->head;
    }

    Node<T>* find(T dato) {
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (current->getDato() == dato) {
                return current;
            }
            current = current->getNext();
        }
        return nullptr;
    }



    void borrarDato(T dato) {
        if (head == nullptr) {
            cout << "Lista Vacía"<< endl;
            return;
        } 

        if (head->getDato() == dato) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
            return;
        }

        Node<T>* current = head;
        while (current->getNext() != nullptr && current->getNext()->getDato() != dato) {
            current = current->getNext();
        }

        if (current->getNext() != nullptr) {
            Node<T>* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
        }
    }
    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;
        while (current != nullptr) {
            nextNode = current->getNext();
            delete current;
            current = nextNode;
            }
        }
       
};
