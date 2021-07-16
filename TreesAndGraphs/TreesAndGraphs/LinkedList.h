#pragma once
#pragma once
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node(T sData)
	{
		data = sData;
		next = NULL;
	}
};
template<typename T>
class LinkedList
{
private:
	Node* start;
	Node* end;
	Node* curr;

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

	friend ostream& operator<<(ostream&,LinkedList<T>&);
	friend istream& operator>>(istream&, LinkedList<T>&);
	friend ofstream& operator<<(ofstream&, LinkedList<T>&);
	friend ifstream& operator>>(ifstream&, LinkedList<T>&);

	bool operator<(const LinkedList<T>&);
};

