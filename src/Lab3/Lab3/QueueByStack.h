#pragma once
#include "Stack.h"

struct QueueByStack
{
	Stack* stack1;
	Stack* stack2;
};

void CreateQueueByStack(int length);

void Enqueue(int data);

void Dequeue();

void ShowQueStack();

void ClearQueueByStackMemory();