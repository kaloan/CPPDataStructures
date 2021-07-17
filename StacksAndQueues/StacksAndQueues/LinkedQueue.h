#pragma once
#include "BasicLinkedDataStructure.h"
#include <iostream>
#include <fstream>
template<typename T>
class LinkedQueue : public BasicLinkedDataStructure<T>
{
protected:
	Node<T>* last;

	void copy(const LinkedQueue<T>& otherQueue) //O(otherQueue.len)
	{
		Node<T>* currOther = otherQueue.start;
		if (!currOther)
		{
			this->start = NULL;
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
	LinkedQueue() : BasicLinkedDataStructure<T>() //O(1)
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
			this->clear();
			copy(otherQueue);
		}
		return *this;
	}
	~LinkedQueue() {} //O(len)

	void push(const T& x) //O(1)
	{
		if (!this->start)
		{
			this->start = new Node<T>(x);
			last = this->start;
			return;
		}
		Node<T>* newEnd = new Node<T>(x);
		last->next = newEnd;
		last=newEnd;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const LinkedQueue& l) // O(len)
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
		out << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, LinkedQueue<T>& l) //O(1)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}

	friend std::ofstream& operator<<(std::ofstream& fOut, const LinkedQueue<T>& l)  // O(len)
	{															
		Node<T>* curr = l.start;
		while (curr)
		{
			fOut << curr->data;
			curr = curr->next;
		}
		delete curr; //Защото е NULL
		fOut << std::endl;
		return fOut;
	}
	friend std::ifstream& operator>>(std::ifstream& fIn, LinkedQueue<T>& l) //O(1)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};