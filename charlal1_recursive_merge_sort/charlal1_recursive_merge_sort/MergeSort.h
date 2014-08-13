#pragma once

using namespace System;

ref class MergeSort
{
public:
	MergeSort(void);
	void Merge(array<int>^ numbers, int left, int mid, int right);
	void MergeRecursive(array<int>^ numbers, int left, int right);
};
