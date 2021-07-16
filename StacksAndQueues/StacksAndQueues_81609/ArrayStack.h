#pragma once
#include "BasicArrayDataStructure.h"
#include <iostream>
#include <fstream>
template <typename T>
class ArrayStack : public BasicArrayDataStructure<T>
{
protected:
	void resize() //O(len)
	{
		T* newArr = new T[size + 100];
		for (int i = 0; i < start; i++)
		{
			newArr[i] = arr[i];
		}
		size += 100;
		delete[] arr;
		arr = newArr;
	}

	void copy(const ArrayStack<T>& other) //O(other.len)
	{
		if (other.empty())
		{
			start = -1;
			size = 0;
			arr = NULL;
		}
		size = other.start + 1;
		start = other.start;
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}


public:
	ArrayStack():BasicArrayDataStructure(){}
	ArrayStack(const ArrayStack<T>& other) //O(other.len)
	{
		copy(other);
	}
	ArrayStack<T>& operator=(const ArrayStack<T>& otherStack) //O(otherStack.len)
	{
		if (this != &otherStack)
		{
			clear();
			copy(otherStack);
		}
		return *this;
	}
	~ArrayStack() : ~BasicArrayDataStructure(){}

	void push(const T& p) //O(1), а ако трябва да се преоразмерява става О(len) 
	{
		if (!arr||start+1==size) resize();
		arr[start++] = T;
	}
	T pop() //O(1)
	{
		if (empty())
		{
			cerr << "The stack is empty!";
			return T();
		}
		T res = arr[start];
		start--;
		return res;
	}

	int len() //O(1)
	{
		return start + 1;
	}

	friend ostream& operator<<(ostream& out, const ArrayStack<T>& l) // O(len)
	{
		if (l.empty())
		{
			out << "The stack is empty.";
			return out;
		}
		for (int i = start; i >= 0; i--)
		{
			out << arr[i] << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, const ArrayStack<T>& l) //О(1)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}

	friend ofstream& operator<<(ofstream& fOut, const ArrayStack<T>& l) //O(len)
	{
		for (int i = start; i >= 0; i--)
		{
			fOut << arr[i];
		}
		return fOut;
	}
	friend ifstream& operator>>(ifstream& fIn, const ArrayStack<T>& l) //O(1)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};