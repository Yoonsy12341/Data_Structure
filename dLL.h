#pragma once

struct Node {
	int data = NULL;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class doublyLinkedList {
public:
	doublyLinkedList();
	void at(int idx);
	bool empty();
	void append(int data);
	void insertion(int idx, int data);
	void deletion(int idx);
	void print();

private:
	Node* header;
	Node* trailer;
	int listSize;
};





