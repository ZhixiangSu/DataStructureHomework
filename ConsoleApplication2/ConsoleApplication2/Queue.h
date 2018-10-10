#pragma once
#include"DoubleLinkedList.cpp"
template<class T>
class Queue:
	private DoubleLinkedList<T>
{
public:
	void push(T data);
	T front();
	bool isEmpty();
	void pop();
	int size();
private:
	int qsize = 0;
};

