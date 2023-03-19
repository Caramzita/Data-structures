#pragma once

/**
 * @brief Структура элемента таблицы. Хранит пару ключ-значение и указатель на следующий элемент.
*/
struct HashItem
{
	//Ключ элемента.
	char* Key;

	//Значение элемента.
	char* Value;

	//Указатель на следующий элемент.
	HashItem* Next = nullptr;
};

/**
 * @brief Структура хеш-таблицы. Хранит массив элементов типа HashItem*, количество элементов,
 * и размер таблицы.
*/
struct HashTable
{
	//Массив элементов типа HashItem*.
	HashItem** Items;

	//Количество заполненных элементов в таблице.
	int Count;

	//Размер таблицы.
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