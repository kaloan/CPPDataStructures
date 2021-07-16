#pragma once
template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(T const& d) :data(d) //O(1)
	{
		next = NULL;
	}
	Node():data() //O(1)
	{
		next = NULL;
	}
};

template <typename T>
class BasicLinkedDataStructure
{
protected:
	Node<T>* start;


public:
	BasicLinkedDataStructure() //O(1)
	{
		start = NULL;
	}
	~BasicLinkedDataStructure() //O(len)
	{
		clear();
	}

	void clear() //O(len)
	{
		Node<T>* curr = start;
		while (curr)
		{
			Node<T>* temp = curr->next;
			delete curr;
			curr = temp;
		}
	}

	virtual void push(const T&) = 0;
	T pop() //O(1)
	{
		if (!start)
		{
			cerr << "Empty Structure!" << endl;
			return T();
		}
		Node<T>* temp = start;
		start = start->next;
		T result = temp->data;
		delete temp;
		return result;
	}

	bool empty() //O(1)
	{
		if (!start) return true;
		return false;
	}
	int len() //O(len)
	{
		Node<T>* curr = start;
		int counter=0;
		while (curr)
		{
			counter++;
			curr = curr->next;
		}
		return counter;
	}

	bool operator<(BasicLinkedDataStructure const &other) // O(len) (заради извикванията на len())
	{
		if (len() < other.len()) return true;
		return false;
	}
};