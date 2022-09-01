//
// Created by Juan Felipe Restrepo on 1/09/2022.
//

#include "Node.h"

Node::Node() {
    this -> value = 0;
    this -> next = nullptr;
}
Node::Node(int value) {
    this -> value = value;
    this -> next = nullptr;
}
Node::Node(int value, Node *next) {
    this -> value = value;
    this -> next = next;
}
int Node::getValue() {
    return this -> value;
}
void Node::setValue(int value) {
    this -> value = value;
}
Node * Node::getNext() {
    return this -> next;
}
void Node::setNext(Node *next) {
    this -> next = next;
}