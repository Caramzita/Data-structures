#include <iostream>
#include <time.h>
#include "Treap.h"

using namespace std;

Treap* CreateTreap(int data) 
{
	srand(time(NULL));

	Treap* treap = new Treap();
	TreapNode* node = new TreapNode();

	node->Key = data;
	node->Priority = rand() % 100;

	treap->Root = node;
	return treap;
}

TreapNode* CreateTreapNode(int data) 
{
	srand(time(NULL));

	TreapNode* node = new TreapNode();

	node->Key = data;
	node->Priority = rand() % 100;

	return node;
}

int SearchElement(TreapNode* node, int key) 
{
	if (node == nullptr)
	{
		throw invalid_argument("Такого ключа нет в дереве!");
	}

	if (node->Key == key) 
	{
		return node->Key;
	}

	if (node->Key > key) 
	{
		SearchElement(node->Left, key);
	}
	else
	{
		SearchElement(node->Right, key);
	}
}

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (node->Key > key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}

	right->Left = Merge(left, right->Left);

	return right;
}

void InsertUnoptimized(TreapNode*& node, TreapNode* element)
{
	if (node == nullptr) 
	{
		node = element;
		return;
	}

	TreapNode* left = new TreapNode();
	TreapNode* right = new TreapNode();

	Split(node, element->Key, left, right);

	node = Merge(Merge(left, element), right);
}

void InsertOptimized(TreapNode*& node, TreapNode* element) 
{
	if (node == nullptr)
	{
		node = element;
		return;
	}

	TreapNode* left = new TreapNode();
	TreapNode* right = new TreapNode();

	if (node->Priority < element->Priority) 
	{
		Split(node, element->Key, left, right);
		element->Left = left;
		element->Right = right;
		node = element;
	}
	else 
	{
		if (node->Key > element->Key) 
		{
			InsertOptimized(node->Left, element);
		}
		else
		{
			InsertOptimized(node->Right, element);
		}
	}
}

void DeleteUnoptimized(TreapNode*& node, TreapNode* element) 
{
	TreapNode* left = new TreapNode();
	TreapNode* right = new TreapNode();
	TreapNode* middle = new TreapNode();

	Split(node, element->Key - 1, left, right);
	Split(right, element->Key, middle, right);
	node = Merge(left, right);

	delete middle;
}

void DeleteOptimized(TreapNode*& node, TreapNode* element) 
{
	if (node->Key == element->Key) 
	{
		TreapNode* temp = node;

		node = Merge(node->Left, node->Right);

		delete temp;

		return;
	}

	if (node->Key > element->Key) 
	{
		DeleteOptimized(node->Left, element);
	}
	else 
	{
		DeleteOptimized(node->Right, element);
	}
}

void ClearTreap(TreapNode* node) 
{
	if (node == nullptr)
	{
		return;
	}

	ClearTreap(node->Left);
	ClearTreap(node->Right);
	delete node;
}