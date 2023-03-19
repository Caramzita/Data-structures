#pragma once
#include "RingBuffer.h"

struct Queue
{
	RingBuffer ringBuffer;
	int capacity;
};

void CreateQueue(int length);

void AddElementInQueue(int data);

int ExtractElementInQueue();

void ShowQueue();

int GetFreeSpaceQueue();

void ClearQueueMemory();
