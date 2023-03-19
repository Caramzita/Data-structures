#include <iostream>
#include "HashTable.h"

using namespace std;

/**
 * @brief ������� � ��������� �����.
 * @param message ���������� ��� �����.
 * @return ���������� �����.
*/
int CreateInt(const char* message)
{
	cout << message;

	int value;
	cin >> value;

	if (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << ("\n�������� ������!\n");
	};

	return value;
}

/**
 * @brief ��������� ������� �� ���-�������.
 * @param table 
*/
void CheckTable(HashTable* table)
{
	if (table == nullptr)
	{
		throw invalid_argument("\n������� ��� �� �������!");
	}
}

/**
 * @brief ���������� ��� �������� �� ��������.
 * @param item1 ������� 1.
 * @param item2 ������� 2.
*/
void CheckCollision(HashItem* item1, HashItem* item2)
{
	if (!strcmp(item1->Key, item2->Key))
	{
		throw invalid_argument("\n����� ���� ��� ����������!");
	}
}