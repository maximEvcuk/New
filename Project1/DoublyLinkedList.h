#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T >
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node(T value) : data(value), next(nullptr), prev(nullptr) {}
	
};

class EmptyListException : public std::runtime_error {
public:
    EmptyListException() : std::runtime_error("The list is empty!") {}
};

class MemoryAllocationException : public std::runtime_error {
    MemoryAllocationException() : std::runtime_error("Memory allocation error!") {}

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
    void InsertAt(T value, int position);
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