#pragma once
#include <iostream>
#include "HashTable.h"
#include "Common.h"

/**
 * @brief ��������� �������. ������ ���-�������.
*/
struct Dictionary
{
	// ���-�������.
	HashTable* Table;
};

void AddElement(HashTable*& dictionary, HashItem* item);