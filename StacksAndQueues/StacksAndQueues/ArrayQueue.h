#pragma once
#include "BasicArrayDataStructure.h"
#include <iostream>
#include <fstream>
template <typename T>
class ArrayQueue : public BasicArrayDataStructure<T>
{
protected:
	int last;

	void resize() //O(len)
	{
		T* temp = arr;
		arr = new T[size + 100];
		int j = 0;
		if (last >= start)
		{
			for (int i = start; i <= last; i++)
			{
				arr[j++] = temp[i];
			}
			last = j;
		}
		else
		{
			for (int i = start; i < size; i++)
			{
				arr[j++] = temp[i];
			}
			for (int i = 0; i <= last; i++)
			{
				arr[j++] = temp[i];
			}
			last = j;
		}
		size += 100;
		delete[] temp;
	}
	void copy(const ArrayQueue<T>& other) //O(other.len)
	{
		if (other.empty())
		{
			last = -1;
			start = -1;
			arr = NULL;
			size = 0;
			return;
		}
		size = other.len();
		arr = new T[size];
		start = 0;
		int j = 0;
		if (other.last >= other.start)
		{
			for (int i = other.start; i <= other.last; i++)
			{
				arr[j++] = other[i];
			}
			last = j;
		}
		else
		{
			for (int i = other.start; i < other.size; i++)
			{
				arr[j++] = other[i];
			}
			for (int i = 0; i <= other.last; i++)
			{
				arr[j++] = other[i];
			}
			last = j;
		}
	}
public:
	ArrayQueue() : BasicArrayDataStructure() 
	{
		last = -1;
	}
	ArrayQueue(const ArrayQueue<T>& other) //O(other.len)
	{
		copy(other);
	}
	ArrayQueue<T>& operator=(const ArrayQueue<T>& otherQueue) //O(otherQueue.len)
	{
		if (this != &otherQueue)
		{
			clear();
			copy(otherQueue);
		}
		return *this;
	}
	~ArrayQueue() : ~BasicArrayDataStructure() {} // O(len)

	void push(const T& p) //O(1), а ако трябва да се преоразмерява става О(len) 
	{
		if (!arr || arr.len() == size) resize();
		if (start == -1) start = 0;
		arr[last] = x;
		last++;
		last = last % size;
	}
	T pop() //O(1)
	{
		if (empty())
		{
			cerr << "The Queue is empty!";
			return T();
		}
		T x = arr[start];
		start++;
		start = start % size;
		return x;
	}

	int len() //O(1)
	{
		if (last >= start)
		{
			return last - start+1;
		}
		int fPart = size - start + 1;
		int sPart = last + 1;
		return fPart + sPart;
	}

	friend ostream& operator<<(ostream& out, const ArrayQueue<T>& a) // O(len)
	{
		if (a.empty())
		{
			out << "The queue is empty.";
			return out;
		}
		if (a.last >= a.start) {
			for (int i = start; i <= last; i++)
			{
				out << a.arr[i] << " ";
			}
			return out;
		}
		for (int i = a.start; i < a.size; i++)
		{
			out << a.arr[i] << " ";
		}
		for (int i = 0; i <= a.last; i++)
		{
			out << a.arr[i] << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, const ArrayQueue<T>& l) //О(1)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}

	friend ofstream& operator<<(ofstream& fOut, const ArrayQueue<T>& a) //O(len)
	{
		if (a.last >= a.start) {
			for (int i = a.start; i <= a.last; i++)
			{
				fOut << a.arr[i];
			}
			return fOut;
		}
		else
		{
			for (int i = a.start; i < a.size; i++)
			{
				fOut << a.arr[i] << " ";
			}
			for (int i = 0; i <= a.last; i++)
			{
				fOut << a.arr[i] << " ";
			}
			return a.out;
		}
	}
	friend ifstream& operator>>(ifstream& fIn, const ArrayQueue<T>& l) //O(1)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};