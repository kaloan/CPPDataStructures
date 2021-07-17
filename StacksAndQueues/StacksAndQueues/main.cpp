#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"

using namespace std;

void testLinkedStack()
{
	cout << "TESTING LINKED STACK" << endl;
	LinkedStack<int> stack;
	stack.push(5);
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);
	
	//Test IO
	cout << stack;

	//Test Copy and Assignment
	auto stack2 = stack;
	cout << stack2;
	LinkedStack<int> stack3;
	stack3.push(100);
	cout << stack3;
	stack3 = stack;
	cout << stack3;

	//Test len
	cout << stack.len() << endl;


	//Test pop
	cout << stack.pop() << " ";
	cout << stack.pop() << endl;
	cout << stack;
}

void testLinkedQueue()
{
	cout << "TESTING LINKED QUEUE" << endl;
	LinkedQueue<int> queue;
	queue.push(5);
	queue.push(4);
	queue.push(3);
	queue.push(2);
	queue.push(1);

	//Test IO
	cout << queue;

	//Test Copy and Assignment
	auto queue2 = queue;
	cout << queue2;
	LinkedQueue<int> queue3;
	queue3.push(100);
	cout << queue3;
	queue3 = queue;
	cout << queue3;

	//Test len
	cout << queue.len() << endl;

	//Test pop
	cout << queue.pop() << " ";
	cout << queue.pop() << endl;
	cout << queue;
}

void testArrayStack()
{
	cout << "TESTING ARRAY STACK" << endl;
	ArrayStack<int> stack;
	stack.push(5);
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);

	//Test IO
	cout << stack;

	//Test Copy and Assignment
	auto stack2 = stack;
	cout << stack2;
	ArrayStack<int> stack3;
	stack3.push(100);
	cout << stack3;
	stack3 = stack;
	cout << stack3;

	//Test len
	cout << stack.len() << endl;

	//Test pop
	cout << stack.pop() << " ";
	cout << stack.pop() << endl;
	cout << stack;
}

void testArrayQueue()
{
	cout << "TESTING ARRAY QUEUE" << endl;
	ArrayQueue<int> queue;
	queue.push(5);
	queue.push(4);
	queue.push(3);
	queue.push(2);
	queue.push(1);

	//Test IO
	cout << queue;

	//Test Copy and Assignment
	auto queue2 = queue;
	cout << queue2;
	ArrayQueue<int> queue3;
	queue3.push(100);
	cout << queue3;
	queue3 = queue;
	cout << queue3;

	//Test len
	cout << queue.len() << endl;

	//Test pop
	cout << queue.pop() << " ";
	cout << queue.pop() << endl;
	cout << queue;
}

int main()
{
	testLinkedStack();
	testLinkedQueue();
	testArrayStack();
	testArrayQueue();

	cin.get();
	return 0;
}