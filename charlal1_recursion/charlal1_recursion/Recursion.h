#pragma once

using namespace System;

ref class Recursion
{
public:
	Recursion(void);
	String^ ReverseIt(String^ s);
	String^ RemoveIt(String^ t, String^ s);
	bool Palindrome(String^ s);
	bool PowerOfThree(int n);
	bool BinarySearch(array<int>^ dataValues, int target, int lBound, int uBound);
	int SumToN(int n);
};
