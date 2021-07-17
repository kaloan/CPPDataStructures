#pragma once
#include <iostream>
#include <fstream>

template <typename T>
struct Node
{
	int balance;
	T data;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
class AVLTree
{
private:
	Node<T>* root; 

	void deleteAVLTree(Node<T>* &) const;
	void copyAVLTree(const AVLTree<T> &);
	void copy(Node<T>* &, Node<T>* const &) const;
	void printFromNode(const Node<T>*, int) const;

	void leftRotate(Node<T>* &);
	void rightRotate(Node<T>* &);

	int insertElem(Node<T>* &, const T&);
	int deleteElem(Node<T>* &, const T&);

	int counter(Node<T>*) const;
public:
	AVLTree();
	~AVLTree();

	AVLTree(const AVLTree<T>&);
	AVLTree<T>& operator=(const AVLTree<T>&);

	bool empty() const;
	T getAVLRootData() const;
	int getAVLBalance() const;
	AVLTree<T> leftAVLTree() const;
	AVLTree<T> rightAVLTree() const;

	void insertNode(const T&);
	void deleteNode(const T&);

	void printTree() const;

	void create();

	int size() const;

	friend std::ostream& operator<<(std::ostream&, const AVLTree<T>&);
	friend std::istream& operator>>(std::istream&, AVLTree<T>&);
	friend std::ofstream& operator<<(std::ofstream&, const AVLTree<T>&);
	friend std::ifstream& operator>>(std::ifstream&, AVLTree<T>&);

	bool operator<(const AVLTree<T>&);
};

