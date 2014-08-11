#include "StdAfx.h"
#include "InsertionSort.h"

InsertionSort::InsertionSort(void)
{
	o = 0;
}

int InsertionSort::Sort(array<int>^ list)
{
	o++;
	int temp;

	o++;
	for(int i = 1; i < list->Length - 1; i++)
	{
		o++;
		temp = list[i];

		o++;
		int j = i-1;

		o++;
		while( j >= 0 && list[j] > temp)
		{
			o+=2;
			list[j+1] = list[j];
			j = j -1;
		}

		o++;
		list[j+1] = temp;
	}

	return o;
}
