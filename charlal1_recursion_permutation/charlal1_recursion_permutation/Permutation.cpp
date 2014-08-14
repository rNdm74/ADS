#include "StdAfx.h"
#include "Permutation.h"

Permutation::Permutation(void)
{
	result = "|";
}

void Permutation::Permute(array<wchar_t>^ s, int n)
{
	int j;

	if(n == s->Length)
	{

		result += gcnew String(s) + "|";
	}
	else
		for(j = n; j < s->Length; j++)
		{
			Swap(s, n, j);

			Permute(s, n + 1);
			
			Swap(s, j, n);
		}
}

void Permutation::Swap(array<wchar_t>^ s, int c1, int c2)
{
	wchar_t t = s[c1];
	s[c1] = s[c2];
	s[c2] = t;
}

void Permutation::PermuteV2(String^ temp, int startingLocation, int itemsToPermute)
{
	/*for (int aa = 1; aa <= itemsToPermute; aa++)
    {
        for (int bb = 1; bb <= itemsToPermute; bb++)
        {
            for (int cc = 1; cc <= itemsToPermute; cc++)
            {
                result += aa + "" + bb + "" + cc + "" + " | ";
            }
        }
    }*/
	
	if(startingLocation <= itemsToPermute)
	{
		for (int i = 1; i <= itemsToPermute; i++)
		{
			PermuteV2(temp + Convert::ToString(i), startingLocation + 1, itemsToPermute);
		}
	}
	else
	{
		result += temp + " ";

	}
}

void Permutation::PermuteV3(String^ temp, array<bool>^ used, int startingLocation, int itemsToPermute)
{
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
				PermuteV3(temp + Convert::ToString(i), used, startingLocation + 1, itemsToPermute);

				// Reset
				used[j] = false;
			}
		}
	}
	else
	{		
		// Output
		result += temp + " ";
	}
}