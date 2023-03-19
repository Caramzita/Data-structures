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
		throw invalid_argument("Введите число");
	}
}

void ShowMenu()
{
	cout << "=============================================" << endl
		<< "1. Стек" << endl
		<< "2. Кольцевой буфер" << endl
		<< "3. Очередь на базе кольцевого буфера" << endl
		<< "4. Очередь на базе 2 стеков" << endl
		<< "=============================================" << endl;

	cout << endl << "Выберите операцию: ";
	cin >> number;
	CheckInt();

	switch (number)
	{
	case 1:
		do
		{
			StackMenu();
			cout << endl << "Введите 1 для продолжения или 0 для выхода из стека: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		break;
	case 2:
		do
		{
			RingBuffer();
			cout << endl << "Введите 1 для продолжения или 0 для выхода из кольцевого буфера: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		ClearBufferMemory();
	case 3:
		do
		{
			Queue();
			cout << endl << "Введите 1 для продолжения или 0 для выхода из очереди: ";
			cin >> Continue;
			CheckInt();
		} while (Continue > 0 && Continue < 2);
		ClearQueueMemory();
	case 4:
		do 
		{
			QueueByStack();
			cout << endl << "Введите 1 для продолжения или 0 для выхода из очереди: ";
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
	cout << endl << "1. Создание стека" << endl
		<< "2. Добавить элемент в стек" << endl
		<< "3. Удалить элемент из стека" << endl
		<< "4. Очистка стека" << endl;

	cout << endl << "Выберите операцию: ";
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
			cout << "Введите значение, которое хотите добавить: ";
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
			cout << "Стек пуст!" << endl;
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

	cout << endl << "1. Создать кольцевой буфер;" << endl
		<< "2. Добавить элемент в буфер;" << endl
		<< "3. Достать элемент из буфера;" << endl
		<< "4. Узнать свободное место буфера;" << endl
		<< "5. Узнать занятое место буфера;" << endl
		<< "6. Очистка буфера;" << endl;

	cout << endl << "Выберите операцию: ";
	cin >> number;
	CheckInt();
	cout << endl;
	try 
	{
		switch (number)
		{
		case 1:
			cout << "Введите длину буфера: ";
			cin >> size;

			CreateRingBuffer(size);
			ShowRingBuffer();
			break;
		case 2:
			cout << "Введите значение, которое хотите добавить: ";
			cin >> ::data;
			CheckInt();
			AddElement(::data);
			ShowRingBuffer();
			break;
		case 3:
			cout << "Элемент " << ExtractElement() << " извлечен" << endl;
			ShowRingBuffer();
			break;
		case 4:
			cout << "Свободного места: " << GetFreeSpace() << endl;
			break;
		case 5:
			cout << "Занятого места: " << GetOccupiedSpace() << endl;
			break;
		case 6:
			ClearBuffer();
			cout << "Буфер пуст!" << endl;
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

	cout << endl << "1. Создать очередь;" << endl
		<< "2. Добавить элемент в очередь;" << endl
		<< "3. Достать элемент из очереди;" << endl
		<< "4. Очистка очереди;" << endl;

	cout << endl << "Выберите операцию: ";
	cin >> number;
	CheckInt();
	cout << endl;

	try 
	{
		switch (number)
		{
		case 1:
			cout << "Введите длину очереди: ";
			cin >> length;

			CreateQueue(length);
			ShowQueue();
			break;
		case 2:
			cout << "Введите значение, которое хотите добавить: ";
			cin >> ::data;
			CheckInt();
			AddElementInQueue(::data);
			ShowQueue();
			break;
		case 3:
			cout << "Элемент " << ExtractElementInQueue() << " извлечен" << endl;
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

	cout << endl << "1. Создать очередь;" << endl
		<< "2. Добавить элемент в очередь;" << endl
		<< "3. Достать элемент из очереди;" << endl
		<< "4. Очистка очереди;" << endl;

	cout << endl << "Выберите операцию: ";
	cin >> number;
	CheckInt();
	cout << endl;

	try
	{
		switch (number)
		{
		case 1:
			cout << "Введите длину очереди: ";
			cin >> length;

			CreateQueueByStack(length);
			ShowQueStack();
			break;
		case 2:
			cout << "Введите значение, которое хотите добавить: ";
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
			cout << "Очередь пуста!" << endl;
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