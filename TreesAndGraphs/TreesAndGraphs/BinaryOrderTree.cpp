#include "BinaryOrderTree.h"
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
void BinaryOrderTree<T>::deleteTree(Node<T>* &nowRoot) const //O(nodes') nodes' са възлите с LCA nowRoot
{
	if (!nowRoot) return;
	deleteTree(nowRoot->left);
	deleteTree(nowRoot->right);
	delete nowRoot;
	nowRoot = NULL;
}

template<typename T>
void BinaryOrderTree<T>::copy(Node<T>* &place, const Node<T>* &toBeCopied) //O(nodes') nodes' са възлите с LCA toBeCopied
{
	place = NULL;
	if (toBeCopied) 
	{
		place = new Node<T>;
		place->data = toBeCopied->data;
		copy(place->left, toBeCopied->left);
		copy(place->right, toBeCopied->right);
	}
}

template<typename T>
void BinaryOrderTree<T>::copyTree(const BinaryOrderTree<T> &otherTree) //O(otherTree.nodes)
{
	copy(root, otherTree.root);
}

template<typename T>
void BinaryOrderTree<T>::printFromNode(const Node<T>* nowRoot) const //O(nodes)
{
	if (!nowRoot) return;
	printFromNode(nowRoot->left);
	cout << nowRoot->data << " ";
	printFromNode(nowRoot->right);
}

template<typename T>
void BinaryOrderTree<T>::add(Node<T>* &nowRoot, const T &info) //O(log nodes') nodes' са възлите с LCA nowRoot
{
	if (!nowRoot) 
	{
		nowRoot = new Node<T>;
		nowRoot->data = info;
		nowRoot->left = NULL;
		nowRoot->right = NULL;
		return;
	}
	if (info < nowRoot->data) add(nowRoot->left, info);
	else add(nowRoot->right, info);
}

template<typename T>
int BinaryOrderTree<T>::counter(Node<T>* nowRoot) const //O(nodes)
{
	if (!nowRoot) return 0;
	return 1 + counter(nowRoot->left) + counter(nowRoot->right);
}

template<typename T>
BinaryOrderTree<T>::BinaryOrderTree() //O(1)
{
	root = NULL;
}

template<typename T>
BinaryOrderTree<T>::~BinaryOrderTree() //O(nodes)
{
	deleteTree(root);
}

template<typename T>
BinaryOrderTree<T>::BinaryOrderTree(const BinaryOrderTree<T> &otherTree) //O(otherTree.nodes)
{
	copyTree(otherTree);
}

template<typename T>
BinaryOrderTree<T>& BinaryOrderTree<T>::operator=(const BinaryOrderTree<T> &otherTree) //O(1) или О(nodes+otherTree.nodes)
{
	if (this != &otherTree)
	{
		deleteTree(root);
		copyTree(otherTree);
	}
	return *this;
}

template<typename T>
void BinaryOrderTree<T>::createWithData(T info, BinaryOrderTree<T> left, BinaryOrderTree<T> right) //O(left.nodes+right.nodes)
{
	root = new Node<T>;
	root->data = info;
	copy(root->left, left.root);
	copy(root->right, right.root);
}

template<typename T>
void BinaryOrderTree<T>::create() //O(log n!) n e общия брой на възлите
{
	root = NULL;
	T nodeValue; 
	char anyMore;
	do 
	{
		cout << "> ";
		cin >> nodeValue;
		addNode(nodeValue);
		cout << "Continue adding?(y/n) ";
		cin >> anyMore;
	} while (anyMore == 'y');
}

template<typename T>
T BinaryOrderTree<T>::getRootData() const //O(1)
{
	return root->data;
}

template<typename T>
Node<T>* BinaryOrderTree<T>::getRootPtr() const //O(1)
{
	return root;
}

template<typename T>
BinaryOrderTree<T> BinaryOrderTree<T>::leftTree() const //O(root->left.nodes)
{
	BinOrdTree<T> result;
	copy(result.root, root->left);
	return result;
}

template<typename T>
BinaryOrderTree<T> BinaryOrderTree<T>::rightTree() const //O(root->right.nodes)
{
	BinOrdTree<T> result;
	copy(result.root, root->right);
	return result;
}

template<typename T>
bool BinaryOrderTree<T>::empty() const //O(1)
{
	if (!root) return false;
	return true;
}

template<typename T>
int BinaryOrderTree<T>::size() const //O(nodes)
{
	return counter(root);
}

template<typename T>
void BinaryOrderTree<T>::print() const //O(nodes)
{
	printFromNode(root);
}

template<typename T>
void BinaryOrderTree<T>::addNode(const T &info) //O(log nodes)
{
	add(root, info);
}

template<typename T>
void BinaryOrderTree<T>::deleteNode(const T &info) //O(leftTree.nodes+rightTree.nodes) 
{
	if (!root) return;
	T rootData = getRootData();
	BinaryOrderTree<T> tempTree;
	if (rootData == info && !root->left)
	{
		*this = this->rightTree();
		return;
	}
	if (rootData == info && !root->right) 
	{
		*this = leftTree();
		return;
	}
	if (rootData == info) 
	{
		T rootValue;
		rightTree().minTree(rootValue, tempTree);
		createWithData(rootValue, leftTree(), tempTree);
		return;
	}
	tempTree = *this;
	if (info < rootData) 
	{
		*this = leftTree();
		deleteNode(info);
		createWithData(rootData, *this, tempTree.rightTree());
		return;
	}
	if (info > rootData) 
	{
		*this = rightTree();
		deleteNode(info);
		createWithData(rootData, tempTree.leftTree(), *this);
	}
}

template<typename T>
void BinaryOrderTree<T>::deleteNodePtr(Node<T>* &nowRoot, const T &info) //O(nodes*log nodes)
{
	if (!nowRoot) return;
	if (info < nowRoot->data) 
	{
		deleteNodePtr(nowRoot->left, info);
	}
	else if (info > nowRoot->data) 
	{
		deleteNodePtr(nowRoot->right, info);
	}
	else 
	{
		Node<T> *tempPtr;
		if (!(nowRoot->left)) 
		{
			tempPtr = nowRoot;
			nowRoot = nowRoot->right;
			delete tempPtr;
		}
		else if (!(nowRoot->right)) 
		{
			tempPtr = nowRoot;
			nowRoot = nowRoot->left;
			delete tempPtr;
		}
		else 
		{
			tempPtr = nowRoot->right;
			while (tempPtr->left) 
			{
				tempPtr = tempPtr->left;
			}
			nowRoot->data = tempPtr->data;
			deleteNodePtr(nowRoot->right, tempPtr->data);
		}
	}
}

template<typename T>
void BinaryOrderTree<T>::minTree(T &min, BinaryOrderTree<T> &minimumTree) const //O(leftTree.nodes^2+rightTree.nodes)
{
	T a = getRootData();
	if (!root->left) 
	{
		min = a;
		minimumTree = rightTree();
	}
	else 
	{
		BinaryOrderTree<T> updatedLeftTree;
		leftTree().minTree(min, updatedLeftTree);
		minimumTree.createWithData(a, updatedLeftTree, rightTree());
	}
}

template<typename T>
bool BinaryOrderTree<T>::operator<(const BinaryOrderTree<T> &otherTree) //O(nodes+otherTree.nodes)
{
	int a = size();
	int b = otherTree.size();
	if (a < b) return true;
	return false;
}

template<typename T>
ostream & operator<<(ostream &output, const BinaryOrderTree<T> &tree) //O(1)
{
	T data = tree.getRootData();
	output << data << " ";
	return output;
}

template<typename T>
istream & operator>>(istream &input, BinaryOrderTree<T> &tree) //O(log tree.nodes)
{
	T data;
	input >> data;
	tree.addNode(data);
	return input;
}

template<typename T>
ofstream & operator<<(ofstream &outFIle, const BinaryOrderTree<T> &tree) //O(1)
{
	T data = tree.getRootData();
	outFile << data << " ";
	return outFile;
}

template<typename T>
ifstream & operator>>(ifstream &inFile, BinaryOrderTree<T> &tree) //O(log tree.nodes)
{
	T data;
	inFile >> data;
	tree.addNode(data);
	return inFile;
}
