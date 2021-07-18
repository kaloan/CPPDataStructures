#pragma once
#include <iostream>
#include <fstream>

template <typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(const T& info) : data(info)
	{
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
	void copyBinaryTree(const BinaryTree&);

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
	void createWithData(const T&, const BinaryTree<T>&, const BinaryTree<T>&);

	int size() const;
	void insert(const T&);

	template<typename T>
	friend std::ostream& operator<<(std::ostream&, const BinaryTree<T>&);

	template<typename T>
	friend std::istream& operator>>(std::istream&, BinaryTree<T>&);

	template<typename T>
	friend std::ofstream& operator<<(std::ofstream&, const BinaryTree<T>&);

	template<typename T>
	friend std::ifstream& operator>>(std::ifstream&, BinaryTree<T>&);

	bool operator<(const BinaryTree<T>&);
};

