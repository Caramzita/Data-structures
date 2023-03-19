#include <iostream>
#include "Menu.h"

using namespace std;

void ShowMenu() 
{
	int resume;

	do
	{
		cout << "==============================\n"
			<< "1. Бинарное дерево;\n"
			<< "2. Декартово дерево;\n"
			<< "==============================\n";

		int number = CreateInt("\nВыберите операцию: ");

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
					throw invalid_argument("\nНет такого варианта!");
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\nВведите 1 для продолжения или 0 для завершения программы: ");

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
			<< "1. Создать бинарное дерево;\n"
			<< "2. Добавить значение;\n"
			<< "3. Удалить значение;\n"
			<< "4. Поиск элемента;\n"
			<< "5. Поиск максимума дерева;\n"
			<< "6. Поиск минимума дерева;\n"
			<< "==============================\n";

		int number = CreateInt("\nВыберите операцию: ");

		try
		{
			switch (number)
			{
				case 1:
				{
					int value = CreateInt("Введите значение корня дерева: ");
					tree = CreateTree(value);
					PrintBinaryTree(tree->Root, 0);
					break;
				}
				case 2:
				{
					int data = CreateInt("Введите значение, которое хотите добавить: ");
					AddElement(data, tree->Root);
					PrintBinaryTree(tree->Root, 0);
					break;
				}
				case 3:
				{
					int data = CreateInt("Введите значение, которое хотите удалить: ");
					DeteleElement(data, tree->Root);
					PrintBinaryTree(tree->Root, 0);
					break;
				}
				case 4:
				{
					int value = CreateInt("Введите элемент, который хотите найти: ");
					int temp = Find(tree->Root, value);
					cout << "Найдено значение - " << value;
					break;
				}
				case 5:
				{
					int max = FindMax(tree->Root);
					cout << "Максимальный элемент в дереве - " << max;
					break;
				}
				case 6:
				{
					int min = FindMin(tree->Root);
					cout << "Минимальный элемент в дереве - " << min;
					break;
				}
				default:
				{
					throw invalid_argument("\nНет такого варианта!");
					break;
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\nВведите 1 для продолжения или 0 для выхода в меню: ");

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
			<< "1. Создать декартово дерево;\n"
			<< "2. Добавить элемент (неоптимизированный алгоритм);\n"
			<< "3. Добавить элемент (оптимизированный алгоритм);\n"
			<< "4. Удалить элемент (неоптимизированный алгоритм);\n"
			<< "5. Удалить элемент (оптимизированный алгоритм);\n"
			<< "6. Поиск элемента;\n"
			<< "7. Очистка дерева;\n"
			<< "==============================\n";

		int number = CreateInt("\nВыберите операцию: ");

		try
		{
			switch (number)
			{
				case 1:
				{
					int data = CreateInt("Введите значение корня дерева: ");
					treap = CreateTreap(data);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 2:
				{
					int data = CreateInt("Введите значение, которое хотите добавить: ");
					TreapNode* node = CreateTreapNode(data);
					InsertUnoptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 3:
				{
					int data = CreateInt("Введите значение, которое хотите добавить: ");
					TreapNode* node = CreateTreapNode(data);
					InsertOptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 4:
				{
					int data = CreateInt("Введите значение, которое хотите удалить: ");
					TreapNode* node = CreateTreapNode(data);
					DeleteUnoptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 5:
				{
					int data = CreateInt("Введите значение, которое хотите удалить: ");
					TreapNode* node = CreateTreapNode(data);
					DeleteOptimized(treap->Root, node);
					PrintTreap(treap->Root, 0);
					break;
				}
				case 6:
				{
					int data = CreateInt("Введите значение, которое хотите найти: ");
					cout << "Найден элемент с ключом - " << SearchElement(treap->Root, data);
					break;
				}
				case 7: 
				{
					ClearTreap(treap->Root);
					cout << "\nДерево очищено!\n";
					break;
				}
				default:
				{
					throw invalid_argument("\nНет такого варианта!");
					break;
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\nВведите 1 для продолжения или 0 для выхода в меню: ");

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