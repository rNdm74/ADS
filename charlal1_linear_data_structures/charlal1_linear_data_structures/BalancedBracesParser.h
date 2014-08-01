#pragma once

#include "LinkedListStack.h"

using namespace System;
using namespace System::Runtime::InteropServices;

ref class BalancedBracesParser
{
public:
	BalancedBracesParser();
	bool IsBalanced(String^ s);
	bool Parse(String^ line);
};
