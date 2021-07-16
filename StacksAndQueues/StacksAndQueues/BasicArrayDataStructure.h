#pragma once
//Навсякъде пиша времето само гледайки класа,но не трябва да забравяме, че е възможно операторите =, >>, << и т.н.
//на template класа може да са със собствена сложност, различна от О(1)
template <typename T>
class BasicArrayDataStructure
{
protected:
	T* arr;
	int start;
	int size;
	virtual void resize() = 0;


public:
	BasicArrayDataStructure() //O(1)
	{
		arr = NULL;
		start = -1;
		size = 0;
	}
	~BasicArrayDataStructure() //O(len)
	{
		clear();
	}

	void clear() //O(len)
	{
		delete[] arr;
	}

	virtual void push(const T&) = 0;
	virtual T pop() = 0;

	bool empty() //O(1)
	{
		if (start==-1) return true;
		return false;
	}
	virtual int len() = 0;

};