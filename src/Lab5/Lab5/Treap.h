#pragma once

struct TreapNode
{
	int Key;
	int Priority;
	TreapNode* Left = nullptr;
	TreapNode* Right = nullptr;
};

struct Treap 
{
	TreapNode* Root;
};

Treap* CreateTreap(int data);

TreapNode* CreateTreapNode(int data);

int SearchElement(TreapNode* node, int key);

void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

TreapNode* Merge(TreapNode* left, TreapNode* right);

void InsertUnoptimized(TreapNode*& node, TreapNode* element);

void InsertOptimized(TreapNode*& node, TreapNode* element);

void DeleteUnoptimized(TreapNode*& node, TreapNode* element);

void DeleteOptimized(TreapNode*& node, TreapNode* element);

void ClearTreap(TreapNode* node);