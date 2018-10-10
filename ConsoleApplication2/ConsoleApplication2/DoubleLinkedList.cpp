#pragma once
#include "pch.h"
#include "DoubleLinkedList.h"
#include<iostream>
using namespace std;
template<class T>
void DoubleLinkedList<T>::add(T data, bool toEnd)
{
	if (first == nullptr && last == nullptr)
	{
		Node<T>* temp= new Node<T>();
		temp->data = data;
		first = last = temp;
	}
	else
	{
		if (toEnd)
		{
			add(data, last, true);
		}
		else
		{
			add(data, first, false);
		}
	}
}

template<class T>
void DoubleLinkedList<T>::add(T data, Node<T>* neighbor, bool toNext)
{
	Node<T>* temp = new Node<T>();
	temp->data = data;
	if (toNext)
	{
		neighbor->next = temp;
		temp->past = neighbor;
		if (neighbor == last)
		{
			last = temp;
		}
	}
	else
	{
		neighbor->past = temp;
		temp->next = neighbor;
		if (neighbor == first)
		{
			first = temp;
		}
	}
}

template<class T>
void DoubleLinkedList<T>::delet(Node<T> * node)
{
	if (node == first&&first== last)
	{
		first = last = nullptr;
	}
	else if (node == first)
	{
		first = first->next;
		first->past = nullptr;
	}
	else if (node == last)
	{
		last = last->past;
		last->next = nullptr;
	}
	else
	{
		Node<T>* temp1 = node->next;
		Node<T>* temp2= node->past;
		node->past->next = temp1;
		node->next->past = temp2;
	}
	delete node;
}

template<class T>
Node<T>* DoubleLinkedList<T>::search(T data)
{
	Node<T>* temp = first;
	if (temp == nullptr)
		return nullptr;
	while (temp != nullptr)
	{
		if (temp->data == data)
			return temp;
		temp = temp->next;
	} 
	return nullptr;
}
