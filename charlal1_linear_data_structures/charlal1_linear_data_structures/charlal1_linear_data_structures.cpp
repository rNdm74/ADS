// charlal1_linear_data_structures.cpp : main project file.

#include "stdafx.h"
#include "BalancedBracesParser.h"
#include "PostfixParser.h"
#include "PalindromeParser.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	BalancedBracesParser^ p = gcnew BalancedBracesParser();
	//PostfixParser^ p = gcnew PostfixParser();
	//PalindromeParser^ p = gcnew PalindromeParser();
	
	String^ line = nullptr;

	while(line != "q")
	{	
		try
		{
			Console::Write("Enter expression to parse or q to quit:");
			line = Console::ReadLine();
			Console::WriteLine("Result: " + p->Parse(line));
		}
		catch(Exception^ e)
		{
			Console::WriteLine(e->Message);
		}		
	}
	
	return 0;
}
