//
// Created by Juan Felipe Restrepo on 1/09/2022.
//

#include "LinkedList.h"
#include "iostream"

using namespace std;

Node* LinkedList::getHead() {
    return this -> head;
}

LinkedList::LinkedList() {
    this -> head = nullptr;
}


void LinkedList::createLinkedList(int data) {
    Node * newNode = new Node(data);
    this -> head = newNode;
}

void LinkedList::insertAtTheTop(int data) {
    Node * newNode = new Node(data, this -> head);

    this -> head = newNode;
}

void LinkedList::insertAtTheEnd(int data) {

    Node * newNode = new Node(data);
    Node * current = this -> head;

    while (current -> getNext() != nullptr) {
        current = current -> getNext();
    }
    current -> setNext(newNode);
}

Node * LinkedList::getLast(Node * current) {
    if (current == nullptr || current -> getNext() == nullptr) {
        return head;
    }else{
        return this -> getLast(current -> getNext());
    }
}

void LinkedList::printList(Node * current) {
    if (current != nullptr) {
        cout << current -> getValue() << " -> ";
        this -> printList(current -> getNext());
    }else{
        cout << NULL <<endl;
    }
}

void LinkedList::deleteIndex(int index) {
    Node * current = this -> head;
    Node * previous = nullptr;
    int i = 0;
    while (current != nullptr && i < index) {
        previous = current;
        current = current -> getNext();
        i++;
    }
    if (current == nullptr) {
        cout << "No existe una posicion en la lista con ese indice" << endl;
    }else{
        previous -> setNext(current -> getNext());
        delete current;
    }
}

Node* LinkedList::deleteValue(Node* current, int data) {
    if(current == nullptr) {
        return nullptr;
    }else if(current -> getValue() == data){
        Node * new_next = current -> getNext();
        delete current;

        return new_next;
    }else{
        current -> setNext(deleteValue(current -> getNext(), data));
        return current;
    }
}

int LinkedList::getData(int index) {
    Node * current = this -> head;
    while(current != nullptr && index > 0) {
        current = current -> getNext();
        index--;
    }

    return current -> getValue();
}

int LinkedList::getIndex(int data) {
    Node * current = this -> head;
    int index = 0;

    while (current != nullptr) {
        if (current -> getValue() == data) {
            return index;
        }
        current = current -> getNext();
        index++;
    }
    return -1;
}

bool LinkedList::searchIndex(int index) {
    Node * current = this -> head;

    while (index > 0 && current != nullptr) {
        current = current -> getNext();
        index--;
    }

    if (index == 0 && current != nullptr) {
        return true;
    }else{
        return false;
    }
}

bool LinkedList::searchValue(int data) {
    Node * current = this -> head;

    while (current != nullptr) {
        if (current -> getValue() == data) {
            return true;
        }
        current = current -> getNext();
    }

    return false;
}

int LinkedList::getSize() {
    Node * current = this -> head;
    int length = 0;

    while (current != nullptr) {
        current = current -> getNext();
        length++;
    }

    return length;
}

Node* LinkedList::nodeInIndex(int index) {
    Node * current = this -> head;

    while (index > 0 && current != nullptr){
        current = current -> getNext();
        index--;
    }

    if (current == nullptr){
        return nullptr;
    }else{
        return current;
    }
}

Node* LinkedList::nodeWithData(int data) {
    Node * current = this -> head;

    while (current != nullptr) {
        if (current -> getValue() == data) {
            return current;
        }
        current = current -> getNext();
    }

    return nullptr;
}