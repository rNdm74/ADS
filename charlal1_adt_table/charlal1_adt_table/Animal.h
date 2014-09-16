#pragma once

using namespace System;

enum ANIMAL
{
	ID, NAME, SPECIES, CAGE_NUMBER, AGE, FOOD   
};

ref class Animal
{
public:
	String^ ID;
	String^ Name;
	String^ Species;
	String^ CageNumber;
	String^ Age;
	String^ Food;

	virtual String^ ToString() override
    {
        return	ID + ", " +
				Name + ", " +
				Species + ", " +
				CageNumber + ", " +
				Age + ", " +
				Food;
    };

	array<String^>^ ToArray()
	{
		return gcnew array<String^>{
			ID,
			Name,
			Species,
			CageNumber,
			Age,
			Food
		};
	};

	Animal();
	Animal(array<String^>^ data);
};
