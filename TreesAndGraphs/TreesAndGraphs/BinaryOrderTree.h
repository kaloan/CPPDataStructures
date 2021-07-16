#pragma once
template<typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template<typename T>
class BinaryOrderTree
{
	Node<T> *root;

	void deleteTree(Node<T> * &) const;
	void copy(Node<T> * &, const Node<T> * &);
	void copyTree(const BinaryOrderTree<T> &);

	void printFromNode(const Node<T> *) const;

	void add(Node<T> * &, const T &);

	int counter(Node<T>*) const;

public:
	BinaryOrderTree();
	~BinaryOrderTree();
	BinaryOrderTree(const BinaryOrderTree<T> &);
	BinaryOrderTree<T>& operator=(const BinaryOrderTree<T> &);

	void createWithData(T, BinaryOrderTree<T>, BinaryOrderTree<T>);
	void create();

	T getRootData() const;
	Node<T>* getRootPtr() const;

	BinaryOrderTree<T> leftTree() const;
	BinaryOrderTree<T> rightTree() const;

	bool empty() const;
	int size() const;
	void print() const;

	void addNode(const T &);
	void deleteNode(const T &);
	void deleteNodePtr(Node<T> * &, const T &);

	void minTree(T &, BinaryOrderTree<T> &) const;

	friend ostream& operator<<(ostream&, const BinaryOrderTree<T>&);
	friend istream& operator>>(istream&, BinaryOrderTree<T>&);
	friend ofstream& operator<<(ofstream&, const BinaryOrderTree<T>&);
	friend ifstream& operator>>(ifstream&, BinaryOrderTree<T>&);

	bool operator<(const BinaryOrderTree<T>&);
};