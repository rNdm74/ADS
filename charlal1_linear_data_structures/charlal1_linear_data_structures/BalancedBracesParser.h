#pragma once

#include "LinkedListStack.h"

using namespace System;
using namespace System::Collections;

ref class BalancedBracesParser
{
public:
	BalancedBracesParser();
	bool Parse( String^ s );
private:
	array<wchar_t>^ ParseBraces( String^ s );
};
