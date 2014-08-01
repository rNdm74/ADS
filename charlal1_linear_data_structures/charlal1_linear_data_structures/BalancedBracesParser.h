#pragma once

#include "TStack.h"

using namespace System;

ref class BalancedBracesParser
{
public:
	BalancedBracesParser();
	bool IsBalanced(String^ s);

private: 
	TStack<char>^ stack;
};
