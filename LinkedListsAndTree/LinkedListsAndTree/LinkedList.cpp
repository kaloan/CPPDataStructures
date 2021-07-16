#include "LinkedList.h"
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void LinkedList<T>::copy(const LinkedList<T>& otherList) //O(otherList.len)
{
	start = NULL;
	end = NULL;
	if (otherList.start) 
	{
		Node<T>* mover = otherList.start;
		while (mover) 
		{
			insertAtEnd(mover->data);
			mover = mover->next;
		}
	}
}

template<typename T>
void LinkedList<T>::clear() //O(len)
{
	Node<T>* mover;
	while (start) 
	{
		mover = start;
		start = start->next;
		delete mover;
	}
	end = NULL;
}

template <typename T>
LinkedList<T>::LinkedList() //O(1)
{
	start = NULL;
	end = NULL;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) //O(otherList.len)
{
	copy(otherList);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& otherList) //O(1) или О(len+otherList.len)
{
	if (this != &otherList)
	{
		clear();
		copy(otherList);
	}
	return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() //O(len)
{
	clear();
}

template<typename T>
void LinkedList<T>::insertAtEnd(const T &info) //O(1)
{
	Node<T>* newEnd = new Node<T>(info);
	if (end) end->next = newElemPtr;
	else start = newElemPtr;
	end = newElemPtr;
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T>* place, const T &info) //O(1)
{
	if (!place) 
	{
		cerr << "No such place!";
		return;
	}
	Node<T>* newNode = new Node<T>(info);
	if (place == end) end = newNode;
	place->next = newNode;
}

template<typename T>
void LinkedList<T>::insertBefore(Node<T>* place, const T &info) //O(1)
{
	if (!place) 
	{
		cerr << "No such place!";
		return;
	}
	Node<T> *newNode = new Node<T>;
	*newNode = *place;
	if (place == end) end = newNode;
	place->data = info;
	place->next = newNode;
}

template<typename T>
bool LinkedList<T>::deleteThis(Node<T>* place,T &info) //O(1) или О(len)
{
	if (!place) 
	{
		cerr << "Nothing to delete!";
		return false;
	}
	if (place == start) 
	{
		info = place->data;
		if (start == end) start = end = NULL;
		else start = start->next;
		delete place;
	}
	else 
	{
		Node<T>* prevNode = start;
		while (prevNode->next != place) 
		{
			prevNode = prevNode->next;
		}
		deleteAfter(prevNode, info);
	}
	return true;
}

template<typename T>
bool LinkedList<T>::deleteAfter(Node<T>* place,T &info) //O(1)
{
	if (!place || !place->next) 
	{
		cerr << "Nothing to delete!";
		return false;
	}

	Node<T>* toDel = place->next;
	info = toDel->data;
	place->next = toDel->next;

	if (toDel == end) end = place;
	delete toDel;
	return true;
}

template<typename T>
bool LinkedList<T>::deleteBefore(Node<T>* place,T &info) //O(1) или O(len)
{
	if (!place || place == start) 
	{
		cerr << "Nothing to delete!";
		return false;
	}
	Node<T>* prevNode = start;
	while (prevNode->next != place) 
	{
		prevNode = prevNode->next;
	}
	deleteThis(prevNode, info);
	return true;
}

template<typename T>
void LinkedList<T>::iterStart(Node<T>* place) //O(1)
{
	if (place) curr = place;
	else curr = start;
}

template<typename T>
Node<T>* LinkedList<T>::iter() //O(1)
{
	Node<T>* temp = curr;
	if (curr) curr = curr->next;
	return temp;
}

template<typename T>
int LinkedList<T>::len() const //O(len)
{
	int n = 0;
	Node<T>* mover = start;
	while (mover) 
	{
		n++;
		mover = mover->next;
	}
	return n;
}

template<typename T>
void LinkedList<T>::print() const //O(len)
{
	Node<T>* mover = start;
	while (mover) 
	{
		cout << mover->data << " ";
		mover = mover->next;
	}
	cout << endl;
}

template<typename T>
bool LinkedList<T>::operator<(const LinkedList<T>& otherList) //O(len+otherList.len)
{
	int a = len();
	int b = otherList.len();
	if (a < b) return true;
	return false;
}

template <typename T>
ostream & operator<<(ostream &output, LinkedList<T>& list) //O(1)
{
	Node<T>* temp = list.iter();
	output << temp->data << " ";
	return output;
}

template<typename T>
istream & operator>>(istream &input, LinkedList<T>& list) //O(1)
{
	T info;
	input >> info;
	list.insertAtEnd(info);
	return input;
}

template<typename T>
ofstream & operator<<(ofstream &outFile, LinkedList<T>& list) //O(1)
{
	Node<T>* temp = list.iter();
	outFile << temp->data << " ";
	return outFile;
}

template<typename T>
ifstream & operator>>(ifstream &inFile, LinkedList<T>& list) //O(1)
{
	T info;
	inFile >> info;
	list.insertAtEnd(info);
	return inFile;
}
