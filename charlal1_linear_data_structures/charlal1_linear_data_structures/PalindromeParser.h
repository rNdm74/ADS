#pragma once

#include "LinkedListStack.h"
#include "LinkedListQueue.h"

using namespace System;
using namespace System::Collections;

ref class PalindromeParser
{
public:
	PalindromeParser();
	bool Parse( String^ s );
};