#include "StdAfx.h"
#include "PalindromeParser.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No change
/// POST-CONDITION: No change 
/// </summary>
PalindromeParser::PalindromeParser()
{
}

/// <summary>
/// Summary for Parse
///	
/// PRE-CONDITION:	Must provide a String^ pointer
/// POST-CONDITION: No global variables are changed, 
///					Local variables created:
///					array<wchar_t>			- Char array from input String^ s
///					LinkedListStack<char>^	- Stack to hold chars FIFO
///					LinkedListQueue<char>^	- Queue to hold chars LIFO
///					int						- Track iteration over array<wchar_t>
///					Result:
///					Boolean returned if palindrome found 
/// </summary>
bool PalindromeParser::Parse( String^ s )
{
	// Get array<wchar_t> for parse
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
		// Fill the stack and queue
		stack->Push( expression[iterator] );
		queue->Push( expression[iterator] );

		// Move to next char
		iterator++;
	}
	
	// Loop through stack and queue while they are BOTH not empty
	while( stack->IsEmpty() == false && queue->IsEmpty() == false )
		if( stack->Pop() != queue->Pop() ) // If resulting pops do not match return false
			return false;

	// If get to here must be palindrome
	return true;
}