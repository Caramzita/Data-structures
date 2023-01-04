#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node* Next;
};

struct Stack
{
	Node* top = nullptr;
};

void Push(Stack* stack, int data);

Stack* CreateStack()
{
	int length;
	int data;

	Stack* newStack = new Stack;

	cout << "Введите количество элементов стека: ";
	cin >> length;

	for(int i = 0; i < length; i++)
	{
		cout << i+1 << " элемент: ";
		cin >> data;
		Push(newStack, data);
	}

	return newStack;
}

void Push(Stack* stack, int data)
{
	Node* newData = new Node;

	newData->data = data;

	newData->Next = stack->top;

	stack->top = newData;
}

void Pop(Stack* stack)
{
	if (stack->top == nullptr)
	{
		return;
	}

	Node* ptr = stack->top->Next;

	delete stack->top;

	stack->top = ptr;
}

void ShowStack(Stack* stack)
{
	Node* temp = stack->top;
	cout << "Текущий стек:" << endl;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	cout << endl;
}

void ClearStack(Stack* stack)
{
	while (stack->top != nullptr)
	{
		Pop(stack);
	}

	delete stack;
}