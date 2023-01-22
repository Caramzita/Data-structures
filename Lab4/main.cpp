#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int Continue;

    HashTable* table;

    do 
    {
        table = ShowMenu();

        cout << endl << "Введите 1 для продолжения или 0 для завершения программы: ";
        cin >> Continue;
        CheckInt();
        cout << endl;
    } while (Continue > 0 && Continue < 2);

    ClearHashTable(table);
}