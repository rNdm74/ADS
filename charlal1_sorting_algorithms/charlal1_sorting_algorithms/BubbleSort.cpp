#include "StdAfx.h"
#include "BubbleSort.h"

BubbleSort::BubbleSort(void)
{
}

void BubbleSort::Sort(array<int>^ list)
{
	bool swapped = true;

	while ( swapped ) 
	{
		swapped = false;

		for ( int i = 0; i < list->Length - 1; i++ ) 
		{
			if ( list[i] > list[i + 1] ) 
			{
				int temp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = temp;
                
				swapped = true;
			}
		}
	}
}
