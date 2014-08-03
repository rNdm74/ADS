#pragma once

#include "LinkedListStack.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class BalancedBracesParser
{
public:
	BalancedBracesParser();
	bool Parse( String^ s );
private:
	array<wchar_t>^ ParseBraces( String^ s );
};
