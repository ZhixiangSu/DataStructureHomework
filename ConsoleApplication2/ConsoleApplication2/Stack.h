#pragma once
#include "DoubleLinkedList.cpp"
template<class T>
class Stack:private DoubleLinkedList<T>
{
public:
	void push(T data);
	bool isEmpty();
	void pop();
	int size();
private:
	int ssize = 0;
};

