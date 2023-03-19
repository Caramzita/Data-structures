#include <iostream>
#include "Menu.h"
using namespace std;

int main()
{
	int Continue;

	setlocale(LC_ALL, "Russian");
	do
	{
		ShowMenu();

		cout << endl << "Введите 1 для продолжения или 0 для завершения программы: ";
		cin >> Continue;
		cout << endl;
	} while (Continue > 0 && Continue < 2);
}