#include "StdAfx.h"
#include "MergeSort.h"

MergeSort::MergeSort(void)
{
}

void MergeSort::Merge(array<int>^ numbers, int left, int mid, int right)
{

	array<int>^ temp = gcnew array<int>(numbers->Length);
    int i, left_end, num_elements, tmp_pos;

    left_end = (mid - 1);
    tmp_pos = left;
    num_elements = (right - left + 1);

    while ((left <= left_end) && (mid <= right))
    {
        if (numbers[left] <= numbers[mid])
            temp[tmp_pos++] = numbers[left++];
        else
            temp[tmp_pos++] = numbers[mid++];
    }

    while (left <= left_end)
        temp[tmp_pos++] = numbers[left++];

    while (mid <= right)
        temp[tmp_pos++] = numbers[mid++];

    for (i = 0; i < num_elements; i++)
    {
        numbers[right] = temp[right];
        right--;
    }
}

void MergeSort::MergeRecursive(array<int>^ numbers, int left, int right)
{
	int mid;
        
	if (right > left)
	{
		mid = (right + left) / 2;
		MergeRecursive(numbers, left, mid);
		MergeRecursive(numbers, (mid + 1), right);

		Merge(numbers, left, (mid+1), right);
	}
}
