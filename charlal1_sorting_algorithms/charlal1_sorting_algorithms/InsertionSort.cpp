#include "StdAfx.h"
#include "InsertionSort.h"

InsertionSort::InsertionSort(void)
{
}

void InsertionSort::Sort(array<int>^ list)
{
	int temp;

	for(int i = 1; i < list->Length - 1; i++)
	{
		temp = list[i];

		int j = i-1;

		while( j >= 0 && list[j] > temp)
		{
			list[j+1] = list[j];
			j = j -1;
		}

		list[j+1] = temp;
	}
}
