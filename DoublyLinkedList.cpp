#include "DoublyLinkedList.h"

Node::Node(int value, Node *prev= nullptr, Node *next= nullptr)
: value(value),prev(prev),next(next)
{}

DoublyLinkedList::DoublyLinkedList()
: head(new Node(-1)),tail(new Node(-1)),size(0)
{
    head->next = tail;
    tail->prev = head;
}

DoublyLinkedList::~DoublyLinkedList() {
    while(head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::appendLeft(int value) {
    Node* new_node = new Node(value,head,head->next);
    head->next->prev = new_node;
    head->next = new_node;
    size++;
}

void DoublyLinkedList::appendRight(int value) {
    Node* new_node = new Node(value,tail->prev,tail);
    tail->prev->next = new_node;
    tail->prev = new_node;
    size++;
}

void DoublyLinkedList::remove(int value) {
    if(size == 0){
        return;
    }

    Node* curr = head->next;

    while(curr != tail && curr->value != value){
        curr = curr->next;
    }

    if(curr != tail){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
    size--;
}

bool DoublyLinkedList::search(int value) {
    Node* curr = head->next;

    while(curr != tail && curr->value != value){
        curr = curr->next;
    }

    return curr != tail;
}

int DoublyLinkedList::popLeft() {
    if(size == 0){
        return -1;
    }

    Node* temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;

    int value = temp->value;
    delete temp;
    size--;

    return value;
}

int DoublyLinkedList::popRight() {
    if(size == 0){
        return -1;
    }

    Node* temp = tail->prev;
    temp->prev->next = tail;
    tail->prev = temp->prev;

    int value = temp->value;
    delete temp;
    size--;

    return value;
}

int DoublyLinkedList::peekLeft() {
    if(size == 0){
        return -1;
    }

    return head->next->value;
}

int DoublyLinkedList::peekRight() {
    if(size == 0){
        return -1;
    }

    return tail->prev->value;
}

int DoublyLinkedList::getSize() {
    return size;
}

void DoublyLinkedList::printList() {
    Node* curr = head->next;

    std::cout << "printing list:" << std::endl;

    while(curr != tail){
        std::cout << curr->value << " ";
        curr = curr->next;
    }

    std::cout << std::endl;
}
