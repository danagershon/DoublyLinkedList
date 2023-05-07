#include "DoublyLinkedList.h"

template<typename T>
Node<T>::Node(T data, Node *prev, Node *next)
: data(data),prev(prev),next(next)
{}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
        : head(new Node<T>()),tail(new Node<T>()),size(0)
{
    head->next = tail;
    tail->prev = head;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while(head){
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void DoublyLinkedList<T>::appendLeft(T data) {
    Node<T>* new_node = new Node(data,head,head->next);
    head->next->prev = new_node;
    head->next = new_node;
    size++;
}

template<typename T>
void DoublyLinkedList<T>::appendRight(T data) {
    Node<T>* new_node = new Node(data,tail->prev,tail);
    tail->prev->next = new_node;
    tail->prev = new_node;
    size++;
}

template<typename T>
void DoublyLinkedList<T>::remove(T data) {
    if(size == 0){
        throw EmptyList();
    }

    Node<T>* curr = head->next;

    while(curr != tail && curr->data != data){
        curr = curr->next;
    }

    if(curr != tail){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }
}

template<typename T>
bool DoublyLinkedList<T>::search(T data) {
    Node<T>* curr = head->next;

    while(curr != tail && curr->data != data){
        curr = curr->next;
    }

    return curr != tail;
}

template<typename T>
T DoublyLinkedList<T>::popLeft() {
    if(size == 0){
        throw EmptyList();
    }

    Node<T>* temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;

    T data = temp->data;
    delete temp;
    size--;

    return data;
}

template<typename T>
T DoublyLinkedList<T>::popRight() {
    if(size == 0){
        throw EmptyList();
    }

    Node<T>* temp = tail->prev;
    temp->prev->next = tail;
    tail->prev = temp->prev;

    T data = temp->data;
    delete temp;
    size--;

    return data;
}

template<typename T>
T DoublyLinkedList<T>::peekLeft() {
    if(size == 0){
        throw EmptyList();
    }

    return head->next->data;
}

template<typename T>
T DoublyLinkedList<T>::peekRight() {
    if(size == 0){
        return -1;
    }

    return tail->prev->data;
}

template<typename T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

const char* EmptyList::what() const noexcept {
    return "Error: list is empty";
}

template class Node<int>;
template class DoublyLinkedList<int>;