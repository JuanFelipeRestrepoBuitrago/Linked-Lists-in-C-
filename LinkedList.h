//
// Created by Juan Felipe Restrepo on 1/09/2022.
//

#ifndef CLASELISTASENLAZADAS_LINKEDLIST_H
#define CLASELISTASENLAZADAS_LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node * head;
public:

    LinkedList();

    Node* getHead();

    void createLinkedList(int data);
    void insertAtTheTop(int data);
    void insertAtTheEnd(int data);

    Node* deleteValue(Node* current, int data);
    void deleteIndex( int index);

    bool searchValue(int data);
    bool searchIndex(int index);

    int getIndex(int data);
    int getData(int index);
    int getSize();

    Node* nodeWithData(int data);
    Node* nodeInIndex(int index);

    Node * getLast(Node * current);
    void printList(Node * current);

};


#endif //CLASELISTASENLAZADAS_LINKEDLIST_H
