#pragma once
#include"Node.h"
template<class T>
class DoubleLinkedList
{
public:
	void add(T data, bool toEnd);
	void add(T data, Node<T>* neighbor, bool toLeft);
	void delet(Node<T>* node); 
	Node<T>* search(T data);
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
};

