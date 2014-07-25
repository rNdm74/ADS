#pragma once

using namespace System;
using namespace System::Collections;

ref class Patient: public IComparable
{
public:
	Patient(int priority, String^ name);

	virtual Int32 CompareTo( Object^ obj ) 
	{
      if (obj == nullptr) return 1;

	  if ( obj->GetType() == Patient::typeid ) {
         Patient^ patient = dynamic_cast<Patient^>(obj);

		 return this->Priority.CompareTo( patient->Priority );
      }

      throw gcnew ArgumentException(  "object is not a Patient" );
    }

	property String^ Name
	{
		String^ get()
		{
			return name;
		}
		void set(String^ value)
		{
			name = value;
		}
	}

	property int Priority
	{
		int get()
		{
			return priority;
		}
		void set(int value)
		{
			priority = value;
		}
	}

private:
	int priority;
	String^ name;



};
