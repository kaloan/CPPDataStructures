#pragma once
#include <iostream>
#include <fstream>

template <typename T>
struct DNode
{
	T data;
	DNode* prev;
	DNode* next;
	DNode(const T& info) : data(info)
	{
		prev = NULL;
		next = NULL;
	}
};

template <typename T>
class DoubleLinkedList
{
private:
	DNode<T> *start;
	DNode<T> *end;
	DNode<T> *currS;
	DNode<T> *currE;

	void clear();
	void copy(const DoubleLinkedList<T>&);

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList<T>&);
	DoubleLinkedList& operator= (const DoubleLinkedList<T>&);
	~DoubleLinkedList();

	void insertAtEnd(const T&);
	bool deleteThis(DNode<T>*, T &);
	void iterStart(DNode<T> *place = NULL);
	DNode<T>* iterNext();

	void iterEnd(DNode<T> *place = NULL);
	DNode<T>* iterPrev();
	int len() const;

	void print() const;
	void print_reverse() const;

	template<typename T>
	friend std::ostream& operator<<(std::ostream&, DoubleLinkedList<T>&);

	template<typename T>
	friend std::istream& operator>>(std::istream&, DoubleLinkedList<T>&);

	template<typename T>
	friend std::ofstream& operator<<(std::ofstream&, DoubleLinkedList<T>&);

	template<typename T>
	friend std::ifstream& operator>>(std::ifstream&, DoubleLinkedList<T>&);

	bool operator<(const DoubleLinkedList<T>&);
};

