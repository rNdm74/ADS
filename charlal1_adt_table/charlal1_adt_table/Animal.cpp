#include "StdAfx.h"
#include "Animal.h"

Animal::Animal()
{
}

Animal::Animal(array<String^>^ data)
{
	this->ID			= data[0];
	this->Name			= data[1];
	this->Species		= data[2];
	this->CageNumber	= data[3];
	this->Age			= data[4];
	this->Food			= data[5];
}