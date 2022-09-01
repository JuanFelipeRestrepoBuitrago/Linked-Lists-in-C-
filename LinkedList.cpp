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