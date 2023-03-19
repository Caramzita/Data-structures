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
	CheckInt();

	try 
	{
		switch (number)
		{
		case 1:
			cout << "\n������� ������ �������: ";
			cin >> size;
			CheckInt();

			::table = CreateHashTable(size);
			break;
		case 2:
			CheckTable(::table);
			item = CreateItem();
			::table = AddKey(::table, item);
			ShowHashTable(::table);
			break;
		case 3:
			CheckTable(::table);
			cout << "������� ����, ������� ������ �������: ";
			cin >> key;
			CheckInt();

			::table = DeleteKey(::table, key);
			ShowHashTable(::table);
			break;
		case 4:
			CheckTable(::table);
			cout << "������� ����, ������� ������ �����: ";
			cin >> key;
			CheckInt();

			cout << endl << FindKey(::table, key) << endl;
			break;
		default:
			throw invalid_argument("\n��� ������ ��������!");
			break;
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}

	return table;
}