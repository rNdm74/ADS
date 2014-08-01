// charlal1_linear_data_structures.cpp : main project file.

#include "stdafx.h"
#include "BalancedBracesParser.h"


using namespace System;

int main(array<System::String ^> ^args)
{
	BalancedBracesParser^ bbp = gcnew BalancedBracesParser();

	String^ line = nullptr;

	while(line != "q")
	{	
		Console::Write("Enter expression to parse or q to quit:");
		line = Console::ReadLine();
		Console::WriteLine("Result: " + bbp->Parse(line));
	}
	
	return 0;
}
