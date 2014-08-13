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

void Permutation::PermuteV2(int startingLocation, int itemsToPermute)
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
	

	for (int cc = 1; cc <= itemsToPermute; cc++)
	{
		result += cc + "";
		
		if(startingLocation <= itemsToPermute)
		{	
			PermuteV2(startingLocation + 1, itemsToPermute);			
		}
		else
		{
			result += " | ";
		}

		
	}

	

	

	
	//array<wchar_t>^ s = gcnew array<wchar_t>(itemsToPermute);
	//int temp;
	//
	//if( startingLocation == itemsToPermute)
	//{
	//	return Convert::ToString(startingLocation);
	//}
	//else
	//{
	//	

	//	for(int i = 1; i <= itemsToPermute; i++)
	//	{
	//		//for(int j = 1; j < itemsToPermute; j++)
	//		//temp = i;
	//		return i + PermuteV2(startingLocation + 1, itemsToPermute);
	//	}	

	//	
	//}
}
