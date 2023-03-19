#include <iostream>
#include "Menu.h"
using namespace std;

int number;

int Continue;

int data;

Stack* stack = new Stack;

void CheckInt() 
{
	if (!cin) 
	{
		throw invalid_argument("������� �����");
	}
}

void ShowMenu()
{
	cout << "=============================================" << endl
		<< "1. ����" << endl
		<< "2. ��������� �����" << endl
		<< "3. ������� �� ���� ���������� ������" << endl
		<< "4. ������� �� ���� 2 ������" << endl
		<< "=============================================" << endl;

	cout << endl << "�������� ��������: ";
	cin >> number;
	CheckInt();

	switch (number)
	{
	case 1:
		do
		{
			StackMenu();
			cout << endl << "������� 1 ��� ����������� ��� 0 ��� ������ �� �����: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		break;
	case 2:
		do
		{
			RingBuffer();
			cout << endl << "������� 1 ��� ����������� ��� 0 ��� ������ �� ���������� ������: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		ClearBufferMemory();
	case 3:
		do
		{
			Queue();
			cout << endl << "������� 1 ��� ����������� ��� 0 ��� ������ �� �������: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		ClearQueueMemory();
	case 4:
		do 
		{
			QueueByStack();
			cout << endl << "������� 1 ��� ����������� ��� 0 ��� ������ �� �������: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		ClearQueueByStackMemory();
	default:
		break;
	}
}

void StackMenu() 
{
	cout << endl << "1. �������� �����" << endl
		<< "2. �������� ������� � ����" << endl
		<< "3. ������� ������� �� �����" << endl
		<< "4. ������� �����" << endl;

	cout << endl << "�������� ��������: ";
	cin >> number;
	CheckInt();
	cout << endl;
	try 
	{
		switch (number)
		{
		case 1:
			::stack = CreateStack();
			cout << endl;
			ShowStack(::stack);
			break;
		case 2:
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> ::data;
			CheckInt();
			cout << endl;
			Push(::stack, ::data);
			ShowStack(::stack);
			break;
		case 3:
			Pop(::stack);
			cout << endl;
			ShowStack(::stack);
			break;
		case 4:
			ClearStack(::stack);
			cout << "���� ����!" << endl;
			break;
		default:
			break;
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}	
}

void RingBuffer()
{
	int size;

	cout << endl << "1. ������� ��������� �����;" << endl
		<< "2. �������� ������� � �����;" << endl
		<< "3. ������� ������� �� ������;" << endl
		<< "4. ������ ��������� ����� ������;" << endl
		<< "5. ������ ������� ����� ������;" << endl
		<< "6. ������� ������;" << endl;

	cout << endl << "�������� ��������: ";
	cin >> number;
	CheckInt();
	cout << endl;
	try 
	{
		switch (number)
		{
		case 1:
			cout << "������� ����� ������: ";
			cin >> size;

			CreateRingBuffer(size);
			ShowRingBuffer();
			break;
		case 2:
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> ::data;
			CheckInt();
			AddElement(::data);
			ShowRingBuffer();
			break;
		case 3:
			cout << "������� " << ExtractElement() << " ��������" << endl;
			ShowRingBuffer();
			break;
		case 4:
			cout << "���������� �����: " << GetFreeSpace() << endl;
			break;
		case 5:
			cout << "�������� �����: " << GetOccupiedSpace() << endl;
			break;
		case 6:
			ClearBuffer();
			cout << "����� ����!" << endl;
			break;
		default:
			break;
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
}

void Queue() 
{
	int length;

	cout << endl << "1. ������� �������;" << endl
		<< "2. �������� ������� � �������;" << endl
		<< "3. ������� ������� �� �������;" << endl
		<< "4. ������� �������;" << endl;

	cout << endl << "�������� ��������: ";
	cin >> number;
	CheckInt();
	cout << endl;

	try 
	{
		switch (number)
		{
		case 1:
			cout << "������� ����� �������: ";
			cin >> length;

			CreateQueue(length);
			ShowQueue();
			break;
		case 2:
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> ::data;
			CheckInt();
			AddElementInQueue(::data);
			ShowQueue();
			break;
		case 3:
			cout << "������� " << ExtractElementInQueue() << " ��������" << endl;
			ShowQueue();
			break;
		case 4:
			ClearQueueMemory();
		default:
			break;
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
}

void QueueByStack() 
{
	int length;

	cout << endl << "1. ������� �������;" << endl
		<< "2. �������� ������� � �������;" << endl
		<< "3. ������� ������� �� �������;" << endl
		<< "4. ������� �������;" << endl;

	cout << endl << "�������� ��������: ";
	cin >> number;
	CheckInt();
	cout << endl;

	try
	{
		switch (number)
		{
		case 1:
			cout << "������� ����� �������: ";
			cin >> length;

			CreateQueueByStack(length);
			ShowQueStack();
			break;
		case 2:
			cout << "������� ��������, ������� ������ ��������: ";
			cin >> ::data;
			CheckInt();
			Enqueue(::data);
			ShowQueStack();
			break;
		case 3:
			Dequeue();
			ShowQueStack();
			break;
		case 4:
			cout << "������� �����!" << endl;
			ClearQueueByStackMemory();
		default:
			break;
		}
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
}