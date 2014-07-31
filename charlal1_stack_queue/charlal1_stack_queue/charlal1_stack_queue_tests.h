#pragma once

#include "TStack.h"
#include "TQueue.h"

using namespace System;
using namespace System::Windows::Forms;

ref class charlal1_stack_queue_tests
{
public:
	charlal1_stack_queue_tests(void);
	void RunTests();
	String^ TestPushInt();
};
