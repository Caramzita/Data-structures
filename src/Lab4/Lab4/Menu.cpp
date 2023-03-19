#include <iostream>
#include "Menu.h"

using namespace std;

/**
 * @brief ������� �� ����� ���� ���������.
*/
void ShowMenu() 
{
	HashItem* item = new HashItem();

	Dictionary* dictionary = new Dictionary();


	int resume;

	do
	{
		cout << "1. �������.\n"
			 << "2. ���-�������.\n";

		int number = CreateInt("\n�������� ��������: ");

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
					throw invalid_argument("��� ������ ��������!");
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}
		
		resume = CreateInt("\n������� 1 ��� ����������� ��� 0 ��� ���������� ���������: ");

		cout << endl;

	} while (resume > 0 && resume < 2);
}

/**
 * @brief ������� ���� ��� ������ �� ��������.
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
			<< "1. ������� �������;\n"
			<< "2. �������� ����-��������;\n"
			<< "3. ������� ����-��������;\n"
			<< "4. ����� �������� �� �����;\n"
			<< "==============================\n";

		int number = CreateInt("\n�������� ��������: ");

		try
		{
			switch (number)
			{
				case 1:
				{
					int size = CreateInt("\n������� ������ �������: ");

					dictionary->Table = CreateHashTable(size);
					break;
				}
				case 2:
				{
					CheckTable(dictionary->Table);

					cout << "������� ����: ";
					cin >> key;

					cout << "������� ��������: ";
					cin >> value;

					item = CreateItem(key, value);
					AddElement(dictionary->Table, item);
					ShowHashTable(dictionary->Table, false);
					break;
				}
				case 3:
				{
					CheckTable(dictionary->Table);
					cout << "������� ����, ������� ������ �������: ";
					cin >> key;

					DeleteKey(dictionary->Table, key);
					ShowHashTable(dictionary->Table, false);
					break;
				}
				case 4:
				{
					CheckTable(dictionary->Table);
					cout << "������� ����, ������� ������ �����: ";
					cin >> key;

					cout << endl << FindKey(dictionary->Table, key) << endl;
					break;
				}
				default:
				{
					throw invalid_argument("\n��� ������ ��������!");
					break;
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\n������� 1 ��� ����������� ��� 0 ��� ������: ");

	} while (resume > 0 && resume < 2);

	ClearHashTable(dictionary->Table);
}

/**
 * @brief ������� ���� ��� ������ � ���-��������.
*/
void HashTableMenu() 
{
	HashTable* hashTable = new HashTable();

	int resume;

	do
	{
		cout << "\n==============================\n"
			<< "1. ������� ���-�������;\n"
			<< "2. �������� ����-��������;\n"
			<< "3. ������� ����-��������;\n"
			<< "4. ����� �������� �� �����;\n"
			<< "==============================\n";

		int number = CreateInt("\n�������� ��������: ");

		HashItem* item = new HashItem();

		char* key = new char[20];

		char* value = new char[20];

		try
		{
			switch (number)
			{
				case 1:
				{
					int size = CreateInt("\n������� ������ �������: ");

					hashTable = CreateHashTable(size);
					break;
				}
				case 2:
				{
					CheckTable(hashTable);

					cout << "������� ����: ";
					cin >> key;

					cout << "������� ��������: ";
					cin >> value;

					item = CreateItem(key, value);
					AddKey(hashTable, item);
					ShowHashTable(hashTable, true);
					break;
				}
				case 3:
				{
					CheckTable(hashTable);
					cout << "������� ����, ������� ������ �������: ";
					cin >> key;

					DeleteKey(hashTable, key);
					ShowHashTable(hashTable, true);
					break;
				}
				case 4:
				{
					CheckTable(hashTable);
					cout << "������� ����, ������� ������ �����: ";
					cin >> key;

					cout << endl << FindKey(hashTable, key) << endl;
					break;
				}
				default:
				{
					throw invalid_argument("\n��� ������ ��������!");
					break;
				}
			}
		}
		catch (invalid_argument& e)
		{
			cerr << e.what() << endl;
		}

		resume = CreateInt("\n������� 1 ��� ����������� ��� 0 ��� ������: ");

	} while (resume > 0 && resume < 2);

	ClearHashTable(hashTable);
}


/**
 * @brief ������� �� ����� ��������� ���-�������/�������.
 * @param table ���-�������.
 * @param isHashTable �������� ������� ���-�������� ��� ��������. True, ���� ���-�������.
 * False, ���� �������.
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