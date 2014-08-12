#include "StdAfx.h"
#include "InsertionSort.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No arguments required
/// POST-CONDITION: The variable o to track the number of operations is initialized to 0 
/// </summary>
InsertionSort::InsertionSort(void)
{
	o = 0;
}

/// <summary>
/// Summary for Sort
///	
/// PRE-CONDITION:	Must provide array to be sorted
/// POST-CONDITION: The array will be sorted with a insertion sort
///					the global variable o will be increments for each assignment and operation
///					The number of operations will be returned after the sort is finished
/// </summary>
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
