#pragma once

#include "Patient.h"

namespace charlal1_priority_queue_lab_2 
{
	ref class PriorityQueue
	{
	public:
		PriorityQueue(int size);
		void Push(Patient^ patient);
		Patient^ Pop();
		Patient^ Peek();
		int Count();
		bool IsEmpty();
	private:
		array<Patient^>^ stack;
		int stackCounter;
		int stackPointer;
		int stackPointerReset;
	};
}