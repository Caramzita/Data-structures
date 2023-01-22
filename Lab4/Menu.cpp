#include <iostream>
#include "HashTable.h"

using namespace std;

HashItem* item = new HashItem();

HashTable* table = new HashTable();

HashTable* ShowMenu() 
{
	cout << "==============================\n"
		<< "1. Создать словарь;\n"
		<< "2. Добавить ключ-знечение;\n"
		<< "3. Удалить ключ-значение;\n"
		<< "4. Поиск значения по ключу;\n"
		<< "==============================\n";

	int number;

	int size;

	char* key = new char[20];

	cout << "\nВыберите операцию: ";
	cin >> number;

	try 
	{
		switch (number)
		{
		case 1:
			cout << "\nВведите размер словаря: ";
			cin >> size;

			::table = CreateHashTable(size);
			break;
		case 2:
			CheckTable(::table);
			::item = CreateItem();
			::table = AddKey(::table, ::item);
			ShowHashTable(::table);
			break;
		case 3:
			CheckTable(::table);
			cout << "Введите ключ, который хотите удалить: ";
			cin >> key;

			::table = DeleteKey(::table, key);
			ShowHashTable(::table);
			break;
		case 4:
			CheckTable(::table);
			cout << "Введите ключ, который хотите найти: ";
			cin >> key;

			cout << endl << FindKey(::table, key) << endl;
			break;
		default:
			break;
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}

	return table;
}