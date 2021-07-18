//Node is defined in both LL and BT, DNode is defined in both DLL and DCL, so comment out includes and test functions for the ones not used

//#include "LinkedList.cpp"
#include "DoubleLinkedList.cpp"
//#include "DoubleCircularList.cpp"
#include "BinaryTree.cpp"

#include <iostream>

using namespace std;

/*
void testList()
{
	cout << "TESTING LINKED LIST" << endl;
	LinkedList<int> list;
	list.insertAtEnd(5);
	list.insertAtEnd(4);
	list.insertAtEnd(3);
	list.insertAtEnd(2);
	list.insertAtEnd(1);
	
	list.print();
	list.iterStart();
	auto st = list.iter();	//iterator is moved to 4
	list.insertBefore(st, 10);
	list.print();

	st = list.iter(); //iterator is moved to 3
	int atST;
	list.deleteThis(st, atST);
	list.print();
	cout << "We have deleted: " << atST << endl;

	//Test Copy and assignment
	cout << "COPIED: ";
	auto list2 = list;
	list2.print();
	cout << "ASSIGNED: ";
	LinkedList<int> list3;
	list3 = list2;
	list3.print();

	//Test IO
	cin >> list;
	cin >> list;
	list.print();

	list.iterStart();
	int len = list.len();
	cout << "The length is: " << len << endl;
	for (int i = 0; i < len; i++)
	{
		cout << list << " ";
	}
	cout << endl;
}*/


void testDoubleList()
{
	cout << "TESTING DOUBLELINKED LIST" << endl;

	DoubleLinkedList<int> list;
	list.insertAtEnd(5);
	list.insertAtEnd(4);
	list.insertAtEnd(3);
	list.insertAtEnd(2);
	list.insertAtEnd(1);

	cout << "Forward print: ";
	list.print();
	list.iterStart();
	auto st = list.iterNext();	//iterator is moved to 4
	cout << "Reverse print: ";
	list.print_reverse();

	st = list.iterNext(); //iterator is moved to 3
	int atST;
	list.deleteThis(st, atST);
	list.print();
	cout << "We have deleted: " << atST << endl;

	list.iterEnd();
	st = list.iterPrev(); //iterator is moved to 2
	list.deleteThis(st, atST);
	list.print();
	cout << "We have deleted: " << atST << endl;

	//Test Copy and assignment
	cout << "COPIED: ";
	auto list2 = list;
	list2.print();
	cout << "ASSIGNED: ";
	DoubleLinkedList<int> list3;
	list3 = list2;
	list3.print();


	//Test IO
	cin >> list;
	cin >> list;
	list.print();

	list.iterStart();
	int len = list.len();
	cout << "The length is: " << len << endl;
	for (int i = 0; i < len; i++)
	{
		cout << list << " ";
	}
	cout << endl;
}

/*
void testDoubleCircularList()
{
	cout << "TESTING DOUBLELINKED CIRCULAR LIST" << endl;

	DoubleCircularList<int> list;
	list.insertAtStart(5);
	list.insertAtStart(4);
	list.insertAtStart(3);
	list.insertAtStart(2);
	list.insertAtStart(1);

	cout << "Forward print: ";
	list.print();
	list.iterStart();
	auto st = list.iter();	//iterator is moved to 4

	st = list.iter(); //iterator is moved to 3
	int atST;
	if (list.deleteThis(st, atST))
	{
		list.print();
		cout << "We have deleted: " << atST << endl;
	}

	//Test Copy and assignment
	cout << "COPIED: ";
	auto list2 = list;
	list2.print();
	cout << "ASSIGNED: ";
	DoubleCircularList<int> list3;
	list3 = list2;
	list3.print();


	//Test IO
	cin >> list;
	cin >> list;
	list.print();

	list.iterStart();
	int len = list.len();
	cout << "The length is: " << len << endl;
	for (int i = 0; i < len; i++)
	{
		cout << list << " ";
	}
	cout << endl;
}*/


void testBinaryTree()
{
	cout << "TESTING BINARY TREE" << endl;
	BinaryTree<int> tree;
	
	cout << "Initialised as empty?: " << tree.empty() << endl;

	tree.insert(6);
	cout << "Is it still empty?: " << tree.empty() << endl;

	tree.insert(4);
	tree.insert(3);
	tree.insert(2);
	tree.insert(1);
	
	tree.print(); //Left->Node->Right

	tree.insert(5);
	tree.insert(11);
	tree.print(); //Left->Node->Right

	cout << "The root is:" << tree.getRootData() << endl;

	//Test subtrees
	cout << "The left subtree is:";
	tree.leftBinaryTree().print();
	cout << "The right subtree is:";
	tree.rightBinaryTree().print();


	//Used for binary tree that is nonordered
	BinaryTree<int> nonOrdTree;
	nonOrdTree.create();
	nonOrdTree.print(); //Left->Node->Right

	//Test Copy and assignment
	cout << "COPIED: ";
	auto nonOrdTree2 = nonOrdTree;
	nonOrdTree2.print();
	cout << "ASSIGNED: ";
	BinaryTree<int> nonOrdTree3;
	nonOrdTree3 = nonOrdTree2;
	nonOrdTree3.print();

	//Test IO
	cin >> tree;
	cin >> tree;
	tree.print();

	int sz = tree.size();
	cout << "The size is: " << sz << endl;
	cout << "The root is: " << tree;
	cout << endl;
}

int main()
{
	//testList();
	testDoubleList();
	//testDoubleCircularList();
	testBinaryTree();

	cin.get();
	return 0;
}