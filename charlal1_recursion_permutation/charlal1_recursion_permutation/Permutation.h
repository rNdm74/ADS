#pragma once

using namespace System;

ref class Permutation
{
private: 
	String^ out;
public:
	Permutation(void);
	void Permute(array<wchar_t>^ s, int n);
	void Swap(array<wchar_t>^ s, int c1, int c2);

	String^ Permute(String^ temp, int startingLocation, int itemsToPermute);
	String^ Permute(String^ temp, array<bool>^ used, int startingLocation, int itemsToPermute);
};
