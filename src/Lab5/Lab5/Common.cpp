#include <iostream>

using namespace std;

/**
 * @brief ������� � ��������� �����.
 * @param message ���������� ��� �����.
 * @return ���������� �����.
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
		cout << ("\n�������� ������!\n");
	};

	return value;
}