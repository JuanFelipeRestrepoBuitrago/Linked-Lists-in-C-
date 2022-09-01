//
// Created by Juan Felipe Restrepo Buitrago on 1/09/2022.
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

    void deleteValue(int data);
    void deleteIndex(int index);

    bool searchValue(int data);
    bool searchIndex(int index);

    int getIndex(int data);
    int getData(int index);
    int getSize();

    int nodeInIndex(int index);
    int nodeWithData(int data);

    Node * getLast(Node * current);
    void printList(Node * current);

};


#endif //CLASELISTASENLAZADAS_LINKEDLIST_H
