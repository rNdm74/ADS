#include "StdAfx.h"
#include "SelectionSort.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No arguments required
/// POST-CONDITION: The variable o to track the number of operations is initialized to 0 
/// </summary>
SelectionSort::SelectionSort(void)
{
	o = 0;
}

/// <summary>
/// Summary for Sort
///	
/// PRE-CONDITION:	Must provide array to be sorted
/// POST-CONDITION: The array will be sorted with a selection sort
///					the global variable o will be increments for each assignment and operation
///					The number of operations will be returned after the sort is finished
/// </summary>
int SelectionSort::Sort(array<int>^ list)
{
	o+=2;
	// Pointer and temp for swap
	int k;
    int temp;

	o++;
	// Loop though the list
    for ( int i = 0; i < list->Length; i++ ) 
	{
		o++;
		// Reset k to i position
        k = i;

		o++;
		// Find the first  item position in list
        for ( int j = i + 1; j < list->Length; j++ ) 
		{
			o++;
			// If item j is less than item k
            if ( list[j] < list[k] ) 
			{
				o++;
				// Set new position
                k = j;
            }
        }

		o+=3;
		// Make the swap
        temp = list[i];
        list[i] = list[k];
        list[k] = temp;
    }

	return o;
}