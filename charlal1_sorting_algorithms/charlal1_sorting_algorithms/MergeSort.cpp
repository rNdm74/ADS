#include "StdAfx.h"
#include "MergeSort.h"

using namespace System;

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No arguments required
/// POST-CONDITION: The variable o to track the number of operations is initialized to 0 
/// </summary>
MergeSort::MergeSort(void)
{
	o= 0;
}

/// <summary>
/// Summary for Sort
///	
/// PRE-CONDITION:	Must provide array to be sorted
/// POST-CONDITION: The array will be sorted with a merge sort
///					the global variable o will be increments for each assignment and operation
///					The number of operations will be returned after the sort is finished
/// </summary>
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

/// <summary>
/// Summary for Merge
///	
/// PRE-CONDITION:	Must provide two arrays of even size to be merged
/// POST-CONDITION: The arrays will be merged
///					the global variable o will be increments for each assignment and operation
///					and an merged array will be returned
/// </summary>
array<int>^ MergeSort::Merge(array<int>^ left, array<int>^ right)
{
	o+=2;
	// Calculate temporary list sizes
	int left_length = left->Length;
	int right_length = right->Length;
 
	o++;
	// list for left and right to be merged
	array<int>^ list = gcnew array<int>(left->Length + right->Length);
 
	o+=3;
	int r = 0; // right index
	int l = 0; // left index
	int i = 0; // list index
  
	o++;
	// Merge left and right back into list
	while ( l < left_length && r < right_length)
	{
		o++;
		// If right is larger than left
		if ( left[l] < right[r] ) 
		{
			o++;
			// left item to list
			list[i] = left[l++]; 
		}
		else 
		{ 
			o++;
			// right item to list
			list[i] = right[r++]; 
		}

		o++;
		// Increment list index
		i++;
	}
 
	o++;
	// Copy over leftovers from left
	while(l < left_length)
	{
		o++; 
		// Assign left item to list
		list[i] = left[l];

		o+=2;
		// Increment list and left index's
		i++; 
		l++;
	}

	o++;
	// Copy over leftovers from right
	while(r < right_length)
	{
		o++; 
		// Assign right item to list
		list[i] = right[r];

		o+=2;
		// Increment list and right index's 
		i++; 
		r++;
	}

	o++;
	// Return complete list
    return list;
}
