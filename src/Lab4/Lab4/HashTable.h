#pragma once

/**
 * @brief ��������� �������� �������. ������ ���� ����-�������� � ��������� �� ��������� �������.
*/
struct HashItem
{
	//���� ��������.
	char* Key;

	//�������� ��������.
	char* Value;

	//��������� �� ��������� �������.
	HashItem* Next = nullptr;
};

/**
 * @brief ��������� ���-�������. ������ ������ ��������� ���� HashItem*, ���������� ���������,
 * � ������ �������.
*/
struct HashTable
{
	//������ ��������� ���� HashItem*.
	HashItem** Items;

	//���������� ����������� ��������� � �������.
	int Count;

	//������ �������.
	int Size;
};

HashItem* CreateItem(char* key, char* value);

HashTable* CreateHashTable(int size);

void AddKey(HashTable*& table, HashItem* item);

void DeleteKey(HashTable*& table, char* key);

const char* FindKey(HashTable* table, char* key);

int HashFunction(const char* str, int a, int m);

void Rehashing(HashTable* table);

void ClearHashTable(HashTable* table);