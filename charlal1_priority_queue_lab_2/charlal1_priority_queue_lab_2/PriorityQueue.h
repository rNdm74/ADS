#pragma once

#include "Patient.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class PriorityQueue
{
public:
	PriorityQueue(int size);
	void Push(Patient^ patient);
	Patient^ Pop();
	Patient^ Peek();
	int Count();
	bool isEmpty();
private:
	array<Patient^>^ stack;
};
