#include <iostream>
#include "Stack.h"

using namespace std;

struct QueueByStack
{
	Stack* stack1 = new Stack;
	Stack* stack2 = new Stack;
};

QueueByStack* queueByStack = new QueueByStack;

int elementQueue1;

void Enqueue(int data);

void CreateQueueByStack(int length) 
{
	for (int i = 0; i < length; i++) 
	{
		cout << "Введите " << i + 1 << " элемент: ";
		cin >> elementQueue1;
		Enqueue(elementQueue1);
	}
}

void Enqueue(int data)
{
	Push(queueByStack->stack1, data);
}

void Dequeue() 
{
	Node* temp = queueByStack->stack1->top;

	if (queueByStack->stack2->top == nullptr) 
	{
		while (temp != nullptr)
		{
			Push(queueByStack->stack2, temp->data);
			Pop(queueByStack->stack1);
			temp = queueByStack->stack1->top;
		}
	}

	if (queueByStack->stack1->top == nullptr && queueByStack->stack2->top == nullptr) 
	{
		throw invalid_argument("Стеки пустые!");
	}

	cout << "Объект " << queueByStack->stack2->top->data << " удален!" << endl;

	Pop(queueByStack->stack2);
}

void ShowQueStack()
{
	Node* temp = queueByStack->stack1->top;
	cout << endl << "Стек №1" << endl;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	temp = queueByStack->stack2->top;

	cout << endl << "Стек №2" << endl;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
}

void ClearQueueByStackMemory()
{
	while (queueByStack->stack1->top != nullptr)
	{
		Pop(queueByStack->stack1);
	}

	while (queueByStack->stack2->top != nullptr)
	{
		Pop(queueByStack->stack2);
	}

	delete queueByStack;
}