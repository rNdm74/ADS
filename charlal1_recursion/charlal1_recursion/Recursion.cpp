#include "StdAfx.h"
#include "Recursion.h"

Recursion::Recursion(void)
{
}

String^ Recursion::ReverseIt(String^ s)
{
	if(s->Length == 1)
		return s;
	else
		return ReverseIt(s->Substring(1, s->Length - 1)) + s[0];
}

String^ Recursion::RemoveIt(String^ t, String^ s)
{
	// If the string does NOT contain t
	if(s->Contains(t) == false)
		return s;
	else
	{
		// Get the first instance
		int index = s->IndexOf(t);
		// Remove it from the string
		String^ temp = s->Remove(index, 1);
		// Check for next instance of t
		return RemoveIt(t, temp);
	}
}

bool Recursion::PowerOfThree(int n)
{
	// lowest number divisible by 3
	if(n == 1)
		return true;

	// if the number is no mod of 3 cannot divide evenly by 3
	if(n % 3 == 1)
		return false;
	else
		return PowerOfThree(n / 3); // devide n by 3
}

bool Recursion::Palindrome(String^ s)
{
	// Check if got to the middle
	if( s->Length == 1 || s->Length == 0 )
		return true;

	// Get the first and last char
	char first = s[0];
	char last = s[s->Length - 1];

	// Keep checking if char are the same
	if( first == last )
		return Palindrome( s->Substring( 1, s->Length - 2 ) );
	
	// If chars do not equal must be false
	return false;
}

int Recursion::SumToN(int n)
{
	if(n == 1)
		return n;
	else
		return SumToN(n - 1) + n;
}

bool Recursion::BinarySearch(array<int>^ dataValues, int target, int lBound, int uBound)
{
	if(lBound > uBound)
		return false;

	int mid = (lBound + uBound) / 2;

	if(dataValues[mid] == target)
		return true;
	else if(dataValues[mid] < target)
		return BinarySearch(dataValues, target, mid + 1, uBound);
	else
		return BinarySearch(dataValues, target, lBound, mid - 1);
}