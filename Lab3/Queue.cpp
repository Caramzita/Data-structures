#include <iostream>
#include "RingBuffer.h"

using namespace std;

struct Queue 
{
	RingBuffer ringBuffer;
	int capacity;
};

Queue* queue = new Queue;

int elementQueue;

int GetFreeSpaceQueue();

void CreateQueue(int length) 
{
	queue->capacity = length * 2;

	queue->ringBuffer.size = length;

	queue->ringBuffer.data = new int[queue->capacity];

	for (int i = length-1; i >= 0; i--)
	{
		cout << "Введите " << i << " элемент: ";
		cin >> elementQueue;
		queue->ringBuffer.data[i] = elementQueue;
	}

	queue->ringBuffer.begin = length - 1;

	queue->ringBuffer.end = 0;
}

void AddElementInQueue(int data) 
{
	for (int i = queue->ringBuffer.size - 1; i >= 0; i--)
	{
		if (queue->ringBuffer.data[i] == NULL) 
		{
			queue->ringBuffer.data[i] = data;
			queue->ringBuffer.begin = i - 1;
			queue->ringBuffer.end = i;
			return;
		}
	}

	int* array = new int[queue->ringBuffer.size + 1];

	queue->ringBuffer.size += 1;

	array[0] = data;

	for (int i = 1; i < queue->ringBuffer.size; i++) 
	{
		array[i] = queue->ringBuffer.data[i - 1];
	}

	delete queue->ringBuffer.data;

	queue->ringBuffer.data = array;

	queue->ringBuffer.begin = (queue->ringBuffer.begin + 1) % queue->ringBuffer.size;

	queue->ringBuffer.end = 0;

	if (queue->ringBuffer.end == -1)
	{
		queue->ringBuffer.end = queue->ringBuffer.size - 1;
	}
}

int ExtractElementInQueue() 
{
	if (GetFreeSpaceQueue() == queue->ringBuffer.size) 
	{
		throw invalid_argument("Очередь пуста!");
	}

	if (queue->ringBuffer.data[queue->ringBuffer.begin] == NULL)
	{
		for (int i = queue->ringBuffer.begin; i >= 0; i--)
		{
			if (queue->ringBuffer.data[i - 1] == NULL)
			{
				queue->ringBuffer.begin = (queue->ringBuffer.begin - 1) % queue->ringBuffer.size;
				continue;
			}

			queue->ringBuffer.begin = (queue->ringBuffer.begin - 1) % queue->ringBuffer.size;
			break;
		}
	}

	if (queue->ringBuffer.begin < 0 || (queue->ringBuffer.begin == queue->ringBuffer.end && queue->ringBuffer.size - GetFreeSpaceQueue() > 1))
	{
		queue->ringBuffer.begin = queue->ringBuffer.size - 1;
	}

	int element = queue->ringBuffer.data[queue->ringBuffer.begin];

	queue->ringBuffer.data[queue->ringBuffer.begin] = NULL;

	queue->ringBuffer.begin = (queue->ringBuffer.begin - 1) % queue->ringBuffer.size;

	return element;
}

void ShowQueue()
{
	cout << endl << "Текущий буфер:" << endl;

	for (int i = 0; i < queue->ringBuffer.size; i++)
	{
		if (queue->ringBuffer.data[i] == NULL)
		{
			cout << "X ";
			continue;
		}
		cout << queue->ringBuffer.data[i] << " ";
	}
}

int GetFreeSpaceQueue()
{
	int count = 0;

	for (int i = 0; i < queue->ringBuffer.size; i++)
	{
		if (queue->ringBuffer.data[i] == NULL)
		{
			count += 1;
		}
	}

	return count;
}

void ClearQueueMemory()
{
	delete[] queue->ringBuffer.data;
	delete queue;
}