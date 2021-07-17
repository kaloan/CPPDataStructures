#pragma once
#include<iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node()
	{
		next = NULL;
	}
	Node(const T& sData) : data(sData)
	{
		next = NULL;
	}
};
template<typename T>
class LinkedList
{
private:
	Node<T>* start;
	Node<T>* end;
	Node<T>* curr;

	void copy(const LinkedList<T>&);
	void clear();
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	LinkedList<T>& operator=(const LinkedList<T>&);
	~LinkedList();

	void insertAtEnd(const T&);
	void insertAfter(Node<T>*, const T&);
	void insertBefore(Node<T>*, const T&);

	bool deleteThis(Node<T>*, T&);
	bool deleteAfter(Node<T>*, T&);
	bool deleteBefore(Node<T>*, T&);

	void iterStart(Node<T>* node = NULL);
	Node<T>* iter();
	int len() const;

	void print() const;

	friend std::ostream& operator<<(std::ostream&, LinkedList<T>&);
	friend std::istream& operator>>(std::istream&, LinkedList<T>&);
	friend std::ofstream& operator<<(std::ofstream&, LinkedList<T>&);
	friend std::ifstream& operator>>(std::ifstream&, LinkedList<T>&);

	bool operator<(const LinkedList<T>&);
};

