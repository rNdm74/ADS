#pragma once

ref class MergeSort
{

public:
	MergeSort(void);
	void Sort(array<int>^ list);
	array<int>^ Merge(array<int>^ left, array<int>^ right);
};
