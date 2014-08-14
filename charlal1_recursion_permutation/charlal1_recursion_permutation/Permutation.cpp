#include "StdAfx.h"
#include "Permutation.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	
/// POST-CONDITION: String^ out is initialized
///					
/// </summary>
Permutation::Permutation(void)
{
	out = "";
}

/// <summary>
/// Summary for Permute with repetition
///	
/// PRE-CONDITION:	Must provide String^, and two integers.
///					1: The starting value 
///					2: The number of items to permute
/// POST-CONDITION:	Will return the output string on each call
///					On first run the out string will be set to temp
///					String^ temp will be appended with the loop int
///					int startingLocation will be incremented by 1
///					No change to itemsToPermute
///	
///					
/// </summary>
String^ Permutation::Permute(String^ temp, int startingLocation, int itemsToPermute)
{
	/** Example of iterative
	 *
	 *	for (int aa = 1; aa <= itemsToPermute; aa++)
	 *	{
     *		for (int bb = 1; bb <= itemsToPermute; bb++)
     *		{
     *			for (int cc = 1; cc <= itemsToPermute; cc++)
     *			{
     *				result += aa + "" + bb + "" + cc + "" + " | ";
     *			}
     *		}
	 *	}
	 *
     */

	// Reset output string
	if(temp == "")
		out = temp;
	
	//
	if(startingLocation <= itemsToPermute)
	{
		// Recursive loop
		for (int i = 1; i <= itemsToPermute; i++)
		{
			// 
			Permute(temp + Convert::ToString(i), startingLocation + 1, itemsToPermute);
		}
	}
	else
	{
		// Print output
		out += temp + " ";		
	}

	return out;
}

/// <summary>
/// Summary for Permute with repetition
///	
/// PRE-CONDITION:	Must provide String^, array<bool>^ and two integers.
///					array<bool>^ must be the same size as the itemsToPermute 
///					1: The starting value 
///					2: The number of items to permute
/// POST-CONDITION:	Will return the output string on each call
///					On first run the out string will be set to temp
///					String^ temp will be appended with the loop int
///					int startingLocation will be incremented by 1
///					No change to itemsToPermute
///	
///					
/// </summary>
String^ Permutation::Permute(String^ temp, array<bool>^ used, int startingLocation, int itemsToPermute)
{
	// Reset output on first run
	if(temp == "")
		out = temp;

	//
	if(startingLocation <= itemsToPermute)
	{
		for (int i = 1; i <= itemsToPermute; i++)
		{
			// Zero based array
			int j = i - 1;

			// Only process when used bool is false
			if(used[j] == false)
			{
				// Using that position
				used[j] = true;				

				// Get next number
				Permute(temp + Convert::ToString(i), used, startingLocation + 1, itemsToPermute);

				// Reset
				used[j] = false;
			}
		}
	}
	else
	{		
		// Output
		out += temp + " ";		
	}

	return out;
}

/// <summary>
/// Summary for Permute EXPERIMENT
///	
/// PRE-CONDITION:	Must provide array, the starting value
/// POST-CONDITION: 
///					
/// </summary>
void Permutation::Permute(array<wchar_t>^ s, int n)
{
	int j;

	if(n == s->Length)
	{

		out += gcnew String(s) + "|";
	}
	else
		for(j = n; j < s->Length; j++)
		{
			Swap(s, n, j);

			Permute(s, n + 1);
			
			Swap(s, j, n);
		}
}

/// <summary>
/// Summary for Swap for permute EXPERIMENT
///	
/// PRE-CONDITION:	Must provide array, and the two position that are being swapped
/// POST-CONDITION: 
///					
/// </summary>
void Permutation::Swap(array<wchar_t>^ s, int c1, int c2)
{
	wchar_t t = s[c1];
	s[c1] = s[c2];
	s[c2] = t;
}