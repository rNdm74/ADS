#include "StdAfx.h"
#include "BalancedBracesParser.h"

BalancedBracesParser::BalancedBracesParser()
{
	
}

bool BalancedBracesParser::IsBalanced(String^ s)
{
	// Test if the string has "{}"
	if(s->Contains("{") == false || s->Contains("}") == false)
		return false;

	LinkedListStack<char>^ stack = gcnew LinkedListStack<char>();

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
			if(stack->IsEmpty() == false)
				stack->Pop();
			else
				isBalanced = false;
		}
	}

	// if stack->Count() is greater than 1
	// once finished looping and there is still braces in the stack 
	// there is a uneven number set isBalanced flag to false	
	if(stack->Count() > 0)
		isBalanced = false;

	return isBalanced;
}

bool BalancedBracesParser::Parse(String^ line)
{
	// Create stack for parse
	LinkedListStack<char>^ stack = gcnew LinkedListStack<char>();

	// Copy contents of managed String into native heap  
	char *expression = (char*)(void*)Marshal::StringToHGlobalAnsi(line);	

	// Pop output
	char result;

	// There is a char to test
	while(*expression)
	{
		// Test for open/closed braces
		switch(*expression)
		{
			// Look for opening braces add to stack
			case '[': case '{': case '(': 
				stack->Push( *expression );
			break;

			// Test for closing braces on all cases " ] } ) "
			// If stack isEmpty and result of Pop does not match expected
			// Input string has unbalanced braces
			case ']':				
				if( stack->IsEmpty() )
					return false;

				result = stack->Pop();

				if( result != '[' )
					return false;
			break;

			case '}':
				if( stack->IsEmpty() )
					return false;

				result = stack->Pop();

				if( result != '{' )
					return false;
			break;

			case ')':
				if( stack->IsEmpty() )
					return false;

				result = stack->Pop();

				if( result != '(' )
					return false;
			break;

			// Ignore all other characters
			default:
				break;
		}

		// Move to next char
		expression++;
	}	
	
	// Return true if reach here with empty stack
	return stack->IsEmpty();
}