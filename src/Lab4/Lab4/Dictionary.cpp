#include "Dictionary.h"

using namespace std;

/**
 * @brief ��������� ������� � �������. ������ �������� ��� ���������� �����.
 * @param dictionary �������, � ������� ����� �������� �������.
 * @param item �������.
*/
void AddElement(HashTable*& dictionary, HashItem* item)
{
	if (dictionary->Count > dictionary->Size - 1)
	{
		throw invalid_argument("\n������� ��������!");
	}

	double loadFactor = (static_cast<double>(dictionary->Count) / dictionary->Size);

	if (loadFactor >= 0.75)
	{
		Rehashing(dictionary);
	}

	int index = HashFunction(item->Key, dictionary->Size - 1, dictionary->Size);

	if (dictionary->Items[index] == nullptr)
	{
		dictionary->Items[index] = item;
		dictionary->Count++;
	}
	else
	{
		if (dictionary->Items[index] != nullptr)
		{
			HashItem* temp = dictionary->Items[index];

			while (temp->Next != nullptr)
			{
				CheckCollision(item, temp);
				temp = temp->Next;
			}

			CheckCollision(item, temp);
			temp->Next = item;
			dictionary->Count++;
		}
	}
}