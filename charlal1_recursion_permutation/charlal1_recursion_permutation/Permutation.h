#pragma once

using namespace System;

ref class Permutation
{
public: 
	String^ result;
	String^ temp;
public:
	Permutation(void);
	void Permute(array<wchar_t>^ s, int n);
	void Swap(array<wchar_t>^ s, int c1, int c2);

	void PermuteV2(String^ temp, int startingLocation, int itemsToPermute);
	void PermuteV3(String^ temp, array<bool>^ used, int startingLocation, int itemsToPermute);
};
