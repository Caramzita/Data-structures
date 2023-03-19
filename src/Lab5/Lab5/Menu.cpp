#include <iostream>
#include "Menu.h"

using namespace std;

void ShowMenu() 
{
	int resume;

	do
	{
		cout << "==============================\n"
			<< "1. �������� ������;\n"
			<< "2. ��������� ������;\n"
			<< "==============================\n";

		int number = CreateInt("\n�������� ��������: ");

		try 
		{
			switch (number)
			{
				case 1:
				{
					BinaryTreeMenu();
					break;
				}
				case 2:
				{
					TreapMenu();
					break;
				}
				default:
				{
					throw invalid_argument("\n��� ������ ��������!");
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\n������� 1 ��� ����������� ��� 0 ��� ���������� ���������: ");

		cout << endl;

	} while (resume > 0 && resume < 2);
}

void BinaryTreeMenu() 
{
	int resume;

	BinaryTree* tree = new BinaryTree();

	do
	{
		cout << "\n==============================\n"
			<< "1. ������� �������� ������;\n"
			<< "2. �������� ��������;\n"
			<< "3. ������� ��������;\n"
			<< "4. ����� ��������;\n"
			<< "5. ����� ��������� ������;\n"
			<< "6. ����� �������� ������;\n"
			<< "==============================\n";

		int number = CreateInt("\n�������� ��������: ");

		try
		{
			switch (number)
			{
				case 1:
				{
					int value = CreateInt("������� �������� ����� ������: ");
					tree = CreateTree(value);
					PrintBinaryTree(tree->Root, 0);
					break;
				}
				case 2:
				{
					int data = CreateInt("������� ��������, ������� ������ ��������: ");
					AddElement(data, tree->Root);
					PrintBinaryTree(tree->Root, 0);
					break;
				}
				case 3:
				{
					int data = CreateInt("������� ��������, ������� ������ �������: ");
					DeteleElement(data, tree->Root);
					PrintBinaryTree(tree->Root, 0);
					break;
				}
				case 4:
				{
					int value = CreateInt("������� �������, ������� ������ �����: ");
					int temp = Find(tree->Root, value);
					cout << "������� �������� - " << value;
					break;
				}
				case 5:
				{
					int max = FindMax(tree->Root);
					cout << "������������ ������� � ������ - " << max;
					break;
				}
				case 6:
				{
					int min = FindMin(tree->Root);
					cout << "����������� ������� � ������ - " << min;
					break;
				}
				default:
				{
					throw invalid_argument("\n��� ������ ��������!");
					break;
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\n������� 1 ��� ����������� ��� 0 ��� ������ � ����: ");

		cout << endl;

	} while (resume > 0 && resume < 2);
}

void PrintBinaryTree(BinaryTreeNode* node, int level){	if (node)
	{
		PrintBinaryTree(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}

		cout << node->Data << endl;
		PrintBinaryTree(node->Left, level + 1);
	}}

void TreapMenu()
{
	int resume;

	Treap* treap = new Treap();

	do
	{
		cout << "\n==============================\n"
			<< "1. ������� ��������� ������;\n"
			<< "2. �������� ������� (������������������ ��������);\n"
			<< "3. �������� ������� (���������������� ��������);\n"
			<< "4. ������� ������� (������������������ ��������);\n"
			<< "5. ������� ������� (���������������� ��������);\n"
			<< "6. ����� ��������;\n"
			<< "7. ������� ������;\n"
			<< "==============================\n";

		int number = CreateInt("\n�������� ��������: ");

		try
		{
			switch (number)
			{
				case 1:
				{
					int data = CreateInt("������� �������� ����� ������: ");
					treap = CreateTreap(data);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 2:
				{
					int data = CreateInt("������� ��������, ������� ������ ��������: ");
					TreapNode* node = CreateTreapNode(data);
					InsertUnoptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 3:
				{
					int data = CreateInt("������� ��������, ������� ������ ��������: ");
					TreapNode* node = CreateTreapNode(data);
					InsertOptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 4:
				{
					int data = CreateInt("������� ��������, ������� ������ �������: ");
					TreapNode* node = CreateTreapNode(data);
					DeleteUnoptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 5:
				{
					int data = CreateInt("������� ��������, ������� ������ �������: ");
					TreapNode* node = CreateTreapNode(data);
					DeleteOptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 6:
				{
					int data = CreateInt("������� ��������, ������� ������ �����: ");
					cout << "������ ������� � ������ - " << SearchElement(treap->Root, data);
					break;
				}
				case 7: 
				{
					ClearTreap(treap->Root);
					cout << "\n������ �������!\n";
					break;
				}
				default:
				{
					throw invalid_argument("\n��� ������ ��������!");
					break;
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\n������� 1 ��� ����������� ��� 0 ��� ������ � ����: ");

		cout << endl;

	} while (resume > 0 && resume < 2);
}

void PrintTreap(TreapNode* node, int level) 
{
	if (node)
	{
		PrintTreap(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}

		cout << node->Key << " : " << node->Priority << endl;
		PrintTreap(node->Left, level + 1);
	}
}