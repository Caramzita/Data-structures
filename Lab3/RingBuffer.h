#pragma once

struct RingBuffer
{
	int* data;
	int size;
	int begin;
	int end;
};

void CheckBuffer();

void CreateRingBuffer(int size);

void AddElement(int data);

int ExtractElement();

int GetFreeSpace();

int GetOccupiedSpace();

void ShowRingBuffer();

void ClearBuffer();

void ClearBufferMemory();