#include "StdAfx.h"
#include "MergeSort.h"

MergeSort::MergeSort(void)
{
}

/// <summary>
/// Summary for Merge
///	
/// PRE-CONDITION:	Must provide array to be sorted
/// POST-CONDITION: The array will be sorted with a bubble sort
///					the global variable o will be increments for each assignment and operation
///					The number of operations will be returned after the sort is finished
/// </summary>
void MergeSort::Merge(array<int>^ numbers, int left, int mid, int right)
{
	// Temp array for merge
	array<int>^ temp = gcnew array<int>(numbers->Length);

	// Local variables
    int leftEnd = mid - 1;						// Left end position
    int tempPos = left;							// Start of left position
    int elementsToCopy = ( right - left + 1 );	// 

	// Merge the left and right into temp array
    while ( ( left <= leftEnd ) && ( mid <= right ) )
    {
        if ( numbers[left] <= numbers[mid] )
            temp[tempPos++] = numbers[left++];
        else
            temp[tempPos++] = numbers[mid++];
    }

	// Tidy up leftovers
    while ( left <= leftEnd )
        temp[tempPos++] = numbers[left++];
    while ( mid <= right )
        temp[tempPos++] = numbers[mid++];

	// Copy back
    for ( int i = 0; i < elementsToCopy; i++ )
    {
        numbers[right] = temp[right];
        right--;
    }
}

/// <summary>
/// Summary for MergeRecursive
///	
/// PRE-CONDITION:	Must provide array and the left and right positions
/// POST-CONDITION: The array will be sorted with a bubble sort
///					the global variable o will be increments for each assignment and operation
///					The number of operations will be returned after the sort is finished
/// </summary>
void MergeSort::MergeRecursive( array<int>^ numbers, int left, int right )
{	        
	// When there is elements to merge
	if ( right > left )
	{
		int mid = ( right + left ) / 2;				// Find middle
		MergeRecursive( numbers, left, mid );		// Merge left half
		MergeRecursive( numbers, mid + 1, right );	// Merge right half
		Merge( numbers, left, mid + 1, right );		// Combine
	}
}
