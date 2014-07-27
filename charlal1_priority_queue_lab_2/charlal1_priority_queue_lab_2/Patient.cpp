#include "StdAfx.h"
#include "Patient.h"

namespace charlal1_priority_queue_lab_2 
{
	Patient::Patient(int priority, String^ name)
	{
		this->priority = priority;
		this->name = name;
	}
}
