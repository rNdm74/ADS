#include "StdAfx.h"
#include "Recursion.h"

Recursion::Recursion(void)
{
}

String^ Recursion::ReverseIt(String^ s)
{
	if(s->Length == 1)
	{
		return s;
	}
	else
	{
		return s + ReverseIt(s->Substring(1, s->Length - 1));
	}
}