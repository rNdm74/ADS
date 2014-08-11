#include "StdAfx.h"
#include "BubbleSort.h"

BubbleSort::BubbleSort(void)
{
	o = 0;
}

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
