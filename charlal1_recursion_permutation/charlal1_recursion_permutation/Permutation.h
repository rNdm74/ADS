#pragma once

using namespace System;

ref class Permutation
{
public: 
	String^ result;
public:
	Permutation(void);
	void Permute(array<wchar_t>^ s, int n);
	void Swap(array<wchar_t>^ s, int c1, int c2);

	void PermuteV2(int startingLocation, int itemsToPermute);
};
