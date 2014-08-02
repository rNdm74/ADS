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
	LinkedListStack<wchar_t>^ stack = gcnew LinkedListStack<wchar_t>();
	// Create queue for parse
	LinkedListQueue<wchar_t>^ queue = gcnew LinkedListQueue<wchar_t>();

	// Loop variables
	int iterator = 0;

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