#include "StdAfx.h"
#include "Patient.h"

Patient::Patient(int priority, String^ name)
{
	this->priority = priority;
	this->name = name;
}
