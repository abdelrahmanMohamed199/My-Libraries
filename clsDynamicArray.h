#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T> class clsDynamicArray
{
protected:

	int _Size = 0;	
	T* _TempArray;

	void _Swap(T &value1, T &value2)
	{
		T temp = value1;
		value1 = value2;
		value2 = temp;
	}

public:

	T* OriginalArray;
	
	clsDynamicArray(int size = 0)
	{
		if (size < 0)
			size = 0;
		_Size = size;
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int index, T value)
	{
		if (index < _Size && index >= 0)
		{
			OriginalArray[index] = value;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}

	void Resize(int NewSize)
	{
		if (NewSize == _Size || NewSize < 0)
			return;
		
		if (NewSize < _Size)
			_Size = NewSize;

		_TempArray = new T[NewSize];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int index)
	{
		return OriginalArray[index];
	}

	void Reverse()
	{
		for (int i = 0; i < _Size / 2; i++)
		{
			_Swap(OriginalArray[i], OriginalArray[_Size - i - 1]);
		}
	}

	void Clear()
	{
		delete[] OriginalArray;
		_Size = 0;
		OriginalArray = new T[_Size];
	}

	bool DeleteItemAt(int index)
	{
		if (index < _Size && index >= 0)
		{
			_Size--;
			_TempArray = new T[_Size];
			for (int i = 0; i < index; i++)
			{
				_TempArray[i] = OriginalArray[i];
			}

			for (int i = index; i < _Size; i++)
			{
				_TempArray[i] = OriginalArray[i + 1];
			}
			
			delete[] OriginalArray;
			OriginalArray = _TempArray;
			return true;
		}
		else
		{
			return false;
		}
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T value)
	{
		int index = Find(value);
		return DeleteItemAt(index);
	}

	bool InsertAt(int index, T value)
	{
		if (index <= _Size && index >= 0)
		{
			_Size++;
			_TempArray = new T[_Size];

			for (int i = 0; i < index; i++)
				_TempArray[i] = OriginalArray[i];

			_TempArray[index] = value;

			for (int i = index + 1; i < _Size; i++)
				_TempArray[i] = OriginalArray[i - 1];

			delete[] OriginalArray;
			OriginalArray = _TempArray;
			return true;
		}
		else
		{
			return false;
		}
	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	bool InsertAfter(int index, T value)
	{
		return InsertAt(index + 1, value);
	}

	bool InsertBefore(int index, T value)
	{
		return InsertAt(index - 1, value);
	}

	void InsertAtEnd(T value)
	{
		InsertAt(_Size, value);
	}

};

