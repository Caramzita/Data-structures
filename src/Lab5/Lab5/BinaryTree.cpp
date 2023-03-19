#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree* CreateTree(int data) 
{
	BinaryTree* tree = new BinaryTree();

	BinaryTreeNode* root = new BinaryTreeNode();

	root->Data = data;

	root->Left = nullptr;
	root->Right = nullptr;

	tree->Root = root;

	return tree;
}

void AddElement(int data, BinaryTreeNode*& node) 
{
	if (!node) 
	{
		node = new BinaryTreeNode();

		node->Data = data;
		node->Left = nullptr;
		node->Right = nullptr;

		return;
	}

	if (node->Data > data)
	{
		AddElement(data, node->Left);
	}
	else
	{
		AddElement(data, node->Right);
	}
}

void DeteleElement(int data, BinaryTreeNode*& node) 
{
	if (node == nullptr) 
	{
		return;
	}

	if (data == node->Data) 
	{
		BinaryTreeNode* temp = new BinaryTreeNode();

		if (node->Right == nullptr)
		{
			temp = node->Left;
		}
		else 
		{
			BinaryTreeNode* tempRight = node->Right;

			if (tempRight->Left == nullptr)
			{
				tempRight->Left = node->Left;

				temp = node->Left;
			}
			else			
			{

				BinaryTreeNode* pmin = tempRight->Left;

				while (pmin->Left != nullptr) 
				{
					tempRight = pmin;

					pmin = tempRight->Left;
				}

				tempRight->Left = pmin->Right;

				pmin->Left = node->Left;

				pmin->Right = node->Right;

				temp = pmin;
			}
		}

		node = temp;
	}

	else if (data < node->Data)
	{
		DeteleElement(data, node->Left);
	}
	else 
	{
		DeteleElement(data, node->Right);
	}
}

int Find(BinaryTreeNode* node, int value)
{
	if (node == nullptr)
	{
		throw invalid_argument("\nТакого ключа нет в дереве!");
	}
	if (node->Data == value)
	{
		return node->Data;
	}
	if (node->Data > value)
	{
		return Find(node->Left, value);
	}
	else
	{
		return Find(node->Right, value);
	}
}

int FindMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		throw invalid_argument("Дерево пусто!");
	}

	while (node->Left != nullptr)
	{
		node = node->Left;
	}

	return node->Data;
}

int FindMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		throw invalid_argument("Дерево пусто!");
	}

	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node->Data;
}

