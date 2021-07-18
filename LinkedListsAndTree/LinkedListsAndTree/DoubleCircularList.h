#pragma once
#include<iostream>
#include <fstream>

template<typename T>
struct DNode
{
	T data;
	DNode* next;
	DNode* prev;
	DNode(const T& info) : data(info)
	{
		next = NULL;
		prev = NULL;
	}
};

template<typename T>
class DoubleCircularList
{
private:
	DNode<T>* start;
	DNode<T>* curr;

	void clear();
	void copy(const DoubleCircularList<T>&);
public:
	DoubleCircularList();
	DoubleCircularList(const DoubleCircularList<T>&);
	DoubleCircularList<T>& operator= (const DoubleCircularList<T>&);
	~DoubleCircularList();

	void iterStart(DNode<T> *place = NULL);
	DNode<T> * iter();

	void insertAtStart(const T&);
	bool deleteThis(DNode<T> *, T &);

	int len() const;

	void print() const;

	template<typename T>
	friend std::ostream& operator<<(std::ostream&, const DoubleCircularList<T>&);

	template<typename T>
	friend std::istream& operator>>(std::istream&, DoubleCircularList<T>&);

	template<typename T>
	friend std::ofstream& operator<<(std::ofstream&, const DoubleCircularList<T>&);

	template<typename T>
	friend std::ifstream& operator>>(std::ifstream&, DoubleCircularList<T>&);

	bool operator<(const DoubleCircularList<T>&);
};

