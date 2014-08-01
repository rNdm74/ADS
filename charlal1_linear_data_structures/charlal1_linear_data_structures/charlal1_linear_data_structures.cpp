// charlal1_linear_data_structures.cpp : main project file.

#include "stdafx.h"
#include "BalancedBracesParser.h"


using namespace System;

int main(array<System::String ^> ^args)
{
	BalancedBracesParser^ bbp = gcnew BalancedBracesParser();

	String^ line = "";

	while(line != "q")
	{	
		Console::Write("Enter express to parse or q to quit:");
		String^ line = Console::ReadLine();
		Console::WriteLine("Result: " + bbp->IsBalanced(line));
	}
	
	return 0;
}
