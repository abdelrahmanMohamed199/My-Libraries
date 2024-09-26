#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

template <class T> class clsMyQueue
{
protected:

	clsDblLinkedList<T> _MyList;

public:

	void push(T value)
	{		
		_MyList.InsertAtEnd(value);
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(_MyList.Size() - 1);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int index, T newValue)
	{
		_MyList.UpdateItem(index, newValue);
	}

	void InsertAfter(int index, T value)
	{
		_MyList.InsertAfter(index, value);
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBegining(value);
	}

	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

};

