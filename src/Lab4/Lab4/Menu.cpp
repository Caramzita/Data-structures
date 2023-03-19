#include <iostream>
#include "Menu.h"

using namespace std;

/**
 * @brief Выводит на экран меню программы.
*/
void ShowMenu() 
{
	HashItem* item = new HashItem();

	Dictionary* dictionary = new Dictionary();


	int resume;

	do
	{
		cout << "1. Словарь.\n"
			 << "2. Хеш-таблица.\n";

		int number = CreateInt("\nВыберите операцию: ");

		try 
		{
			switch (number)
			{
				case 1:
				{
					DictionaryMenu();
					break;
				}
				case 2:
				{
					HashTableMenu();
					break;
				}
				default:
				{
					throw invalid_argument("Нет такого варианта!");
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

/**
 * @brief Выводит меню для работы со словарем.
*/
void DictionaryMenu() 
{
	int resume;

	Dictionary* dictionary = new Dictionary();

	do
	{
		HashItem* item = new HashItem();

		char* key = new char[20];

		char* value = new char[20];

		cout << "\n==============================\n"
			<< "1. Создать словарь;\n"
			<< "2. Добавить ключ-значение;\n"
			<< "3. Удалить ключ-значение;\n"
			<< "4. Поиск значения по ключу;\n"
			<< "==============================\n";

		int number = CreateInt("\nВыберите операцию: ");

		try
		{
			switch (number)
			{
				case 1:
				{
					int size = CreateInt("\nВведите размер словаря: ");

					dictionary->Table = CreateHashTable(size);
					break;
				}
				case 2:
				{
					CheckTable(dictionary->Table);

					cout << "Введите ключ: ";
					cin >> key;

					cout << "Введите значение: ";
					cin >> value;

					item = CreateItem(key, value);
					AddElement(dictionary->Table, item);
					ShowHashTable(dictionary->Table, false);
					break;
				}
				case 3:
				{
					CheckTable(dictionary->Table);
					cout << "Введите ключ, который хотите удалить: ";
					cin >> key;

					DeleteKey(dictionary->Table, key);
					ShowHashTable(dictionary->Table, false);
					break;
				}
				case 4:
				{
					CheckTable(dictionary->Table);
					cout << "Введите ключ, который хотите найти: ";
					cin >> key;

					cout << endl << FindKey(dictionary->Table, key) << endl;
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

		resume = CreateInt("\nВведите 1 для продолжения или 0 для выхода: ");

	} while (resume > 0 && resume < 2);

	ClearHashTable(dictionary->Table);
}

/**
 * @brief Выводит меню для работы с хеш-таблицей.
*/
void HashTableMenu() 
{
	HashTable* hashTable = new HashTable();

	int resume;

	do
	{
		cout << "\n==============================\n"
			<< "1. Создать хеш-таблицу;\n"
			<< "2. Добавить ключ-значение;\n"
			<< "3. Удалить ключ-значение;\n"
			<< "4. Поиск значения по ключу;\n"
			<< "==============================\n";

		int number = CreateInt("\nВыберите операцию: ");

		HashItem* item = new HashItem();

		char* key = new char[20];

		char* value = new char[20];

		try
		{
			switch (number)
			{
				case 1:
				{
					int size = CreateInt("\nВведите размер словаря: ");

					hashTable = CreateHashTable(size);
					break;
				}
				case 2:
				{
					CheckTable(hashTable);

					cout << "Введите ключ: ";
					cin >> key;

					cout << "Введите значение: ";
					cin >> value;

					item = CreateItem(key, value);
					AddKey(hashTable, item);
					ShowHashTable(hashTable, true);
					break;
				}
				case 3:
				{
					CheckTable(hashTable);
					cout << "Введите ключ, который хотите удалить: ";
					cin >> key;

					DeleteKey(hashTable, key);
					ShowHashTable(hashTable, true);
					break;
				}
				case 4:
				{
					CheckTable(hashTable);
					cout << "Введите ключ, который хотите найти: ";
					cin >> key;

					cout << endl << FindKey(hashTable, key) << endl;
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

		resume = CreateInt("\nВведите 1 для продолжения или 0 для выхода: ");

	} while (resume > 0 && resume < 2);

	ClearHashTable(hashTable);
}


/**
 * @brief Выводит на экран состояние хеш-таблицы/словаря.
 * @param table Хеш-таблица.
 * @param isHashTable Является таблица хеш-таблицей или словарем. True, если хеш-таблица.
 * False, если словарь.
*/
void ShowHashTable(HashTable* table, bool isHashTable)
{
	for (int i = 0; i < table->Size; i++)
	{
		if (table->Items[i])
		{
			if (table->Items[i] != nullptr)
			{
				HashItem* temp = table->Items[i];

				while (temp != nullptr)
				{
					cout << "Index: " << i << "\t Key: " << temp->Key
						<< "\t Value: " << temp->Value << " || ";
					temp = temp->Next;
				}

				cout << endl;

				continue;
			}
		}

		if (isHashTable == true) 
		{
			cout << "None" << endl;
		}
	}
}