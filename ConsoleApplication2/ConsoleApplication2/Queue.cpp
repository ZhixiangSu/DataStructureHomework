#pragma once
#include "pch.h"
#include "Queue.h"
template<class T>
void Queue<T>::push(T data)
{
	DoubleLinkedList<T>::add(data, true);
	qsize++;
}

template<class T>
T Queue<T>::front()
{
	return DoubleLinkedList<T>::first.data;
}

template<class T>
bool Queue<T>::isEmpty()
{
	if (DoubleLinkedList<T>::first == nullptr&&DoubleLinkedList<T>::last == nullptr)
		return true;
	return false;
}

template<class T>
void Queue<T>::pop()
{
	DoubleLinkedList<T>::delet(DoubleLinkedList<T>::first);
	qsize--;
}

template<class T>
int Queue<T>::size()
{
	return qsize;
}
