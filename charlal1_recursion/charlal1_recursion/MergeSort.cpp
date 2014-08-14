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
    int left_end = mid - 1;					// Left end position
    int tmp_pos = left;						// Start of left position
    int num_elements = (right - left + 1);	// 

	// Merge the left and right
    while ( ( left <= left_end ) && ( mid <= right ) )
    {
        if ( numbers[left] <= numbers[mid] )
            temp[tmp_pos++] = numbers[left++];
        else
            temp[tmp_pos++] = numbers[mid++];
    }

	// Tidy up leftovers
    while ( left <= left_end )
        temp[tmp_pos++] = numbers[left++];
    while ( mid <= right )
        temp[tmp_pos++] = numbers[mid++];

	// Copy back
    for ( int i = 0; i < num_elements; i++ )
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
void MergeSort::MergeRecursive(array<int>^ numbers, int left, int right)
{
	int mid;
        
	if (right > left)
	{
		mid = (right + left) / 2;
		MergeRecursive(numbers, left, mid);
		MergeRecursive(numbers, mid + 1, right);

		Merge(numbers, left, mid + 1, right);
	}
}
