#pragma once

#include "StdAfx.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

template<class T> 
ref class Table
{
private:
	array<T>^ database;
	DataGridView^ dataGridView;
	List<String^>^ log;
public:
	Table(int size, DataGridView^ dataGridView);
	void InsertItem(int key, T t);
	void DisplayTable();
	T FindItem(int key);
	void DeleteItem(int key);
	void LoadFromFile(OpenFileDialog^  openFileDialog);	
	void DisplayLog(ListBox^ lb);
};


template<class T> 
Table<T>::Table(int size, DataGridView^ dataGridView)
{
	this->database = gcnew array<T>(size);
	this->dataGridView = dataGridView;
	this->log = gcnew List<String^>();
};

template<class T> 
void Table<T>::DisplayLog(ListBox^ lb)
{
	lb->Items->AddRange(log->ToArray());	
};

template<class T> 
void Table<T>::InsertItem(int key, T t)
{
	int id = Convert::ToInt16(t->ID);
	log->Add("Inserting: " + id);

	int hash = (id % database->Length);
	log->Add("Hashed value: " + hash);

	log->Add("Checking for collision...");
    while ( database[hash] != nullptr && Convert::ToInt16(database[hash]->ID) != id )
	{    
		log->Add("Collision found!");
		hash = (hash + 1) % database->Length;		
		log->Add("New hash: " + hash);
	}

    if (database[hash] != nullptr)
	{
		log->Add("Clearing hash position");
        delete database[hash];		  
	}

	log->Add("No collision!");
	log->Add("Adding: " + hash);
	log->Add("");
	database[hash] = t;
};

template<class T> 
void Table<T>::DisplayTable()
{
	dataGridView->Rows->Clear();

	for(int i = 0; i < database->Length; i++)
	{
		T t = database[i];
		
		if(t != nullptr)
		{
			dataGridView->Rows->Add(database[i]->ToArray());			
		}	
		else
		{
			dataGridView->Rows->Add(1);
		}		
	}
};

template<class T> 
T Table<T>::FindItem(int key)
{
	int hash = (key % database->Length);
    
	while (database[hash] != nullptr && Convert::ToInt16(database[hash]->ID) != key)
          hash = (hash + 1) % database->Length;
    
	T t = database[hash];

	if(t != nullptr)
		return t;
	else
		throw gcnew Exception("Item not in database");
};

template<class T> 
void Table<T>::DeleteItem(int key)
{
	int hash = (key % database->Length);
    
	while (database[hash] != nullptr && Convert::ToInt16(database[hash]->ID) != key)
          hash = (hash + 1) % database->Length;

	if(database[hash] != nullptr)
		database[hash] = nullptr;
	else
		throw gcnew Exception("Item not in database");
};

template<class T> 
void Table<T>::LoadFromFile(OpenFileDialog^  openFileDialog)
{
	if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(openFileDialog->FileName);

		int count = 0;

		while(!sr->EndOfStream)
		{

			String^ line = sr->ReadLine();
			array<String^>^ obj = line->Split(',');

		 
			Animal^ a = gcnew Animal(obj);
			int key = Convert::ToInt16(a->ID);

			InsertItem(key, a);

			count++;
		}

		sr->Close();
	}
};