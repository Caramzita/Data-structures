#include <iostream>
using namespace std;

struct RingBuffer
{
	int* data;
	int size;
	int begin;
	int end;
};

int element;

RingBuffer* ringBuffer = new RingBuffer();

void CheckBuffer()
{
	if (ringBuffer->data == NULL)
	{
		throw invalid_argument("Буфер еще не создан!");
	}
}

void CreateRingBuffer(int size)
{
	ringBuffer = new RingBuffer();

	ringBuffer->data = new int[size];

	ringBuffer->size = size;

	for (int i = 0; i < size; i++) 
	{
		cout << "Введите " << i + 1 << " элемент: ";
		cin >> element;
		ringBuffer->data[i] = element;
	}

	ringBuffer->begin = -1;

	ringBuffer->end = size;
}

void AddElement(int data)
{
	CheckBuffer();

	for (int i = 0; i < ringBuffer->size; i++)
	{
		if (ringBuffer->data[i] == ' ')
		{
			ringBuffer->data[i] = data;
			ringBuffer->begin = i;
			ringBuffer->end = (ringBuffer->end + 1) % ringBuffer->size;
			return;
		}
	}

	ringBuffer->begin = (ringBuffer->begin + 1) % ringBuffer->size;

	ringBuffer->data[ringBuffer->begin] = data;

	ringBuffer->end = (ringBuffer->end + 1) % ringBuffer->size;
}

int ExtractElement()
{
	CheckBuffer();

	if (ringBuffer->data[ringBuffer->begin + 1] == ' ')
	{
		for(int i = ringBuffer->begin + 1; i < ringBuffer->size; i++)
		{
			if (ringBuffer->data[i] == ' ')
			{
				ringBuffer->begin = (ringBuffer->begin + 1) % ringBuffer->size;
				continue;
			}

			ringBuffer->begin = (ringBuffer->begin + 1) % ringBuffer->size;
			break;
		}
	}
	else 
	{
		ringBuffer->begin = (ringBuffer->begin + 1) % ringBuffer->size;
	}

	int element = ringBuffer->data[ringBuffer->begin];

	if (ringBuffer->begin == ringBuffer->size) 
	{
		ringBuffer->begin = 0;
	}

	ringBuffer->data[ringBuffer->begin] = ' ';

	return element;
}

int GetFreeSpace()
{
	CheckBuffer();

	int count = 0;

	for (int i = 0; i < ringBuffer->size; i++)
	{
		if (ringBuffer->data[i] == NULL)
		{
			count += 1;
		}
	}

	return count;
}

int GetOccupiedSpace()
{
	int count = ringBuffer->size - GetFreeSpace();

	return count;
}

void ShowRingBuffer()
{
	CheckBuffer();

	cout << endl << "Текущий буфер:" << endl;

	for (int i = 0; i < ringBuffer->size; i++)
	{
		if (ringBuffer->data[i] == ' ')
		{
			cout << "X ";
			continue;
		}
		cout << ringBuffer->data[i] << " ";
	}
}

void ClearBuffer()
{
	for (int i = 0; i < ringBuffer->size; i++) 
	{
		ringBuffer->data[i] = ' ';
	}
}

void ClearBufferMemory()
{
	delete[] ringBuffer->data;
	delete ringBuffer;
}