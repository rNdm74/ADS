#include "StdAfx.h"
#include "BubbleSort.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No arguments required
/// POST-CONDITION: The variable o to track the number of operations is initialized to 0 
/// </summary>
BubbleSort::BubbleSort(void)
{
	o = 0;
}

/// <summary>
/// Summary for Sort
///	
/// PRE-CONDITION:	Must provide array to be sorted
/// POST-CONDITION: The array will be sorted with a bubble sort
///					the global variable o will be increments for each assignment and operation
///					The number of operations will be returned after the sort is finished
/// </summary>
int BubbleSort::Sort(array<int>^ list)
{
	o++;
	bool swapped = true;

	o++;
	while ( swapped ) 
	{
		o++;
		swapped = false;

		o++;
		for ( int i = 0; i < list->Length - 1; i++ ) 
		{
			o++;
			if ( list[i] > list[i + 1] ) 
			{
				o+=4;
				int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
                
				swapped = true;
			}
		}
	}

	return o;
}
