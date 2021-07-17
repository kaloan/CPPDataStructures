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
			this->start = NULL;
			return;
		}
		Node<T>* sDroppingTop = otherStack.start;
		Node<T>* thisDroppingTop = NULL;
		this->start = new Node<T>(sDroppingTop->data);
		//this->start->next = thisDroppingTop;
		thisDroppingTop = this->start;
		sDroppingTop = sDroppingTop->next;
		while (sDroppingTop)
		{
			Node<T>* oneStepDrop = new Node<T>(sDroppingTop->data);
			thisDroppingTop->next = oneStepDrop;
			thisDroppingTop = oneStepDrop;
			sDroppingTop = sDroppingTop->next;
		}
		//thisDroppingTop->next = NULL;
	}


public:
	LinkedStack() : BasicLinkedDataStructure<T>() {} //O(1)
	LinkedStack(const LinkedStack<T>& otherStack) //O(otherQueue.len)
	{
		copy(otherStack);
	}
	LinkedStack<T>& operator=(const LinkedStack<T>& otherStack)
	{
		if (this != &otherStack)
		{
			this->clear();
			copy(otherStack);
		}
		return *this;
	}
	~LinkedStack() {} //O(len)

	void push(const T& x) //O(1)
	{
		Node<T>* newStart = new Node<T>(x);
		newStart->next = this->start;
		this->start = newStart;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& l) // O(len)
	{
		if (l.empty())
		{
			out << "The stack is empty.";
			return out;
		}
		Node<T>* curr = l.start;
		while (curr)
		{
			out << curr->data << " ";
			curr = curr->next;
		}
		/*int arrSize = l.len();
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
		delete[] elements;*/
		delete curr; //Защото ще е NULL
		out << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, LinkedStack<T>& l) //О(1)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}
	friend std::ofstream& operator<<(std::ofstream& fOut, const LinkedStack<T>& l)//O(len)
	{
		Node<T>* curr = l.start;
		while (curr)
		{
			fOut << curr->data << " ";
			curr = curr->next;
		}
		/*int arrSize = l.len();
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
		delete[] elements;*/
		delete curr; //Защото ще е NULL
		fOut << std::endl;
		return fOut;
	}
	friend std::ifstream& operator>>(std::ifstream& fIn, LinkedStack<T>& l) //O(1)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};