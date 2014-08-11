#include "StdAfx.h"
#include "MergeSort.h"

using namespace System;

MergeSort::MergeSort(void)
{
	o= 0;
}

int MergeSort::Sort( array<int>^ list )
{ 
	o++;
	int length = list->Length / 2;

	o++;
	array<int>^ left = gcnew array<int>( length );

	o++;
	Array::Copy( list, 0, left, 0, left->Length );

	o+=3;
	array<int>^ right = gcnew array<int>( length );
	int srcIndex = ( length / 2 ) + 1;
	Array::Copy( list, srcIndex, right, 0, right->Length );

	o+=2;
	Array::Sort( left );
	Array::Sort( right );

	o++;
	Array::Copy(Merge( left, right ), list, list->Length);

	return o;
}

array<int>^ MergeSort::Merge(array<int>^ left, array<int>^ right)
{
	o+=2;
	/* calculate temporary list sizes */
	int left_length = left->Length;
	int right_length = right->Length;
 
	o++;
	array<int>^ list = gcnew array<int>(left->Length + right->Length);
 
	o+=3;
	int r = 0; /* right_half index */
	int l = 0; /* left_half index */
	int i = 0; /* list index */
  
	/* merge left_half and right_half back into list */
	o++;
	for ( i = 0, r = 0, l = 0; l < left_length && r < right_length; i++)
	{
		o+=3;

		if ( left[l] < right[r] ) 
		{
			list[i] = left[l++]; 
		}
		else 
		{ 
			list[i] = right[r++]; 
		}
	}
 
	/* Copy over leftovers of whichever temporary list hasn't finished */
	o+=2;
	for ( ; l < left_length; i++, l++ ) { o++; list[i] = left[l]; }
	for ( ; r < right_length; i++, r++ ) { o++; list[i] = right[r]; }

	o++;
    return list;
}
