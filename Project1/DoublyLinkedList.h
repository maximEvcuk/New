#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T >
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node(T value) : data(value), next(nullptr), prev(nullptr) {}
	
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddToHead(T value);
    void AddToToil(T value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show() const;
};

#include "DoublyLinkedList.h"




#endif // DOUBLY_LINKED_LIST_H