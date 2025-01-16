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
    void InsertAt(int value, int position);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAt(int position);
    void DeleteAll();
    int Search(T value) const;
    int Replace(T oldValue, T newValue);
    void Reverse();
    void Show() const;
};

#include "DoublyLinkedList.h"




#endif // DOUBLY_LINKED_LIST_H