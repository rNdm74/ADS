#pragma once

template<class T>
ref class Node
{
public:
	Node();
	Node^ Next;
	T Data;
};

template<class T> Node<T>::Node()
{
};
