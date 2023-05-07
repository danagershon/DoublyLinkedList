#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int value,Node* prev,Node* next);
    ~Node() = default;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void appendLeft(int value);
    void appendRight(int value);
    void remove(int value);
    bool search(int value);
    int popLeft();
    int popRight();
    int peekLeft();
    int peekRight();
    int getSize();
    void printList();
};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
