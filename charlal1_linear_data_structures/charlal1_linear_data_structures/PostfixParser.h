#pragma once

#include "LinkedListStack.h"

using namespace System;
using namespace System::Collections;

ref class PostfixParser
{
public:
	PostfixParser();
	int Parse( String^ s );
};
