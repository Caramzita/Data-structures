#include <iostream>
#include "HashTable.h"

using namespace std;

/**
 * @brief Создает и проверяет число.
 * @param message Информация для ввода.
 * @return Возвращает число.
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
		cout << ("\nНеверный формат!\n");
	};

	return value;
}

/**
 * @brief Проверяет создана ли хеш-таблица.
 * @param table 
*/
void CheckTable(HashTable* table)
{
	if (table == nullptr)
	{
		throw invalid_argument("\nТаблица еще не создана!");
	}
}

/**
 * @brief Сравнивает два предмета на коллизию.
 * @param item1 Предмет 1.
 * @param item2 Предмет 2.
*/
void CheckCollision(HashItem* item1, HashItem* item2)
{
	if (!strcmp(item1->Key, item2->Key))
	{
		throw invalid_argument("\nТакой ключ уже существует!");
	}
}