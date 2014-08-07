#include "StdAfx.h"
#include "SelectionSort.h"

SelectionSort::SelectionSort(void)
{
}

void SelectionSort::Sort(array<int>^ list)
{
	// Find the largest item in list

	// Swap end list item with current item 
	
	// Move item to end of list
	//array<int>^ test = list;

	// 
	int k;
    int temp;

	// Loop though the list
    for ( int i = 0; i < list->Length; i++ ) 
	{
		// 
        k = i;

		// Find the first  item position in list
        for ( int j = i + 1; j < list->Length; j++ ) 
		{
			// 
            if ( list[j] < list[k] ) 
			{
				// Set new position
                k = j;
            }
        }

		// Make the swap
        temp = list[i];
        list[i] = list[k];
        list[k] = temp;
    }
}