#pragma once
#include <iostream>
#include "HashTable.h"
#include "Common.h"

/**
 * @brief Структура словаря. Хранит хеш-таблицу.
*/
struct Dictionary
{
	// Хеш-таблица.
	HashTable* Table;
};

void AddElement(HashTable*& dictionary, HashItem* item);