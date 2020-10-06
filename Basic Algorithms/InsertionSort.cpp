/*
*Insertion Sort standalone application using c++.
*Templated function, works with various types.
*Limitations: Sorting not guaranteed to work with non-numeral types.
*Author: Rodolfo Fava
*Date: October 6th, 2020
*Language: C++
*/

#include "pch.h"
#include <iostream>

template<typename T>
void debugPrint(T* container, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << "\n";
}

template<typename T>
void CPP_InsertionSort(T* container, size_t length)
{
	for (size_t i = 1; i < length; i++)
	{
		T temp = container[i];
		size_t j = i;
		for (; j >= 0 && container[j - 1] > temp; j--)
		{
			container[j] = container[j - 1];
		}
		container[j] = temp;

		//debugPrint(container, length);
	}
	debugPrint(container, length);
}

int main()
{
	//Insertion Sort
	int p[] = { 1,2,3,0 };
	CPP_InsertionSort(p, 4);

	double p2[] = { 1.2 , 10.5, 3.2, 100.01, 34.34 };
	CPP_InsertionSort(p2, 5);

	float p3[] = { 3.4f, 23.f, 12.5f, 9.3f, 4.5f };
	CPP_InsertionSort(p3, 5);

	char c1[] = { 'a', 'b', 'A', 'J', 'B', '2' };
	CPP_InsertionSort(c1, 6);

	return 0;
}