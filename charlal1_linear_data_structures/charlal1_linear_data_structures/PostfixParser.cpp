#include "StdAfx.h"
#include "PostfixParser.h"

PostfixParser::PostfixParser()
{
}

int PostfixParser::Parse( String^ s )
{
	// Get all braces from string
	array<wchar_t>^ expression = s->ToCharArray();

	// Create stack for parse
	LinkedListStack<int>^ stack = gcnew LinkedListStack<int>();

	// Loop variables
	int first;
	int second;
	int iterator;

	// There is a char to test
	while( iterator < expression->Length )
	{
		switch( expression[iterator] )
		{
			// Look for opening braces add to stack
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

			default:
				if( expression[iterator] >= '0' && expression[iterator] <= '9' )
				{
					stack->Push( expression[iterator] - 48 );
				}
				else
				{
					throw gcnew Exception( "Expression must be all numbers" );
				}
			break;
		}

		iterator++;
	}
	
	return stack->Pop();
}