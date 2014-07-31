#include "StdAfx.h"
#include "charlal1_stack_queue_tests.h"

charlal1_stack_queue_tests::charlal1_stack_queue_tests(void)
{
}

void charlal1_stack_queue_tests::RunTests()
{
	
	MessageBox::Show("Hello");
}

String^ charlal1_stack_queue_tests::TestPushInt()
{
	TStack<int>^ target = gcnew TStack<int>(); 
	
	int data = 5;

	target->Push(data);

	int  expected = 5; 
	int  actual;
	actual = target->Peek();

	if(expected == actual)
		return "Pass";
	else
		return "Fail";
}
