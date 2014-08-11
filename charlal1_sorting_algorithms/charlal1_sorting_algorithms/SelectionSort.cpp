#include "StdAfx.h"
#include "SelectionSort.h"

SelectionSort::SelectionSort(void)
{
	o = 0;
}

int SelectionSort::Sort(array<int>^ list)
{
	o+=2;
	// 
	int k;
    int temp;

	o++;
	// Loop though the list
    for ( int i = 0; i < list->Length; i++ ) 
	{
		o++;
		// 
        k = i;

		o++;
		// Find the first  item position in list
        for ( int j = i + 1; j < list->Length; j++ ) 
		{
			o++;
			// 
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