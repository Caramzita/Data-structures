#include <iostream>
#include "HashTable.h"

using namespace std;

HashItem* item = new HashItem();

HashTable* table = new HashTable();

HashTable* ShowMenu() 
{
	cout << "==============================\n"
		<< "1. ������� �������;\n"
		<< "2. �������� ����-��������;\n"
		<< "3. ������� ����-��������;\n"
		<< "4. ����� �������� �� �����;\n"
		<< "==============================\n";

	int number;

	int size;

	char* key = new char[20];

	cout << "\n�������� ��������: ";
	cin >> number;

	try 
	{
		switch (number)
		{
		case 1:
			cout << "\n������� ������ �������: ";
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
			cout << "������� ����, ������� ������ �������: ";
			cin >> key;

			::table = DeleteKey(::table, key);
			ShowHashTable(::table);
			break;
		case 4:
			CheckTable(::table);
			cout << "������� ����, ������� ������ �����: ";
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