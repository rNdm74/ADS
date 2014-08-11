#pragma once

ref class MergeSort
{
public:
	int o;
public:
	MergeSort(void);
	int Sort(array<int>^ list);
	array<int>^ Merge(array<int>^ left, array<int>^ right);
};
