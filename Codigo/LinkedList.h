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

    void setHead(Node<T>* head) {
            this->head = head;
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

    Node<T>* getHead () const {
        return this->head;
    }

    Node<T>* find(const T& dato) const {
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
            cout << "Dato eliminado" << endl;
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

    
    void clear() {
        Node<T>* actual = head;
        while (actual != nullptr) {
            Node<T>* siguiente = actual->getNext();
            delete actual;
            actual = siguiente;
        }
        head = nullptr;
    }
    void remove(Node<T>* nodoAEliminar) {
        if (!head || !nodoAEliminar) return;

        if (head == nodoAEliminar) {
            head = head->getNext();
            delete nodoAEliminar;
            return;
        }

        Node<T>* actual = head;
        while (actual->getNext() && actual->getNext() != nodoAEliminar) {
            actual = actual->getNext();
        }

        if (actual->getNext() == nodoAEliminar) {
            actual->setNext(nodoAEliminar->getNext());
            delete nodoAEliminar;
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
