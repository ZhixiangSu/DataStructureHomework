#include "pch.h"
#include "Stack.h"


template<class T>
void Stack<T>::push(T data)
{
	DoubleLinkedList<T>::add(data, false);
	ssize++;
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (DoubleLinkedList<T>::first == nullptr&&DoubleLinkedList<T>::last == nullptr)
		return true;
	return false;
}

template<class T>
void Stack<T>::pop()
{
	DoubleLinkedList<T>::delet(DoubleLinkedList<T>::first);
	ssize--;
}

template<class T>
int Stack<T>::size()
{
	return ssize;
}
