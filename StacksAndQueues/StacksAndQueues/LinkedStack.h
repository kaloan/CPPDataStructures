#pragma once
#include "BasicLinkedDataStructure.h"
#include <iostream>
#include <fstream>
template <typename T>
class LinkedStack : public BasicLinkedDataStructure<T>
{
protected:
	void copy(const LinkedStack<T>& otherStack) //O(otherStack.len)
	{
		if (!otherStack.start)
		{
			top = NULL;
			return;
		}
		Node<T>* sDroppingTop = otherStack.start;
		Node<T>* thisDroppingTop = NULL;
		start = new Node<T>(sDroppingTop->data);
		start->next = thisDroppingTop;
		thisDroppingTop = start;
		sDroppingTop = sDroppingTop->previous;
		while (sDroppingtop)
		{
			Node<T>* oneStepDrop = new Node<T>(sDroppingTop->data);
			thisDroppingTop->next = oneStepDrop;
			thisDroppingTop = oneStepDrop;
			sDroppingTop = sDroppingTop->next;
		}
		thisDroppingTop->next = NULL;
	}


public:
	LinkedStack() : BasicLinkedDataStructure() {} //O(1)
	LinkedStack(const LinkedStack<T>& otherStack) //O(otherQueue.len)
	{
		copy(otherStack);
	}
	LinkedStack<T>& operator=(const LinkedStack<T>& otherStack)
	{
		if (this != &otherStack)
		{
			clear();
			copy(otherStack);
		}
		return *this;
	}
	~LinkedStack() : ~BasicLinkedDataStructure() {} //O(len)

	void push(const T& x) //O(1)
	{
		Node<T>* newStart = new Node(x);
		newStart->next = start;
		start = newStart;
	}
	
	friend ostream& operator<<(ostream& out, const LinkedStack<T>& l) // O(len)
	{
		if (l.empty())
		{
			out << "The stack is empty.";
			return out;
		}
		Node<T>* curr = l.start;
		int arrSize = l.len();
		T* elements = new T[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			elements[i] = curr.data;
			curr = curr->next;
		}
		for (int i = arrSize - 1; i > -1; i--) //Защото сме записали наобратно
		{
			out << elements[i] << " ";
		}
		delete[] elements;
		delete curr; //Защото ще е NULL
		return out;
	}
	friend istream& operator>>(istream& in, const LinkedStack<T>& l) //О(1)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}
	friend ofstream& operator<<(ofstream& fOut, const LinkedStack<T>& l)//O(len)
	{
		Node<T>* curr = l.start;
		int arrSize = l.len();
		T* elements = new T[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			elements[i] = curr.data;
			curr = curr->next;
		}
		for (int i = arrSize - 1; i > -1; i--) //Защото сме записали наобратно
		{
			fOut << elements[i];
		}
		delete[] elements;
		delete curr; //Защото ще е NULL
		return fOut;
	}
	friend ifstream& operator>>(ifstream& fIn, const LinkedStack<T>& l) //O(1)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};