#pragma once

struct BinaryTreeNode
{
	int Data;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
};

struct BinaryTree
{
	BinaryTreeNode* Root;
};

BinaryTree* CreateTree(int data);

void AddElement(int data, BinaryTreeNode*& node);

void DeteleElement(int data, BinaryTreeNode*& node);

int Find(BinaryTreeNode* node, int value);

int FindMin(BinaryTreeNode* node);

int FindMax(BinaryTreeNode* node);

