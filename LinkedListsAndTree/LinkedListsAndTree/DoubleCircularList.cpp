#include "DoubleCircularList.h"
#include <iostream>
#include <fstream>
using namespace std;


template<typename T>
void DoubleCircularList<T>::clear() //O(len)
{
	/*
	DNode<T>* mover;
	while (start)
	{
		mover = start;
		start = start->next;
		delete mover;
	}
	start = NULL;
	*/
	if (!start) return;

	DNode<T>* mover = start->next;

	while (mover != start)
	{
		mover->next = start->next;
		delete start;
		start = mover->next;
	}

	if (mover == start)
	{
		delete start;
		start = NULL;
	}
}

template<typename T>
void DoubleCircularList<T>::copy(const DoubleCircularList<T>& otherList) //O(otherList.len)
{
	start = NULL;
	DNode<T>* anchor = otherList.start;
	if (anchor)
	{
		DNode<T>* mover = anchor->prev;
		do
		{
			insertAtStart(mover->data);
			mover = mover->prev;
		} while (mover != anchor->prev);
	}
}

template<typename T>
DoubleCircularList<T>::DoubleCircularList() //O(1)
{
	start = NULL;
}

template<typename T>
DoubleCircularList<T>::DoubleCircularList(const DoubleCircularList<T>& otherList) //O(otherList.len)
{
	copy(otherList);
}

template<typename T>
DoubleCircularList<T>& DoubleCircularList<T>::operator=(const DoubleCircularList<T>& otherList) //O(1) или О(len+otherList.len)
{
	if (this != &otherList)
	{
		clear();
		copy(otherList);
	}
	return *this;
}

template<typename T>
DoubleCircularList<T>::~DoubleCircularList() //O(len)
{
	clear();
}

template<typename T>
void DoubleCircularList<T>::iterStart(DNode<T>* place) //O(1)
{
	if (place) curr = place;
	else curr = start;
}

template<typename T>
DNode<T>* DoubleCircularList<T>::iter() //O(1)
{
	if (!curr) return NULL;

	DNode<T> *temp = curr;
	curr = curr->next;
	//if (curr == start) curr = NULL;
	//else if (curr) curr = curr->next;

	return temp;
}

template<typename T>
void DoubleCircularList<T>::insertAtStart(const T &info) //O(1)
{
	DNode<T> *newStart = new DNode<T>(info);
	if (start)
	{
		newStart->prev = start->prev;
		newStart->next = start;
		start->prev->next = newStart;
		start->prev = newStart;
		start = newStart;
	}
	else
	{
		start = newStart;
		start->next = newStart;
		start->prev = newStart;
	}
}

template<typename T>
bool DoubleCircularList<T>::deleteThis(DNode<T>* place, T &info) //O(1)
{
	if (!place) 
	{
		cerr << "No such place!";
		return false;
	}
	info = place->data;
	/*if (start == start->next) 
	{
		start = NULL;
		delete place;
		return true;
	}*/

	DNode<T> *oneBefore = place->prev;
	oneBefore->next = place->next;
	place->next->prev = oneBefore;

	if (place == start) start = start->next;
	delete place;
	return true;
}

template<typename T>
int DoubleCircularList<T>::len() const //O(len)
{
	int n = 0;
	DNode<T>* anchor = start;
	if (anchor)
	{
		DNode<T>* mover = anchor;
		do
		{
			n++;
			mover = mover->next;
		} while (mover != anchor);
	}
	return n;
}

template<typename T>
void DoubleCircularList<T>::print() const //O(len)
{
	DNode<T>* anchor = start;
	if (anchor)
	{
		DNode<T>* mover = anchor;
		do 
		{
			cout << mover->data << " ";
			mover = mover->next;
		} while (mover != anchor);
	}
	cout << endl;
}

template<typename T>
bool DoubleCircularList<T>::operator<(const DoubleCircularList<T>& otherList) //O(len+otherList.len)
{
	int a = len();
	int b = otherList.len();
	if (a < b) return true;
	return false;
}

template<typename T>
ostream & operator<<(ostream &output, DoubleCircularList<T>& list) //O(1)
{
	DNode<T>* temp = list.iter();
	if (temp) output << temp->data << " ";
	return output;
}

template<typename T>
istream & operator>>(istream &input, DoubleCircularList<T>& list) //O(1)
{
	T info;
	input >> info;
	list.insertAtStart(info);
	return input;
}

template<typename T>
ofstream & operator<<(ofstream &outFile, DoubleCircularList<T>& list) //O(1)
{
	DNode<T>* temp = list.iter();
	if (temp) outFile << temp->data << " ";
	return outFile;
}

template<typename T>
ifstream & operator>>(ifstream &inFile, DoubleCircularList<T>& list) //O(1)
{
	T info;
	inFile >> info;
	list.insertAtStart(info);
	return inFile;
}
