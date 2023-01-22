#include <iostream>

using namespace std;

int index;

struct HashItem 
{
	char* key;
	char* value;
	HashItem* Next = nullptr;
};

struct HashTable 
{
	HashItem** items;
	int count;
	int size;
};

HashTable* Rehashing(HashTable* table);

HashItem* CreateItem() 
{
	char* key = new char[10];
	char* value = new char[10];

	HashItem* item = new HashItem();

	cout << "Введите ключ: ";
	cin >> key;

	cout << "Введите значение: ";
	cin >> value;

	item->key = key;
	item->value = value;

	return item;
}

HashTable* CreateHashTable(int size) 
{
	HashTable* table = new HashTable();

	table->count = 0;
	table->size = size;
	table->items = new HashItem*[size];

	for (int i = 0; i < size; i++) 
	{
		table->items[i] = nullptr;
	}

	return table;
}

int Hash(const char* str, int a, int m)
{
	int hash = 0;

	for (; *str != '\0'; str++)
	{
		hash = (hash * a + *str) % m;
	}

	return hash;
}

void CheckCollision(HashItem* item1, HashItem* item2) 
{
	if (!strcmp(item1->key, item2->key))
	{
		throw invalid_argument("\nТакой ключ уже существует!");
	}
}

HashTable* AddKey(HashTable* table, HashItem* item) 
{
	if (table->count > table->size - 1) 
	{
		throw invalid_argument("\nСловарь заполнен!");
	}

	if ((static_cast<double>(table->count) / table->size) > 0.70)
	{
		table = Rehashing(table);
	}
	
	index = Hash(item->key, table->size - 1, table->size);

	if (table->items[index] == nullptr) 
	{
		table->items[index] = item;
		table->count++;
	}
	else 
	{
		if (table->items[index] != nullptr)
		{
			HashItem* temp = table->items[index];

			while (temp->Next != nullptr)
			{
				CheckCollision(item, temp);
				temp = temp->Next;
			}

			CheckCollision(item, temp);
			temp->Next = item;
			table->count++;
		}
	}

	return table;
}

HashTable* DeleteKey(HashTable* table, char* key)
{
	index = Hash(key, table->size - 1, table->size);

	HashItem* temp = table->items[index];

	HashItem* prev = nullptr;

	while (temp != nullptr)
	{
		if (!strcmp(temp->key, key))
		{
			if (prev == nullptr)
			{
				table->items[index] = temp->Next;
				free(temp);
				return table;
			}

			prev->Next = temp->Next;
			free(temp);
			table->count--;
			return table;
		}

		prev = temp;
		temp = temp->Next;
	}

	throw invalid_argument("\nНет такого ключа!");
	return table;
}

const char* FindKey(HashTable* table, char* key) 
{
	index = Hash(key, table->size - 1, table->size);

	HashItem* temp = table->items[index];

	while (temp != nullptr)
	{
		if (!strcmp(temp->key, key))
		{
			return temp->value;
		}

		temp = temp->Next;
	}

	return "Нет такого ключа";
}

HashTable* Rehashing(HashTable* table) 
{
	HashTable* newTable = new HashTable();

	newTable->count = 0;
	newTable->size = table->size * 1.5;
	newTable->items = new HashItem * [newTable->size];

	for (int i = 0; i < newTable->size; i++)
	{
		newTable->items[i] = nullptr;
	}

	for (int i = 0; i < table->size; i++) 
	{
		HashItem* temp = table->items[i];

		while (temp != nullptr) 
		{
			index = Hash(temp->key, newTable->size - 1, newTable->size);
			newTable->items[index] = temp;
			newTable->count++;

			temp = temp->Next;
		}
	}

	delete table;

	return newTable;
}

void ShowHashTable(HashTable* table)
{
	for (int i = 0; i < table->size; i++) 
	{
		if (table->items[i]) 
		{
			if (table->items[i] != nullptr) 
			{
				HashItem* temp = table->items[i];

				while (temp != nullptr) 
				{
					cout << "Index: " << i << "\t Key: " << temp->key
						<< "\t Value: " << temp->value << " -> ";
					temp = temp->Next;
				}

				cout << endl;

				continue;
			}
		}

		cout << "None" << endl;
	}
}

void CheckTable(HashTable* table)
{
	if (table->items == nullptr)
	{
		throw invalid_argument("\nТаблица еще не создана!");
	}
}

void ClearHashTable(HashTable* table) 
{
	for (int i = 0; i < table->size; i++) 
	{
		HashItem* temp = table->items[i];

		HashItem* prev = nullptr;

		while (temp != nullptr)
		{
			prev = temp;
			temp = temp->Next;
			free(prev);
		}
	}

	free(table->items);
	free(table);
}
