// FlyweightDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


const int PhysicalNumbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

// create a linked list of numbers
// that point to the const elements
typedef struct _Number
{
	const int*	pNum;
	_Number*	pNext;
}Number;

Number* pRootNum = nullptr;


bool CreateNumber(int _iNum)
{
	if (_iNum < 0 || _iNum > 9) {
		return false;
	}

	Number* pNum = new Number();
	if (pNum == nullptr) {
		return false;
	}

	pNum->pNum = &PhysicalNumbers[_iNum];
	pNum->pNext = nullptr;

	if (pRootNum == nullptr) {
		pRootNum = pNum;
	}
	else {
		pNum->pNext = pRootNum;
		pRootNum = pNum;
	}

	return true;
}





int main()
{
	printf("\nEnter characters individually followed by a return key");
	printf("\nEnter -1 followed by return to exit\n");

	bool bLoop = true;
	while (bLoop) {
		int num = -1;
		//num = getchar();
		scanf_s("%i", &num);
		if (num < 0) {
			bLoop = false;
		}
		else {
			CreateNumber(num);
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
