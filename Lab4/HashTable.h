#pragma once

struct HashItem
{
	char* key;
	char* value;
};

struct HashTable
{
	HashItem** items;
	int count;
	int size;
};

HashItem* CreateItem();

HashTable* CreateHashTable(int size);

HashTable* AddKey(HashTable* table, HashItem* item);

HashTable* DeleteKey(HashTable* table, char* key);

const char* FindKey(HashTable* table, char* key);

int Hash(const char* str, int a, int m);

void ShowHashTable(HashTable* table);

void CheckTable(HashTable* table);

void ClearHashTable(HashTable* table);