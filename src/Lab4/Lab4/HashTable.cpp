#include <iostream>
#include <time.h>
#include "HashTable.h"
#include "Common.h"

using namespace std;

/**
 * @brief ������� ������� ���� HashItem*.
 * @param key ����.
 * @param value ��������.
 * @return ���������� ������� ���� HashItem*.
*/
HashItem* CreateItem(char* key, char* value) 
{
	HashItem* item = new HashItem();

	item->Key = key;
	item->Value = value;

	return item;
}

/**
 * @brief ������� ���-�������.
 * @param size ������ ���-�������.
 * @return ���������� ������ ���-������� �������� size.
*/
HashTable* CreateHashTable(int size) 
{
	HashTable* table = new HashTable();

	table->Count = 0;
	table->Size = size;
	table->Items = new HashItem*[size];

	for (int i = 0; i < size; i++) 
	{
		table->Items[i] = nullptr;
	}

	return table;
}

/**
 * @brief ��������� ����������� �����.
 * @param inputKey ������� ������.
 * @param a ������� �����.
 * @param m ������� �����.
 * @return ���������� ������ � ���-�������.
*/
int HashFunction(const char* inputKey, int a, int m)
{
	int hash = 0;

	for (; *inputKey != '\0'; inputKey++)
	{
		hash = (hash * a + *inputKey) % m;
	}

	return hash;
}

/**
 * @brief ��������� ������� ����-�������� � ���-�������.
 * @param table �������, � ������� ����� �������� �������.
 * @param item ������� ���� HashItem*.
*/
void AddKey(HashTable*& table, HashItem* item) 
{
	if (table->Count > table->Size - 1) 
	{
		throw invalid_argument("\n������� ��������!");
	}

	double loadFactor = (static_cast<double>(table->Count) / table->Size);

	if (loadFactor >= 0.75)
	{
		Rehashing(table);
	}
	
	int index = HashFunction(item->Key, table->Size - 1, table->Size);

	if (table->Items[index] == nullptr) 
	{
		table->Items[index] = item;
		table->Count++;
	}
	else 
	{
		if (table->Items[index] != nullptr)
		{
			HashItem* temp = table->Items[index];

			while (temp->Next != nullptr)
			{
				temp = temp->Next;
			}

			temp->Next = item;
			table->Count++;
		}
	}
}

/**
 * @brief ������� ������� �� ���-�������.
 * @param table �������, � ������� ����� ������� �������.
 * @param key 
*/
void DeleteKey(HashTable*& table, char* key)
{
	int index = HashFunction(key, table->Size - 1, table->Size);

	HashItem* temp = table->Items[index];

	HashItem* prev = nullptr;

	while (temp != nullptr)
	{
		if (!strcmp(temp->Key, key))
		{
			if (prev == nullptr)
			{
				table->Items[index] = temp->Next;
				free(temp);
				return;
			}

			prev->Next = temp->Next;
			free(temp);
			table->Count--;
			return;
		}

		prev = temp;
		temp = temp->Next;
	}

	throw invalid_argument("\n��� ������ �����!");
}

/**
 * @brief ������� �������� �� �����.
 * @param table �������, � ������� ����� ����� ��������.
 * @param key ����, ������� ����� �����.
 * @return ���������� �������� �� �����, ���� �� ��� ������ �����,
 * �� ����������� ����������.
*/
const char* FindKey(HashTable* table, char* key) 
{
	int index = HashFunction(key, table->Size - 1, table->Size);

	HashItem* temp = table->Items[index];

	while (temp != nullptr)
	{
		if (!strcmp(temp->Key, key))
		{
			return temp->Value;
		}

		temp = temp->Next;
	}

	throw invalid_argument("\n��� ������ �����!");

	return nullptr;
}

/**
 * @brief ��������� ��������������� �������, ���� ��� ��������� �� 75% � �����.
 * @param table ������� ��� ���������������.
*/
void Rehashing(HashTable* table)
{
	HashTable* newTable = new HashTable();

	newTable->Count = 0;
	const double growthFactor = 1.5;

	newTable->Size = table->Size * growthFactor;
	newTable->Items = new HashItem*[newTable->Size];

	for (int i = 0; i < newTable->Size; i++)
	{
		newTable->Items[i] = nullptr;
	}

	for (int i = 0; i < table->Size; i++)
	{
		HashItem* temp = table->Items[i];

		while (temp != nullptr)
		{
			HashItem* tempItem = new HashItem();

			tempItem->Key = temp->Key;
			tempItem->Value = temp->Value;

			AddKey(newTable, tempItem);

			temp = temp->Next;
		}
	}

	table->Items = newTable->Items;
	table->Count = newTable->Count;
	table->Size = newTable->Size;
}

/**
 * @brief ������� ���-������� � ����������� ������.
 * @param table ���-�������.
*/
void ClearHashTable(HashTable* table) 
{
	for (int i = 0; i < table->Size; i++) 
	{
		HashItem* temp = table->Items[i];

		HashItem* prev = nullptr;

		while (temp != nullptr)
		{
			prev = temp;
			temp = temp->Next;
			free(prev);
		}
	}

	free(table->Items);
	free(table);
}
