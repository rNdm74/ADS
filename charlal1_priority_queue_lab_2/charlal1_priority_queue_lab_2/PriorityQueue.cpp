#include "StdAfx.h"
#include "PriorityQueue.h"
#include "Patient.h"

PriorityQueue::PriorityQueue(int size)
{
	stack = gcnew array<Patient^>(size);
}

void PriorityQueue::Push(Patient^ patient)
{
	// Checks on new patient

	// If checks pass

	// Find next avail position
	int next = 0;
	while( stack[next] != nullptr )
		next++;

	// Add patient to array at next avail position
	stack[next] = patient;

	// Sort array on priority number
	Array::Sort(stack);
}

Patient^ PriorityQueue::Pop()
{
	// Error checking can we pop a patient off the queue
	// Pop will always look at the first element in the queue 
	// Remove from the queue
	// Return patient
	return stack[stack->Length - 1];
}

Patient^ PriorityQueue::Peek()
{
	// Error checking can we pop a patient off the queue

	// Pop will always look at the first element in the queue 
	// Remove from the queue
	// Return patient
	return stack[stack->Length - 1];
}

int PriorityQueue::Count()
{
	int count = 0;

	while(stack[count] != nullptr)
		count++;

	return count;
}

bool PriorityQueue::isEmpty()
{
	return (stack->Length <= 0);
}