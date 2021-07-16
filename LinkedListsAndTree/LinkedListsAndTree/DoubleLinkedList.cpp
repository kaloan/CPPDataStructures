#include "DoubleLinkedList.h"
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void DoubleLinkedList<T>::clear() //O(len)
{
	DNode<T>* mover;
	while (start) 
	{
		mover = start;
		start = start->next;
		delete mover;
	}
	end = NULL;
}

template<typename T>
void DoubleLinkedList<T>::copy(const DoubleLinkedList<T>& otherList) //О(otherList.len)
{
	start = NULL;
	end = NULL;
	if (otherList.start) 
	{
		DNode<T>* mover = otherList.start;
		while (mover) 
		{
			insertAtEnd(mover->data);
			mover = mover->next;
		}
	}
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() //O(1)
{
	start = NULL;
	end = NULL;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& otherList) //О(otherList.len)
{
	copy(otherList);
}

template<typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& otherList) //O(1) или О(len+otherList.len)
{
	if (this != &otherList) 
	{
		clear();
		copy(otherList);
	}
	return *this;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	clear();
}

template<typename T>
void DoubleLinkedList<T>::insertAtEnd(const T &info) //O(1)
{
	DNode<T> *newEnd = new DNode<T>(info);
	if (end) end->next = newEnd;
	else start = newEnd;
	newEnd->prev = end;
	end = newEnd;
}

template<typename T>
bool DoubleLinkedList<T>::deleteThis(DNode<T>* place, T &info) //O(1)
{
	if (!place) 
	{
		cerr << "No such place!";
		return false;
	}
	info = place->data;
	if (start == end) 
	{
		start = NULL;
		end = NULL;
	}
	else if (place == start) 
	{
		start = start->next;
		start->prev = NULL;
	}
	else if (place == end) 
	{
		end = place->prev;
		end->next = NULL;
	}
	else 
	{
		place->prev->next = place->next;
		place->next->prev = place->prev;
	}
	delete place;

	return true;
}

template<typename T>
void DoubleLinkedList<T>::iterStart(DNode<T>* place) //O(1)
{
	if (place) currS = place;
	else currS = start;
}

template<typename T>
DNode<T>* DoubleLinkedList<T>::iterNext() //O(1)
{
	DNode<T> *temp = currS;
	if (currS) currS = currS->next;
	return temp;
}

template<typename T>
void DoubleLinkedList<T>::iterEnd(DNode<T>* place) //O(1)
{
	if (place) currE = place;
	else currE = end;
}

template<typename T>
DNode<T>* DoubleLinkedList<T>::iterPrev() //O(1)
{
	DNode<T> *temp = currE;
	if (currE) currE = currE->prev;
	return temp;
}

template<typename T>
int DoubleLinkedList<T>::len() const //O(len)
{
	int n = 0;
	DNode<T>* mover = start;
	while (mover) 
	{
		n++;
		mover = mover->next;
	}
	return n;
}

template<typename T>
void DoubleLinkedList<T>::print() const //O(len)
{
	DNode<T>* mover = start;
	while (mover) 
	{
		cout << mover->data << " ";
		mover = mover->next;
	}
	cout << endl;
}

template<typename T>
void DoubleLinkedList<T>::print_reverse() const //O(len)
{
	DNode<T>* mover = end;
	while (mover)
	{
		cout << mover->data << " ";
		mover = mover->prev;
	}
	cout << endl;
}

template<typename T>
bool DoubleLinkedList<T>::operator<(const DoubleLinkedList<T>& otherList) //O(len+otherList.len)
{
	int a = len();
	int b = otherList.len();
	if (a < b) return true;
	return false;
}

template<typename T>
ostream & operator<<(ostream &output, DoubleLinkedList<T>& list) //O(1)
{
	DNode<T>* temp = list.iterNext();
	output << temp->data << " ";
	return output;
}

template<typename T>
istream & operator>>(istream &input, DoubleLinkedList<T>& list) //O(1)
{
	T info;
	input >> info;
	list.insertAtEnd(info);
	return input;
}

template<typename T>
ofstream & operator<<(ofstream &outFile, DoubleLinkedList<T>& list) //O(1)
{
	DNode<T>* temp = list.iter();
	outFile << temp->data << " ";
	return outFile;
}

template<typename T>
ifstream & operator>>(ifstream &inFile, DoubleLinkedList<T>& list) //O(1)
{
	T info;
	inFile >> info;
	list.insertAtEnd(info);
	return inFile;
}
