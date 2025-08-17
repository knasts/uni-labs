#include "Priority_queue.h"
#include "binary_heap.h"
#include "dynamic_array.h"
#include <iostream>
using namespace std;


void Priority_queue::push(const Data& object)
{
	heap.array.push_back(object);
	heap.siftUp(heap.array.size() - 1);
}

Data Priority_queue::top()
{
	if (heap.array.size() == 0)
	{
		cout << "priority queue is empty:/" << endl;
		return Data();
	}
	return heap.array.get(0);
}
Data Priority_queue::pop()
{
	if (heap.array.size() == 0)
	{
		cout << "priority queue is empty:/" << endl;
		return Data();
	}

	Data root = heap.array.get(0);

	if (heap.array.size() > 1)
	{
		heap.array.list[0] = heap.array.get(heap.array.size() - 1);
	}
	;

	heap.array.pop_back();
	if (heap.array.size() > 0)
	{
		heap.siftDown(0);
	}

	return root;
}
int Priority_queue::size()
{
	return heap.array.size();
}
bool Priority_queue::empty()
{
	return(heap.array.size() == 0);
}
void Priority_queue::clean()
{
	heap.array.clear();
}