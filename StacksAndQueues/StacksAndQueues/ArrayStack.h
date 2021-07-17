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
		T* newArr = new T[this->size + 100];
		for (int i = 0; i < this->start; i++)
		{
			newArr[i] = this->arr[i];
		}
		this->size += 100;
		delete[] this->arr;
		this->arr = newArr;
	}

	void copy(const ArrayStack<T>& other) //O(other.len)
	{
		if (other.empty())
		{
			this->start = -1;
			this->size = 0;
			this->arr = NULL;
		}
		this->size = other.len();
		this->start = other.start;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}


public:
	ArrayStack():BasicArrayDataStructure<T>(){}
	ArrayStack(const ArrayStack<T>& other) //O(other.len)
	{
		copy(other);
	}
	ArrayStack<T>& operator=(const ArrayStack<T>& otherStack) //O(otherStack.len)
	{
		if (this != &otherStack)
		{
			this->clear();
			copy(otherStack);
		}
		return *this;
	}
	~ArrayStack(){}

	void push(const T& x) //O(1), а ако трябва да се преоразмерява става О(len) 
	{
		if (!this->arr || len() == this->size) resize();
		this->arr[++this->start] = x;
	}
	T pop() //O(1)
	{
		if (this->empty())
		{
			std::cerr << "The stack is empty!" << std::endl;
			return T();
		}
		T res = this->arr[this->start--];
		return res;
	}

	int len() const //O(1)
	{
		return this->start + 1;
	}

	friend std::ostream& operator<<(std::ostream& out, const ArrayStack<T>& l) // O(len)
	{
		if (l.empty())
		{
			out << "The stack is empty.";
			return out;
		}
		for (int i = l.start; i >= 0; i--)
		{
			out << l.arr[i] << " ";
		}
		out << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const ArrayStack<T>& l) //О(1), а ако трябва да се преоразмерява става О(len)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}

	friend std::ofstream& operator<<(std::ofstream& fOut, const ArrayStack<T>& l) //O(len)
	{
		for (int i = l.start; i >= 0; i--)
		{
			fOut << l.arr[i];
		}
		fOut << std::endl;
		return fOut;
	}
	friend std::ifstream& operator>>(std::ifstream& fIn, const ArrayStack<T>& l) //O(1), а ако трябва да се преоразмерява става О(len)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};