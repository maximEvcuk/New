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
	Node<T>* newNode = new(std::nothrow) Node<T>(value);
	if (!newNode) throw MemoryAllocationException();

	if (!head) {
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
	Node<T>* newNode = new(std::nothrow) Node<T>(value);
	if (!newNode) throw MemoryAllocationException();

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
void DoublyLinkedList<T>::InsertAt(T value, int position) {
	if (position < 0) return;

	if (position == 0) {
		AddToHead(value);
		return;
	}

	Node<T>* newNode = new(std::nothrow) Node<T>(value);
	if (!newNode) throw MemoryAllocationException();

	Node<T>* current = head;
	for (int i = 0; i < position && current != nullptr; ++i) {
		current = current->next;
	}

	if (current == nullptr) {
		AddToTail(value);
	}

	else {
		newNode->prev = current->prev;
		newNode->next = current;
		if (current->prev) {
			current->prev->next = newNode;
		}
		current->prev = newNode;

		if (newNode->prev == nullptr) {
			head = newNode;
		}
	}
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromHead() {
	if (!head) throw EmptyListException();
	Node<T>* temp = head;
	head = head->next;
	if (head) head->prev = nullptr;
	else tail = nullptr
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {
	if (!tail) throw EmptyListException();
	Node<T>* temp = tail;
	tail = tail->prev;
	if (tail) tail->next = nullptr;
	else head = nullptr;
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAt(int position) {
	if (position < 0) return;

	if (position == 0) {
		DeleteFromHead();
		return;
	}

	Node<T>* current = head;
	for (int i = 0; i < position && current != nullptr; ++i) {
		current = current->next;
	}

	if (current) {
		if (current->prev){
			current->prev->next = current->next;
	    }
		
		if (current->next) {
			current->next->prev = current->prev;
	    }

		if (current == tail) {
			tail = current->prev;
		}
		delete current;
	}
	
}

template <typename T>
void DoublyLinkedList<T>::DeleteAll() {
	while (head) {
		DeleteFromHead();
	}
}

template <typename T>
int DoublyLinkedList<T>::Search(T value) const{
	Node<T>* current = head;
	int position = 0;
	while (current) {
		if (current->data == value) {
			return position;
		}
		current = current->next;
		position++;
	}
	return -1;
}

template <typename T>
int DoublyLinkedList<T>::Replace(T oldValue, T newValue) {
	Node<T>* current = head;
	int count = 0;
	while (current) {
		if (current->data == oldValue) {
			current->data = newValue;
			count++;
		}
		current = current->next;
	}
	return count > 0 ? count : -1;
}

template <typename T>
void DoublyLinkedList<T>::Reverse() {
	Node<T>* current = head;
	Node<T>* temp = nullptr;
	tail = head;

	while (current){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp){
		head = temp->prev;
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
	try {
		DoublyLinkedList<int> list;

		list.AddToHead(10);
		list.AddToHead(20);
		list.AddToToil(30);
		list.InsertAt(15, 1);

		std::cout << "List after insertion: ";
		list.Show();
		 
		list.DeleteAt(1);
		std::cout << "List after deleting from position 1: ";
		list.Show();

		int pos = list.Search(20);
		std::cout << "Position of element 20: " << pos << std::endl;

		int replacedCount = list.Replace(20, 25);
		std::cout << "Number of replaced elements: " << replacedCount << std::endl;
		std::cout << "List of replacement: ";
		list.Show();

		list.Reverse();
		std::cout << "List after reversal: ";
		list.Show();

		list.DeleteAll();
		std::cout << "After deleting all: ";
		list.Show();
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}