#pragma once

struct Node
{
	int data;
	Node* Next;
};

struct Stack
{
	Node* top = nullptr;
};

Stack* CreateStack();

void Push(Stack* stack, int data);

void Pop(Stack* stack);

void ShowStack(Stack* stack);

void ClearStack(Stack* stack);