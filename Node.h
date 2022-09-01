//
// Created by Juan Felipe Restrepo on 1/09/2022.
//

#ifndef CLASELISTASENLAZADAS_NODE_H
#define CLASELISTASENLAZADAS_NODE_H


class Node {
private:
    int value;
    Node * next;
public:
    Node();
    Node(int value);
    Node(int value, Node * next);
    int getValue();
    void setValue(int data);
    Node * getNext();
    void setNext(Node * following);
};


#endif //CLASELISTASENLAZADAS_NODE_H
