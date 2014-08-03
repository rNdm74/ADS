#include "StdAfx.h"
#include "BalancedBracesParser.h"

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	No change
/// POST-CONDITION: No change 
/// </summary>
BalancedBracesParser::BalancedBracesParser()
{
	
}

/// <summary>
/// Summary for Parse
///	
/// PRE-CONDITION:	Must provide a String^ pointer
/// POST-CONDITION: No global variables are changed, private function is used to pull braces from input String^ s
///					Private function:
///					ParseBraces()				- Returns array<wchar_t>
///					Local variables created:
///					array<wchar_t>				- Char array from input String^ s
///					LinkedListStack<wchar_t>^	- Stack to hold chars FIFO
///					wchar_t						- Hold result of pop
///					int							- Track iteration over array<wchar_t>
///					Result:
///					Boolean returned if braces balance
/// </summary>
bool BalancedBracesParser::Parse( String^ s )
{
	// Get all braces from string
	array<wchar_t>^ braces = ParseBraces(s);

	// Throw error if no braces in string
	if( braces->Length <= 0 )
		throw gcnew Exception( "No braces found" );
	
	// Create stack for parse
	LinkedListStack<wchar_t>^ stack = gcnew LinkedListStack<wchar_t>();

	// Loop variables
	wchar_t result = '\0';
	int iterator = 0;

	// There is a char to test
	while( iterator < braces->Length )
	{
		// Test for open/closed braces
		switch( braces[iterator] )
		{
			// Look for opening braces add to stack
			case '[': case '{': case '(': 
				stack->Push( braces[iterator] );
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

			default:
				return false;
		}

		// Move to next char
		iterator++;
	}	
	
	// Return true if reach here with empty stack
	return stack->IsEmpty();
}

/// <summary>
/// Summary for ParseBraces
///	
/// PRE-CONDITION:	Must provide a String^ pointer, expect array<wchar_t> returned
/// POST-CONDITION: No global variables are changed,
///					Local variables created:
///					Two String^s				- One hold brace matches, Two hold found braces	
///					IEnumerator^				- Enumerator for looping over String^
///					Result:
///					array<wchar_t>^ of braces from the input string
/// </summary>
array<wchar_t>^ BalancedBracesParser::ParseBraces( String^ s )
{
	// Specify the matches 
	String^ matches = "{}[]()";

	// Holder for mathes found
	String^ result = "";

	// Get the enumerator of the incoming string
	array<wchar_t>^ expression = s->ToCharArray();

	int iterator = 0;
    	
	// Loop through each char
	while ( iterator < expression->Length )
    {
		String^ item = Convert::ToString( expression[iterator] );
	   
		// If it is a match add to the result string
	    if( matches->Contains( item ) )
			result += item;

	    iterator++;
    }		

	// Return char array
	return result->ToCharArray();
}