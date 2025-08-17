#include <iostream>
#include "binary_heap.h"
#include "dynamic_array.h"
using namespace std;
#include <algorithm>

int Binary_heap::getParent(int index)
{
	return (index - 1) / 2;
}
int Binary_heap::getLeftChild(int index)
{
	return (2 * index) + 1;
}
int Binary_heap::getRightChild(int index)
{
	return (2 * index) + 2;
}
void Binary_heap::siftUp(int index)
{
	if (index <= 0) return;

	int parent_i = getParent(index);
	if (array.list[index] > array.list[parent_i])
	{
		swap(array.list[parent_i], array.list[index]);
		siftUp(parent_i);
	}
}
void Binary_heap::siftDown(int index)
{
	if (index < 0 || index >= array.size()) return;

	int left_ch_i = getLeftChild(index);
	int right_ch_i = getRightChild(index);
	int max_ch_i = index;

	int size = array.size();

	if (left_ch_i < size && array.list[left_ch_i] > array.list[max_ch_i])
	{
		max_ch_i = left_ch_i;
	}
	if (right_ch_i < size && array.list[right_ch_i] > array.list[max_ch_i])
	{
		max_ch_i = right_ch_i;
	}

	if (max_ch_i != index)
	{
		swap(array.list[index], array.list[max_ch_i]);
		siftDown(max_ch_i);
	}
}


