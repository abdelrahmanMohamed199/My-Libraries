#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T> class clsMyQueueArr
{
protected:

	clsDynamicArray<T> _MyArray;

public:

	void push(T value)
	{
		_MyArray.InsertAtEnd(value);
	}

	void Print()
	{
		_MyArray.PrintList();
	}

	int Size()
	{
		return _MyArray.Size();
	}

	T front()
	{
		return _MyArray.GetItem(0);
	}

	T back()
	{
		return _MyArray.GetItem(_MyArray.Size() - 1);
	}

	void pop()
	{
		_MyArray.DeleteFirstItem();
	}

	bool IsEmpty()
	{
		return _MyArray.IsEmpty();
	}

	T GetItem(int index)
	{
		return _MyArray.GetItem(index);
	}

	void Reverse()
	{
		_MyArray.Reverse();
	}

	void UpdateItem(int index, T newValue)
	{
		_MyArray.SetItem(index, newValue);
	}

	void InsertAfter(int index, T value)
	{
		_MyArray.InsertAfter(index, value);
	}

	void InsertAtFront(T value)
	{
		_MyArray.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_MyArray.InsertAtEnd(value);
	}

	void Clear()
	{
		_MyArray.Clear();
	}


};

