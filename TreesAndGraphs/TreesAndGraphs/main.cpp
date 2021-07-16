#include "LinkedList.cpp"
#include <iostream>
#include <vector>
using namespace std;

typedef LinkedList<int> IntList;
typedef LinkedList<IntList> IntGraph;

Node<int>* getPointPtr(int a, IntGraph &graph) {
	graph.iterStart();
	Node<IntList>* listPtr;
	Node<int>* pointPtr;
	do 
	{
		listPtr = graph.iter();
		listPtr->data.iterStart();
		pointPtr = listPtr->data.iter();
	} while (pointPtr->data != a);
	return pointPtr;
}

vector<int> BFSArray(vector<vector<bool>> adjacency, int start) //Редовете са началата, а колоните краищата
{
	int size = adjacency.size();
	vector<bool> reached;
	reached.resize(size);

	int queueSize = 1;
	vector<int> searchQueue;
	searchQueue.resize(queueSize);
	searchQueue.push_back(start);

	vector<int> lengths; //result
	lengths.resize(size, 0);

	while (!searchQueue.empty())
	{
		int now = searchQueue[0];
		for (int i = 0; i < size; i++)
		{
			if (adjacency[now][i])
			{
				searchQueue.push_back(i);
				lengths[i] = lengths[now] + 1;
				reached[i] = true;
			}
		}
		searchQueue.erase(searchQueue.begin());
	}

	for (int i = 0; i < size; i++)
	{
		if (!reached[i]) lengths[i] = -1;
	}
	return lengths;
}

vector<int> BFSLinked(IntGraph graph, int start)
{
	int size = graph.len();
	vector<bool> reached;
	reached.resize(size);

	int queueSize = 1;
	vector<int> searchQueue;
	searchQueue.resize(queueSize);
	searchQueue.push_back(start);

	vector<int> lengths; 
	lengths.resize(size, 0);

	while (!searchQueue.empty())
	{
		int now = searchQueue[0];
		Node<int>* adjacent = getPointPtr(now, graph);
		while (adjacent->next)
		{
			searchQueue.push_back(adjacent->next->data);
			lengths[adjacent->next->data] = lengths[now] + 1;
			adjacent = adjacent->next;
		}
		searchQueue.erase(searchQueue.begin());
	}

	for (int i = 0; i < size; i++)
	{
		if (!reached[i]) lengths[i] = -1;
	}
	return lengths;
}

vector<int> DFSArray(vector<vector<bool>> adjacency,int start) //Тук и в другата функция използвам, че неориентиран граф е
{															//подвид на ориентирания
	int size = adjacency.size();
	vector<bool> reached;
	reached.resize(size);

	int stackSize = 1;
	vector<int> searchStack;
	searchStack.resize(stackSize);
	searchStack.push_back(start);

	vector<int> lengths; //result
	lengths.resize(size, 0);

	while (!searchStack.empty())
	{
		int now = searchStack[stackSize-1];
		searchStack.pop_back();
		if (!reached[now])
		{
			reached[now] = true;
			for (int i = 0; i < size; i++)
			{
				if (adjacency[now][i])
				{
					searchStack.push_back(i);
					lengths[i] = lengths[now] + 1;
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (!reached[i]) lengths[i] = -1;
	}
	return lengths;
}

vector<int> DFSLinked(IntGraph graph, int start)
{
	int size = graph.len();
	vector<bool> reached;
	reached.resize(size);

	int stackSize = 1;
	vector<int> searchStack;
	searchStack.resize(stackSize);
	searchStack.push_back(start);

	vector<int> lengths;
	lengths.resize(size, 0);

	while (!searchStack.empty())
	{
		int now = searchStack[stackSize - 1];
		searchStack.pop_back();
		if (!reached[now])
		{
			reached[now] = true;
			Node<int>* adjacent = getPointPtr(now, graph);
			while (adjacent->next)
			{
				searchStack.push_back(adjacent->next->data);
				lengths[adjacent->next->data] = lengths[now] + 1;
				adjacent = adjacent->next;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (!reached[i]) lengths[i] = -1;
	}
	return lengths;
}

//Не съм сигурен как да ги рандъмна толкова големи данни