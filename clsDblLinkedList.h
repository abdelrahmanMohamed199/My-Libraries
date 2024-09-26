#pragma once
#include <iostream>

using namespace std;

template <class T> class clsDblLinkedList
{
public:

	class Node
	{
	public:

		T value;
		Node* next;
		Node* prev;
	};

	void InsertAtBegining(T value)
	{
		Node* newNode = new Node;

		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL)
		{
			// if the node has one or more nodes (not empty)
			head->prev = newNode;
		}
		head = newNode; // make the newNode is the new head of list
		_Size++;
	}

	void PrintList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}

	Node* Find(T value)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->value == value)
				return temp;
			temp = temp->next;
		}
		return NULL;
	}

	void InsertAfter(Node* nodeToInsertAfter, T value)
	{
		if (nodeToInsertAfter == NULL)
		{
			cout << "\nError node can not be null\n";
			return;
		}
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = nodeToInsertAfter->next;
		if (nodeToInsertAfter->next != NULL)
		{
			nodeToInsertAfter->next->prev = newNode;
		}
		nodeToInsertAfter->next = newNode;
		newNode->prev = nodeToInsertAfter;
		_Size++;
	}

	bool InsertAfter(int index, T value)
	{
		Node* current = GetNode(index);
		if (current != NULL)
		{
			InsertAfter(current, value);
			return true;
		}
		else
		{
			return false;
		}
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
			newNode->prev = NULL;
		}
		else
		{
			Node* lastNode = head;
			while (lastNode->next != NULL)
			{
				lastNode = lastNode->next;
			}
			lastNode->next = newNode;
			newNode->prev = lastNode;
		}
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete) {

		/*
			1-Set the next pointer of the previous node to the next pointer of the current node.
			2-Set the previous pointer of the next node to the previous pointer of the current node.
			3-Delete the current node.
		*/
		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL) {
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL) {
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		Node* temp = head;
		// check if list empty
		if (head == NULL)
		{
			return;
		}
		if (head->next != NULL)
		{
			head->next->prev = NULL;
		}
		head = temp->next;
		delete temp; // free from memory
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}

		Node* current = head;

		// if the list has only one node
		if (current->next == NULL)
		{
			head = NULL;
			delete current;
			return;
		}

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->prev->next = NULL;
		delete current;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return head == NULL;
	}

	void Clear()
	{
		while (head != NULL)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		while (head->next != NULL)
		{
			Swap(head->prev, head->next);
			head = head->prev;
		}
		Swap(head->prev, head->next);
	}

	Node* GetNode(int index)
	{
		if (index >= _Size || index < 0) //index is out of range
			return NULL;

		Node* result = head;
		int c = 0;
		while (result != NULL)
		{
			if (c == index)
				return result;
			result = result->next;
			c++;
		}
	}

	T GetItem(int index)
	{
		Node* N1 = GetNode(index);
		if (N1 != NULL)
			return N1->value;
		else
			return NULL;
	}

	bool UpdateItem(int index, T newValue)
	{
		Node* N1 = GetNode(index);
		if (N1 != NULL)
		{
			N1->value = newValue;
			return true;
		}
		else
		{
			return false;
		}
	}

protected:

	Node* head = NULL;
	int _Size = 0;

	void Swap(Node*& prev, Node*& next)
		{
			Node* temp = prev;
			prev = next;
			next = temp;
		}

};

