#pragma once
template<typename T>
struct DNode
{
	T data;
	DNode* next;
	DNode* prev;
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

	friend ostream& operator<<(ostream&, DoubleCircularList<T>&);
	friend istream& operator>>(istream&, DoubleCircularList<T>&);
	friend ofstream& operator<<(ofstream&, DoubleCircularList<T>&);
	friend ifstream& operator>>(ifstream&, DoubleCircularList<T>&);

	bool operator<(const DoubleCircularList<T>&);
};

