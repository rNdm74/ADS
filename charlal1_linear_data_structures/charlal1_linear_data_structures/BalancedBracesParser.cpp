#include "StdAfx.h"
#include "BalancedBracesParser.h"

BalancedBracesParser::BalancedBracesParser()
{
	stack = gcnew TStack<char>();
}

bool BalancedBracesParser::IsBalanced(String^ s)
{
	// Assume string has balanced braces
	bool isBalanced = true;

	// Loop through each char in s
	for(int c = 0; c < s->Length; c++)
	{
		// Push opening braces to stack
		if(s[c] == '{')
		{
			stack->Push(s[c]);
		}
		else if(s[c] == '}') // On closing brace found
		{
			// If we can pop stack matching brace found
			// Else set the isBalanced flag to false
			if(!stack->IsEmpty())
				stack->Pop();
			else
				isBalanced = false;
		}
	}

	// if stack->Count() is greater than 1
	// once finished looping and there is still braces in the stack 
	// there is a uneven number set isBalanced flag to false
	int count = stack->Count();
	if(count > 0)
		isBalanced = false;

	//isBalanced = s->Contains("{");

	return isBalanced;
}