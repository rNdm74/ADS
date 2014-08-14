#include "StdAfx.h"
#include "Recursion.h"

Recursion::Recursion(void)
{
}

/// <summary>
/// Summary for ReverseIt
///	
/// PRE-CONDITION: Must input type String^	
/// POST-CONDITION: Returns a String^, that has been reversed
///					
/// </summary>
String^ Recursion::ReverseIt(String^ s)
{
	if(s->Length == 1)
		return s;
	else
		return ReverseIt(s->Substring(1, s->Length - 1)) + s[0]; // append the first char to the end of the string
}

/// <summary>
/// Summary for RemoveIt
///	
/// PRE-CONDITION:	Takes to String^'s t assuming is 1 char long 
///					and the string you want to you want to remove the char from.
/// POST-CONDITION: Output is a string, with the first removed instance of t
///					this will continue untill all instances of t has been removed
///					
/// </summary>
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

/// <summary>
/// Summary for PowerOfThree
///	
/// PRE-CONDITION:	Input int that you want to test is a power of three	
/// POST-CONDITION: Output is a bool, on each call the number new input 
///					number is devided by three untill the base case is reached
///					
/// </summary>
bool Recursion::PowerOfThree(int n)
{
	// lowest number divisible by 3
	if(n == 1)
		return true;

	// if the number is not modulo of 3 cannot divide evenly
	if(n % 3 == 1)
		return false;
	else
		return PowerOfThree(n / 3); // devide n by 3
}

/// <summary>
/// Summary for Palindrome
///	
/// PRE-CONDITION:  Takes a String^ to test if palindrome	
/// POST-CONDITION:	Returns true or false if palindrome or not
///					On each call the input string first and last chars are tested 
///					then recalled with with a string not including the two tested chars
///					
/// </summary>
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

/// <summary>
/// Summary for SumToN
///	
/// PRE-CONDITION:	Integer that you want to sum 
/// POST-CONDITION: Returns int that has been added to itself -1 
///					
/// </summary>
int Recursion::SumToN(int n)
{
	if(n == 1)
		return n;
	else
		return SumToN(n - 1) + n;
}

/// <summary>
/// Summary for BinarySearch
///	
/// PRE-CONDITION:	Accepts a sorted array of integerValues, the search target 
///					upper and lower of the array you want to search
/// POST-CONDITION: The array is not changed, a bool is returned on 5 cases
///					1. lower bound is greater than upper bound
///					2. return true if array[mid] = target
///					3. if target is in upper
///					4. if target is in lower
///					5. return if target not in upper or lower
///					
/// </summary>
bool Recursion::BinarySearch(array<int>^ dataValues, int target, int lBound, int uBound)
{
	// Not found if lower is greater than upper
	if(lBound > uBound)
		return false;

	// Get the middle of the lower and upper bounds
	int mid = (lBound + uBound) / 2;

	// If the target is the mid you have found
	if(dataValues[mid] == target)
		return true;
	else if(dataValues[mid] < target) // Target is in upper
		return BinarySearch(dataValues, target, mid + 1, uBound);
	else if(dataValues[mid] > target) // Target is in lower
		return BinarySearch(dataValues, target, lBound, mid - 1);
	else 
		return false; // Target not in list
}