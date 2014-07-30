#pragma once

#include "TStack.h"
#include "TQueue.h"

ref class TestHarness
{
public:
	TestHarness();

public:
	void RunTests()
	{

	}

public:
	void PushTestInt()
	{
		TStack<int>^ target = gcnew TStack<int>(); 
		
		int data = 5;

		target->Push(data);

		int  expected = 5; 
		int  actual;
		actual = target->Peek();

		

		//Assert::AreEqual(expected, actual);
	}

public:
	ref class Assert
	{
	public:
		void AreEqual(int expected, int actual)
		{
		//	if(expected.Equals(actual))
				////throw gcnew StackOverflowException("You are trying to push a null item");

		}
	};
};


