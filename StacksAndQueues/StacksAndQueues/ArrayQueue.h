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
		T* temp = this->arr;
		this->arr = new T[this->size + 100];
		if (temp)
		{
			int j = 0;
			if (last >= this->start)
			{
				for (int i = this->start; i <= last; i++)
				{
					this->arr[j++] = temp[i];
				}
				last = j - 1;
			}
			else
			{
				for (int i = this->start; i < this->size; i++)
				{
					this->arr[j++] = temp[i];
				}
				for (int i = 0; i <= last; i++)
				{
					this->arr[j++] = temp[i];
				}
				last = j - 1;
			}
			this->start = 0;
		}
		this->size += 100;
		delete[] temp;
	}
	void copy(const ArrayQueue<T>& other) //O(other.len)
	{
		if (other.empty())
		{
			last = -1;
			this->start = -1;
			this->arr = NULL;
			this->size = 0;
			return;
		}
		this->size = other.len();
		this->arr = new T[this->size];
		this->start = 0;
		int j = 0;
		if (other.last >= other.start)
		{
			for (int i = other.start; i <= other.last; i++)
			{
				this->arr[j++] = other.arr[i];
			}
			last = j - 1;
		}
		else
		{
			for (int i = other.start; i < other.size; i++)
			{
				this->arr[j++] = other.arr[i];
			}
			for (int i = 0; i <= other.last; i++)
			{
				this->arr[j++] = other.arr[i];
			}
			last = j - 1;
		}
	}
public:
	ArrayQueue() : BasicArrayDataStructure<T>() 
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
			this->clear();
			copy(otherQueue);
		}
		return *this;
	}
	~ArrayQueue(){} // O(len)

	void push(const T& x) //O(1), а ако трябва да се преоразмерява става О(len) 
	{
		if (!this->arr || len() == this->size) resize();
		if (this->start == -1) this->start = 0;
		this->arr[++last] = x;
		last = last % this->size;
	}
	T pop() //O(1)
	{
		if (this->empty())
		{
			std::cerr << "The Queue is empty!" << std::endl;
			return T();
		}
		T x = this->arr[this->start];
		this->start++;
		this->start = this->start % this->size;
		return x;

	}

	int len() const //O(1)
	{
		if (last >= this->start)
		{
			return last - this->start + 1;
		}
		int fPart = this->size - this->start + 1;
		int sPart = last + 1;
		return fPart + sPart;
	}

	friend std::ostream& operator<<(std::ostream& out, const ArrayQueue<T>& a) // O(len)
	{
		if (a.empty())
		{
			out << "The queue is empty." << std::endl;
			return out;
		}
		if (a.last >= a.start) 
		{
			for (int i = a.start; i <= a.last; i++)
			{
				out << a.arr[i] << " ";
			}
		}
		else 
		{
			for (int i = a.start; i < a.size; i++)
			{
				out << a.arr[i] << " ";
			}
			for (int i = 0; i <= a.last; i++)
			{
				out << a.arr[i] << " ";
			}
		}	
		out << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const ArrayQueue<T>& l) //О(1), а ако трябва да се преоразмерява става О(len)
	{
		T what;
		in >> what;
		l.push(what);
		return in;
	}

	friend std::ofstream& operator<<(std::ofstream& fOut, const ArrayQueue<T>& a) //O(len)
	{
		if (a.last >= a.start)
		{
			for (int i = a.start; i <= a.last; i++)
			{
				fOut << a.arr[i];
			}
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
		fOut << std::endl;
		return fOut;
	}
	friend std::ifstream& operator>>(std::ifstream& fIn, const ArrayQueue<T>& l) //O(1), а ако трябва да се преоразмерява става О(len)
	{
		T what;
		fIn >> what;
		l.push(what);
		return fIn;
	}
};