#pragma once
#include "Node.h"
template<class Type>
class LinkedListIterator
{
	NodeType<Type> *current;
public:
	//Assigns current = null
	LinkedListIterator()
	{
		current = NULL;
	}
	//Assigns current = ptr
	LinkedListIterator(NodeType<Type> *ptr)
	{
		current = ptr;
	}
	//Overloads derefrence operator and returns info contained within node
	Type& operator*()
	{
		return current->info;
	}
	//Overloads pre-increment operator and the iterator is advanced to next node
	LinkedListIterator<Type>operator++()
	{
		current = current->link;
		return *this;
	}
	//Overloads equality operator and returns true if iterator is equal to the iterator specified by right otherwise return false
	bool operator==(const LinkedListIterator<Type>& right) const
	{
		return current == right.current;
	}
	//Overloads inequality operator and returns true if iterator is not queal
	bool operator!=(const LinkedListIterator<Type>& right) const
	{
		return current != right.current;
	}
};

