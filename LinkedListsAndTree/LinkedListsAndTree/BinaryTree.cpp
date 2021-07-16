#include "BinaryTree.h"
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void BinaryTree<T>::deleteBinaryTree(Node<T>* &curr) const //O(nodes)
{
	if (!curr) return;

	deleteBinaryTree(curr->left);
	deleteBinaryTree(curr->right);
	delete curr;
	curr = NULL;
}

template<typename T>
void BinaryTree<T>::copyFromNode(Node<T>*& spot, Node<T>* const &toCopy) const //O(nodes') nodes' са възлите от този надолу
{
	spot = NULL;
	if (toCopy) 
	{
		spot = new Node<T>(toCopy->data);
		copy(spot->left, toCopy->left);
		copy(spot->right, toCopy->right);
	}
}

template<typename T>
void BinaryTree<T>::copyBinaryTree(const BinaryTree<T>& otherTree) //О(otherTree.nodes)
{
	copy(root, otherTree.root);
}

template<typename T>
void BinaryTree<T>::printFromNode(const Node<T>* spot) const //O(nodes') nodes' са възлите от този надолу
{
	if (!spot) 
	{
		return;
	}

	printFromNode(spot->left);
	cout << spot->data << " ";
	printFromNode(spot->right);
}

template<typename T>
void BinaryTree<T>::createBinaryTree(Node<T>*& spot) const //O(2^n) 
{
	T info; 
	char additional;
	cout << "Root: ";
	cin >> info;
	spot = new Node<T>(info);

	cout << "left BinaryTree of: " << x << " y/n? ";
	cin >> additional;

	if (additional == 'y') 
	{
		createBinaryTree(spot->left);
	}

	cout << "right BinaryTree of: " << x << " y/n? ";
	cin >> additional;

	if (additional == 'y') 
	{
		createBinaryTree(spot->right);
	}
}

template<typename T>
int BinaryTree<T>::counter(Node<T>* nowRoot) const //O(nodes') nodes' са възлите от този надолу
{
	if(!nowRoot) return 0;
	return 1 + counter(nowRoot->left) + counter(nowRoot->right);
}

template<typename T>
void BinaryTree<T>::insertHelper(Node<T>*& nowRoot, const T &info)
{
	if (!nowRoot) nowRoot = new Node<T>(info);
	else if (info < nowRoot->data) insertHelper(nowRoot->left, info);
	else insertHelper(nowRoot->right, info);
}

template<typename T>
BinaryTree<T>::BinaryTree() //O(1)
{
	root = NULL;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& otherTree) //O(otherTree.nodes)
{
	copyBinaryTree(otherTree);
}

template<typename T>
BinaryTree<T> & BinaryTree<T>::operator=(const BinaryTree<T>& otherTree) //O(1) или О(nodes+otherTree.nodes);
{
	if (this != &otherTree)
	{
		deleteBinaryTree(root);
		copyBinaryTree(otherTree);
	}
	return *this;
}

template<typename T>
BinaryTree<T>::~BinaryTree() //O(nodes)
{
	deleteBinaryTree(root);
}

template<typename T>
BinaryTree<T> BinaryTree<T>::leftBinaryTree() const //O(nodes') nodes' са възлите в лявото поддърво 
{
	BinaryTree<T> copiedTree;
	copy(copiedTree.root, root->left);
	return copiedTree;
}

template<typename T>
BinaryTree<T> BinaryTree<T>::rightBinaryTree() const //O(nodes') nodes' са възлите в дясното поддърво 
{
	BinaryTree<T> copiedTree;
	copy(copiedTree.root, root->right);
	return copiedTree;
}

template<typename T>
T BinaryTree<T>::getRootData() const //О(1)
{
	return root->data;
}

template<typename T>
Node<T>* BinaryTree<T>::getRootPtr() //О(1)
{
	return root;
}

template<typename T>
bool BinaryTree<T>::empty() const //О(1)
{
	if (!root) return true;
	return false;
}

template<typename T>
void BinaryTree<T>::print() const //О(nodes)
{
	printFromNode(root);
}

template<typename T>
void BinaryTree<T>::create()
{
	createBinaryTree(root);
}

template<typename T>
void BinaryTree<T>::createWithData(T info, BinaryTree<T> left, BinaryTree<T> right) //O(left.nodes+right.nodes)
{
	root = new Node<T>(info);
	copy(root->left, left.root);
	copy(root->right, right.root);
}

template<typename T>
int BinaryTree<T>::size() const //O(nodes)
{
	return counter(root);
}

template<typename T>
void BinaryTree<T>::insert(const T &info)
{
	insertHelper(root, info);
}

template<typename T>
bool BinaryTree<T>::operator<(const BinaryTree<T>& otherTree) //O(nodes+otherTree.nodes)
{
	int a = size();
	int b = otherTree.size();
	if (a < b) return true;
	return false;
}

template<typename T>
ostream & operator<<(ostream &output, const BinaryTree<T>& tree) //O(1)
{
	T data = tree.getRootData();
	output << data << " ";
	return output;
}

template<typename T>
istream & operator>>(istream &input, BinaryTree<T>& tree) //O(1)
{
	T data;
	input >> data;
	tree.insert(data);
	return input;
}

template<typename T>
ofstream & operator<<(ofstream &outFile, const BinaryTree<T>& tree) //O(1)
{
	T data = tree.getRootData();
	outFile << data << " ";
	return outFile;
}

template<typename T>
ifstream & operator>>(ifstream &inFile, BinaryTree<T>& tree) //O(1)
{
	T data;
	inFile >> data;
	tree.insert(data);
	return inFile;
}
