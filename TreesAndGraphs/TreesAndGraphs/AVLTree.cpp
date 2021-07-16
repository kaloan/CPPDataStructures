#include "AVLTree.h"
#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
void AVLTree<T>::deleteAVLTree(Node<T>* &nowRoot) const //O(nodes') nodes' са възлите с LCA nowRoot
{
	if (!nowRoot) return;
	deleteAVLFromNode(nowRoot->left);
	deleteAVLFromNode(nowRoot->right);
	delete nowRoot;
	nowRoot = NULL;
}

template<typename T>
void AVLTree<T>::copyAVLTree(const AVLTree<T> &otherTree) //O(otherTree.nodes)
{
	copy(root, otherTree.root);
}

template<typename T>
void AVLTree<T>::copy(Node<T>* &place, Node<T>* const &toBeCopied) const //O(nodes') nodes' са възлите с LCA toBeCopied
{
	place = NULL;
	if (toBeCopied) 
	{
		place = new Node<T>;
		place->data = toBeCopied->data;
		place->balance = toBeCopied->balance;
		copy(place->left, toBeCopied->left);
		copy(place->right, toBeCopied->right);
	}
}

template<typename T>
void AVLTree<T>::printFromNode(const Node<T>* nowRoot, int n) const //O(nodes') nodes' са възлите с LCA nowRoot
{
	if (!nowRoot) return;
	n = n + 7;
	printFromNode(nowRoot->right, n);
	cout << setw(n) << nowRoot->data << " " << nowRoot->balance << endl;
	printFromNode(nowRoot->left, n);
}

template<typename T>
void AVLTree<T>::leftRotate(Node<T>* &nowRoot) //O(1)
{
	Node<T>* temp = nowRoot;
	nowRoot = nowRoot->right;
	temp->right = nowRoot->left;
	nowRoot->left = temp;

	temp->balance = temp->balance – 1;
	if (nowRoot->balance > 0) 
	{
		temp->balance = temp->balance – nowRoot->balance;
	}
	nowRoot->balance = nowRoot->balance – 1;
	if (temp->balance < 0) 
	{
		nowRoot->balance = nowRoot->balance + temp->balance;
	}
}

template<typename T>
void AVLTree<T>::rightRotate(Node<T>* &nowRoot) //O(1)
{
	Node<T>* temp = nowRoot;
	nowRoot = nowRoot->left;
	temp->left = nowRoot->right;
	nowRoot->right = temp;
	
	temp->balance = temp->balance + 1;
	if (nowRoot->balance < 0) 
	{
		temp->balance = temp->balance – nowRoot->balance;
	}

	nowRoot->balance = nowRoot->balance + 1;
	if (temp->balance > 0) 
	{
		nowRoot->balance = nowRoot->balance + temp->balance;
	}
}

template <typename T>
int AVLTree<T>::insertElem(Node <T>* &nowRoot, const T &info) //O(log nodes)
{
	int h = 0; 
	if (!nowRoot) 
	{
		nowRoot = new Node<T>;
		nowRoot->data = info;
		nowRoot->balance = 0;
		nowRoot->left = nowRoot->right = NULL;
		h = 1;
		return h;
	}
	
	if (info > nowRoot->data) 
	{
		if (insertElem(nowRoot->right, info))
		{
			nowRoot->balance++; 
			if (nowRoot->balance == 1) h = 1;
			else if (nowRoot->balance == 2) 
			{
				if (nowRoot->right->balance == -1) rightRotate(nowRoot->right);
				leftRotate(nowRoot);
			}
		}
		return h;
	}
	
	if (info < nowRoot->data) 
	{
		if (insertElem(nowRoot->left, info)) 
		{
			nowRoot->balance--;
			if (nowRoot->balance == -1) h = 1;
			else if (nowRoot->balance == -2) 
			{
				if (nowRoot->left->balance == 1) leftRotate(nowRoot->left);
				rightRotate(nowRoot);
			}
		}
	}
	return h;
}

template<typename T>
int AVLTree<T>::deleteElem(Node<T>* &nowRoot, const T &info) //О(log nodes)
{
	Node<T>* p;
	Node<T>* temp;
	int h = 0;
	if (!nowRoot) return 0;

	if (info < nowRoot->data) 
	{
		if (deleteElem(nowRoot->left, info)) 
		{
			nowRoot->balance++;
			if (nowRoot->balance == 0) h = 1;
			else if (nowRoot->balance == 2) 
			{
				if (nowRoot->right->balance == -1) rightRotate(nowRoot->right);
				leftRotate(nowRoot);
				h = 1;
			}
		}
		return h;
	}
	
	if (info > nowRoot->data) 
	{
		if (deleteElem(nowRoot->right, info)) 
		{
			nowRoot->balance--;
			if (nowRoot->balance == 0) h = 1;
			else if (nowRoot->balance == -2) {
				if (nowRoot->left->balance == 1) {
					leftRotate(nowRoot->left);
				}
				rightRotate(nowRoot);
				h = 1;
			}
		}
		return h;
	}
	
	if (!nowRoot->right) 
	{
		temp = nowRoot;
		nowRoot = nowRoot->left;
		delete temp;
		return 1;
	}
	else if (!nowRoot->left) 
	{
		temp = nowRoot;
		nowRoot = nowRoot->right;
		delete temp;
		return 1;
	}
	else 
	{ 
		p = nowRoot->left;
		while (p->right) p = p->right; 
		nowRoot->data = p->data;
		p->data = info;
		if (deleteElem(nowRoot->left, info)) 
		{
			nowRoot->balance++;
			if (nowRoot->balance == 0) h = 1;
			else if (nowRoot->balance == 2) 
			{
				if (nowRoot->right->balance == -1) rightRotate(nowRoot->right);
				leftRotate(nowRoot);
				if (nowRoot->balance == 0) h = 1;
			}
		}
	}
	return h;
}

template<typename T>
int AVLTree<T>::counter(Node<T>* nowRoot) const //O(nodes)
{
	if (!nowRoot) return 0;
	return 1 + counter(nowRoot->left) + counter(nowRoot->right);
}

template<typename T>
AVLTree<T>::AVLTree() //O(1)
{
	root = NULL;
}

template<typename T>
AVLTree<T>::~AVLTree() //O()
{
	deleteAVLTree(root);
}

template<typename T>
AVLTree<T>::AVLTree(const AVLTree<T> &otherTree) //O(otherTree.nodes)
{
	copyAVLTree(nowRoot);
}

template<typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T> &otherTree) //O(nodes+otherTree.nodes)
{
	if (this != &otherTree)
	{
		deleteAVLTree(root);
		copyAVLTree(otherTree);
	}
	return *this;
}

template<typename T>
bool AVLTree<T>::empty() const //O(1)
{
	if (!root) return false;
	return true;
}

template<typename T>
T AVLTree<T>::getAVLRootData() const //O(1)
{
	return root->data;
}

template<typename T>
int AVLTree<T>::getAVLBalance() const //O(1)
{
	return root->balance;
}

template<typename T>
AVLTree<T> AVLTree<T>::leftAVLTree() const //O(root->left.nodes)
{
	AVLTree<T> tempTree;
	copy(tempTree.root, root->left);
	return tempTree;
}

template<typename T>
AVLTree<T> AVLTree<T>::rightAVLTree() const //O(root->right.nodes)
{
	AVLTree<T> tempTree;
	copy(tempTree.root, root->right);
	return tempTree;
}

template<typename T>
void AVLTree<T>::insertNode(const T &info) //O(log nodes)
{
	insertElem(root, info);
}

template<typename T>
void AVLTree<T>::deleteNode(const T &info) //O(log nodes)
{
	deleteElem(root, info);
}

template<typename T>
void AVLTree<T>::printTree() const //O(nodes)
{
	printFromNode(root, 0);
	cout << endl;
}

template<typename T>
void AVLTree<T>::create() //O(log n!) n e общия брой на възлите
{
	root = NULL;
	T nodeValue;
	char anyMore;
	do
	{
		cout << "> ";
		cin >> nodeValue;
		insertNode(nodeValue);
		cout << "Continue adding?(y/n) ";
		cin >> anyMore;
	} while (anyMore == 'y');
}

template<typename T>
int AVLTree<T>::size() const //O(nodes)
{
	return counter(root);
}

template<typename T>
bool AVLTree<T>::operator<(const AVLTree<T> &otherTree) //O(nodes+otherTree.nodes)
{
	int a = size();
	int b = otherTree.size();
	if (a < b) return true;
	return false;
}

template<typename T>
ostream & operator<<(ostream &output, const AVLTree<T> &tree) //O(1)
{
	T data = tree.getRootData();
	output << data << " ";
	return output;
}

template<typename T>
istream & operator>>(istream &input, AVLTree<T> &tree) //O(log tree.nodes)
{
	T data;
	input >> data;
	tree.insertNode(data);
	return input;
}

template<typename T>
ofstream & operator<<(ofstream &outFIle, const AVLTree<T> &tree) //O(1)
{
	T data = tree.getRootData();
	outFile << data << " ";
	return outFile;
}

template<typename T>
ifstream & operator>>(ifstream &inFile, AVLTree<T> &tree) //O(log tree.nodes)
{
	T data;
	inFile >> data;
	tree.insertNode(data);
	return inFile;
}
