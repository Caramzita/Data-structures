#include <iostream>

using namespace std;

/**
 * @brief Создает и проверяет число.
 * @param message Информация для ввода.
 * @return Возвращает число.
*/
int CreateInt(const char* message)
{
	cout << message;

	int value;
	cin >> value;

	if (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << ("\nНеверный формат!\n");
	};

	return value;
}