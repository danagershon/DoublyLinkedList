#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>
#include <exception>

class ListException: public std::exception{};

class EmptyList: public ListException{
    const char* what () const noexcept override;
};

template <typename T = int> class Node {
public:
    T data;
    Node* prev;
    Node* next;

    explicit Node(T data = T(), Node* prev=nullptr, Node* next= nullptr);
    ~Node() = default;
};

template <typename T = int> class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void appendLeft(T data);
    void appendRight(T data);
    void remove(T data);
    bool search(T data);
    T popLeft();
    T popRight();
    T peekLeft();
    T peekRight();
    int getSize();
    friend std::ostream & operator << (std::ostream &out, const DoublyLinkedList<T> &list){
        Node<T>* curr = list.head->next;
        while(curr != list.tail){
            out << curr->data << " ";
            curr = curr->next;
        }
        out << std::endl;
        return out;
    }
};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
