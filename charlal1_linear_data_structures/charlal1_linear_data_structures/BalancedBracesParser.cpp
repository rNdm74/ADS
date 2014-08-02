#include "StdAfx.h"
#include "BalancedBracesParser.h"

BalancedBracesParser::BalancedBracesParser()
{
	
}

bool BalancedBracesParser::Parse( String^ s )
{
	// Get all braces from string
	array<wchar_t>^ braces = ParseBraces(s);

	// Throw error if no braces in string
	if( braces->Length <= 0 )
		throw gcnew Exception( "No braces found" );
	
	// Create stack for parse
	LinkedListStack<char>^ stack = gcnew LinkedListStack<char>();

	// Loop variables
	char result;
	int iterator;

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

array<wchar_t>^ BalancedBracesParser::ParseBraces( String^ s )
{
	// Specify the matches 
	String^ matches = "{}[]()";

	// Holder for mathes found
	String^ result = "";

	// Get the enumerator of the incoming string
	IEnumerator^ myEnum = s->GetEnumerator();
    	
	// Loop through each char
	while ( myEnum->MoveNext() )
    {
		// Get the char
       Char^ entry = safe_cast<Char^>( myEnum->Current );

	   // If it is a match add to the result string
	   if( matches->Contains( Convert::ToString( entry ) ) )
		   result += entry;
    }		

	// Return char array
	return result->ToCharArray();
}