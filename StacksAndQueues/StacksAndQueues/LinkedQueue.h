#pragma once
#include "BasicLinkedDataStructure.h"
#include <iostream>
#include <fstream>
template<typename T>
class LinkedQueue : public BasicLinkedDataStructure<T>
{
protected:
	Node* last;

	void copy(const LinkedQueue<T>& otherQueue) //O(otherQueue.len)
	{
		Node<T>* currOther = otherQueue.start;
		if (!currOther)
		{
			start = NULL;
			last = NULL;
			return;
		}
		while (currOther)
		{
			push(currOther->data);
			currOther = currOther->next;
		}
	}


public:
	LinkedQueue() : BasicLinkedDataStructure() //O(1)
	{
		last = NULL;
	}
	LinkedQueue(const LinkedQueue<T>& otherQueue) //O(otherQueue.len)
	{
		copy(otherQueue);
	}
	LinkedQueue<T>& operator=(const LinkedQueue<T>& otherQueue)
	{
		if (this != &otherQueue)
		{
			clear();
			copy(otherQueue);
		}
		return *this;
	}
	~LinkedQueue() : ~BasicLinkedDataStructure() {} //O(len)

	void push(const T& x) //O(1)
	{
		if (!start)
		{
			start = new Node<T>(x);
			last = start;
			return;
		}
		Node<T>* newEnd = new Node(x);
		last->next = newEnd;
		last=newEnd;
	}
	
	friend ostream& operator<<(ostream& out, const LinkedQueue& l) // O(len)
	{
		if (l.empty())
		{
			out << "The queue is empty.";
			return out;
		}
		Node<T>* curr = l.start;
		while (curr)
		{
			out << curr->data<<" ";
			curr = curr->next;
		}
		delete curr; //Защото е NULL
		return out;
	}
	friend istream& operator>>(istream& in, const LinkedQueue<T>& l) //O(1)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}

	friend ofstream& operator<<(ofstream& fOut, const LinkedQueue<T>& l)  // O(len)
	{															
		Node<T>* curr = l.start;
		while (curr)
		{
			fOut << curr->data;
			curr = curr->next;
		}
		delete curr; //Защото е NULL
		return out;
	}
	friend ifstream& operator>>(ifstream& fIn, const LinkedQueue<T>& l) //O(1)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};