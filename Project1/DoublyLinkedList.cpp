#include "DoublyLinkedList.h"
#include <list>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	DeleteAll();
}

template < typename T>
void DoublyLinkedList<T>::AddToHead(T value) {
	Node<T>* newNode = new Node<T>(value);
	if (!head){
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

template <typename T>
void DoublyLinkedList<T>::AddToToil(T value) {
	Node<T>* newNode = new Node<T>(value);
	if (!tail) {
		head = tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}
 
template <typename T>
void DoublyLinkedList<T>::DeleteFromHead() {
	if (!head) return;
	Node<T>* temp = head;
	head = head->next;
	if (head) head->prev = nullptr;
	else tail = nullptr;
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {
	if (!tail) return;
	Node<T>* temp = tail;
	tail = tail->prev;
	if (tail) tail->next = nullptr;
	else head = nullptr;
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAll() {
	while (head) {
		DeleteFromHead();
	}
}

template <typename T>
void DoublyLinkedList<T>::Show() const {
	Node<T>* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}


int main() {
	DoublyLinkedList<int> list;

	list.AddToHead(10);
	list.AddToToil(20);
	list.AddToHead(5);

	std::cout << "list: ";
	list.Show();

	list.DeleteFromHead();
	std::cout << "List after deleting from head: ";
	list.Show();

	list.DeleteFromTail();
	std::cout << "List after deleting from toil: ";
	list.Show();

	list.DeleteAll();
	std::cout << "List after deleting all: ";
	list.Show();


	return 0;

}