#include "StdAfx.h"
#include "PalindromeParser.h"

PalindromeParser::PalindromeParser()
{
}

bool PalindromeParser::Parse( String^ s )
{
	// Get all braces from string
	array<wchar_t>^ expression = s->ToCharArray();

	// Create stack for parse
	LinkedListStack<char>^ stack = gcnew LinkedListStack<char>();
	// Create queue for parse
	LinkedListQueue<char>^ queue = gcnew LinkedListQueue<char>();

	// Loop variables
	int iterator;

	// There is a char to test
	while( iterator < expression->Length )
	{
		stack->Push( expression[iterator] );
		queue->Push( expression[iterator] );
		iterator++;
	}
	
	while( stack->IsEmpty() == false && queue->IsEmpty() == false )
		if( stack->Pop() != queue->Pop() )
			return false;

	return true;
}