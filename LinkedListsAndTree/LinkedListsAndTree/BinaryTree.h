#pragma once
template <typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T info)
	{
		data = info;
		left = NULL;
		right = NULL;
	}
};
template <typename T>
class BinaryTree
{
private:
	Node<T> *root;

	void deleteBinaryTree(Node<T> * &) const;

	void copyFromNode(Node<T> * &, Node<T> * const &) const;
	void copyBinaryTree(const BinaryTree<T>&);

	void printFromNode(const Node<T> *) const;
	void createBinaryTree(Node<T> * &) const;
	
	int counter(Node<T>*) const;

	void insertHelper(Node<T>*&, const T&);
public:
	BinaryTree();
	BinaryTree(const BinaryTree<T>&);
	BinaryTree<T>& operator=(const BinaryTree<T>&);
	~BinaryTree();

	BinaryTree<T> leftBinaryTree() const;
	BinaryTree<T> rightBinaryTree() const;

	T getRootData() const;
	Node<T>* getRootPtr();

	bool empty() const;
	void print() const;

	void create();
	void createWithData(T, BinaryTree<T>, BinaryTree<T>);

	int size() const;
	void insert(const T&);

	friend ostream& operator<<(ostream&, const BinaryTree<T>&);
	friend istream& operator>>(istream&, BinaryTree<T>&);
	friend ofstream& operator<<(ofstream&, const BinaryTree<T>&);
	friend ifstream& operator>>(ifstream&, BinaryTree<T>&);

	bool operator<(const BinaryTree<T>&);
};

