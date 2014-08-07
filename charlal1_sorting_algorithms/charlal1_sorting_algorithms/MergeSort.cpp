#include "StdAfx.h"
#include "MergeSort.h"

using namespace System;

MergeSort::MergeSort(void)
{
}

void MergeSort::Sort( array<int>^ list )
{ 
	int length = list->Length / 2;

	array<int>^ left = gcnew array<int>( length );

	Array::Copy( list, 0, left, 0, left->Length );

	array<int>^ right = gcnew array<int>( length );
	int srcIndex = ( length / 2 ) + 1;
	Array::Copy( list, srcIndex, right, 0, right->Length );

	Array::Sort( left );
	Array::Sort( right );

	Array::Copy(Merge( left, right ), list, list->Length);
}

array<int>^ MergeSort::Merge(array<int>^ left, array<int>^ right)
{
	/* calculate temporary list sizes */
	int left_length = left->Length;
	int right_length = right->Length;
 
	array<int>^ list = gcnew array<int>(left->Length + right->Length);
 
	int r = 0; /* right_half index */
	int l = 0; /* left_half index */
	int i = 0; /* list index */
  
	/* merge left_half and right_half back into list */
	for ( i = 0, r = 0, l = 0; l < left_length && r < right_length; i++)
	{
		if ( left[l] < right[r] ) { list[i] = left[l++]; }
		else { list[i] = right[r++]; }
	}
 
	/* Copy over leftovers of whichever temporary list hasn't finished */
	for ( ; l < left_length; i++, l++ ) { list[i] = left[l]; }
	for ( ; r < right_length; i++, r++ ) { list[i] = right[r]; }

    return list;
}
