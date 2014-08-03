#include "StdAfx.h"
#include "PostfixParser.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No change
/// POST-CONDITION: No change 
/// </summary>
PostfixParser::PostfixParser()
{
}

/// <summary>
/// Summary for Parse
///	
/// PRE-CONDITION:	Must provide a String^ pointer
/// POST-CONDITION: No global variables are changed, 
///					Local variables created:
///					array<wchar_t>			- Char array from input String^ s
///					LinkedListStack<int>^	- Stack to hold integers and totals
///					3x int					- Two for data when poped from stack, and one to track iteration over array<wchar_t>
///					Result:
///					Return result, always last entry in stack
/// </summary>
int PostfixParser::Parse( String^ s )
{
	// Get array<wchar_t> for parse
	array<wchar_t>^ expression = s->ToCharArray();

	// Create stack for parse
	LinkedListStack<int>^ stack = gcnew LinkedListStack<int>();

	// Loop variables
	int first = 0;
	int second = 0;
	int iterator = 0;

	// There is a char to test
	while( iterator < expression->Length )
	{
		switch( expression[iterator] )
		{
			// Look for opening braces add to stack
			// When operator chars "+-*/" found pop twice to get integers 
			// Push result back to stack
			case '+':
				first = stack->Pop();
				second = stack->Pop();
				stack->Push(first + second);
			break;

			case '-':
				first = stack->Pop();
				second = stack->Pop();
				stack->Push(second - first);
			break;

			case '*': 
				first = stack->Pop();
				second = stack->Pop();
				stack->Push(first * second);
			break;

			case '/': 
				first = stack->Pop();
				second = stack->Pop();
				stack->Push(second / first);
			break;

			// If no operators found must be integer for processing
			default:
				// Test for valid number else throw exception
				if( expression[iterator] >= '0' && expression[iterator] <= '9' )
				{
					// Push number to stack
					stack->Push( expression[iterator] - 48 ); // Subract char code '0' to convert char to int
				}
				else
				{
					throw gcnew Exception( "Expression must be all numbers" );
				}
			break;
		}

		// Move to next char
		iterator++;
	}
	
	// Return result
	return stack->Pop();
}