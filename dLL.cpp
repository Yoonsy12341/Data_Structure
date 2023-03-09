//#include <iostream>
//#include "dLL.h"
//
//doublyLinkedList::doublyLinkedList() {
//	header = new Node;
//	trailer = new Node;
//
//	header->next = trailer;
//	trailer->prev = header;
//
//	listSize = 0;
//}
//
//bool doublyLinkedList::empty() {
//	if (header->next == trailer && trailer->prev == header) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void doublyLinkedList::append(int data) {
//	Node* newNode = new Node;
//	newNode->data = data;
//
//	newNode->prev = trailer->prev;
//	newNode->next = trailer;
//
//	trailer->prev->next = newNode;
//	trailer->prev = newNode;
//
//	listSize++;
//}
//
//void doublyLinkedList::insertion(Node* p, int data) { // p ¾Õ¿¡ »ðÀÔ
//	Node* v = new Node;
//	v->data = data;
//	
//	v->prev = p->prev;
//	p->prev->next = v;
//
//	p->prev = v;
//	v->next = p;
//
//	listSize++;
//}
//
//void doublyLinkedList::deletion(Node* _node) {
//	_node->prev->next = _node->next;
//	_node->next->prev = _node->prev;
//	delete _node;
//	listSize--;
//}
//
//void doublyLinkedList::print() {
//	Node* curNode = header->next;
//	for (int i = 0; i < listSize; i++) {
//		std::cout << curNode->data << " ";
//		curNode = curNode->next;
//	}
//	std::cout << std::endl;
//}

#include <iostream>
#include "dLL.h"
using namespace std;

doublyLinkedList::doublyLinkedList() {
	header = new Node;
	trailer = new Node;

	header->next = trailer;
	trailer->prev = header;
	listSize = 0;
}

void doublyLinkedList::at(int idx) {
	Node* curNode = header->next;
	for (int i = 0; i < idx; i++) {
		curNode = curNode->next;
	}
	cout << curNode->data << endl;

}

bool doublyLinkedList::empty() {
	if (listSize == 0) {
		return true;
	}
	else
		return false;
}

void doublyLinkedList::append(int data) {
	Node* newNode = new Node;
	newNode->data = data;

	if (empty()) {
		header->next = newNode;
		newNode->prev = header;

		newNode->next = trailer;
		trailer->prev = newNode;
	}
	else {
		trailer-> prev->next = newNode;
		newNode->prev = trailer->prev;

		newNode->next = trailer;
		trailer->prev = newNode;
	}
	listSize++;
}

void doublyLinkedList::insertion(int idx, int data) {
	if (idx < 0 || idx > listSize) {
		return;
	}
	else if (idx == listSize) {
		append(data);
	}
	else if (idx == 0) {
		Node* newNode = new Node;
		newNode->data = data;
		
		newNode->next = header->next;
		header->next->prev = newNode;

		newNode->prev = header;
		header->next = newNode;
		
		listSize++;
	}
	else {
		Node* newNode = new Node;
		newNode->data = data;

		Node* curNode = header->next;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}

		newNode->next = curNode;
		newNode->prev = curNode->prev;

		curNode->prev->next = newNode;
		curNode->prev = newNode;

		listSize++;
	}
}

void doublyLinkedList::deletion(int idx) {
	if (empty() || idx < 0 || idx > listSize) {
		return;
	}

	Node* curNode = header->next;
	if (idx == 0) {
		if (listSize == 1) {
			header->next = trailer = nullptr;
		}
		else {
			header->next = curNode->next;
			curNode->prev = nullptr;

			curNode->next->prev = header;
			curNode->next = nullptr;
		}
	}
	else {
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		curNode->next->prev = curNode->prev;
		curNode->prev->next = curNode->next;

		curNode->next = nullptr;
		curNode->prev = nullptr;
	}
	delete curNode;
	listSize--;
}

void doublyLinkedList::print() {
	if (empty()) {
		cout << "empty";
	}
	Node* curNode = header->next;
	while (curNode != trailer) {
		cout << curNode->data << " ";
		curNode = curNode->next;
	}
	cout << endl;
}






