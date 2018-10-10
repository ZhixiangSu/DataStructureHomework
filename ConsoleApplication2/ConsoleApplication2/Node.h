#pragma once
template<class T>
class Node {
public:
	Node* past = nullptr;
	Node* next = nullptr;
	T data;
};

