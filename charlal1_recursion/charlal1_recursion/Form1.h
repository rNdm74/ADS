#pragma once

#include "Recursion.h"
#include "MergeSort.h"

namespace charlal1_recursion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			lbDisplay->Items->Add("Recursion labs");
			Recursion^ r = gcnew Recursion();
			lbDisplay->Items->Add("");

			// ReverseIt example
			lbDisplay->Items->Add("ReverseIt example");
			lbDisplay->Items->Add("Input: abcde");
			String^ reverseIt = r->ReverseIt("abcde");
			lbDisplay->Items->Add("Output: " + reverseIt);
			lbDisplay->Items->Add("");
			
			// SumToN example
			lbDisplay->Items->Add("SumToN example");
			lbDisplay->Items->Add("Input: 5");
			int sumToN = r->SumToN(5);
			lbDisplay->Items->Add("Output: " + sumToN);
			lbDisplay->Items->Add("");

			// Palindrome example
			lbDisplay->Items->Add("Palindrome example");
			lbDisplay->Items->Add("Input: abcba");
			bool palindrome = r->Palindrome("abcba");
			lbDisplay->Items->Add("Output: " + palindrome);
			lbDisplay->Items->Add("");

			// PowerOfThree example
			lbDisplay->Items->Add("Palindrome example");
			lbDisplay->Items->Add("Input: 21");
			bool powerOfThree = r->PowerOfThree(21);
			lbDisplay->Items->Add("Output: " + powerOfThree);
			lbDisplay->Items->Add("");

			// RemoveIt example
			lbDisplay->Items->Add("RemoveIt example");
			lbDisplay->Items->Add("Input: The quick brown fox jumped over the lazy dog");
			lbDisplay->Items->Add("Remove: o");
			String^ removeIt = r->RemoveIt("o","The quick brown fox jumped over the lazy dog");
			lbDisplay->Items->Add("Output: " + removeIt);
			lbDisplay->Items->Add("");

			// Recursive mergesort example
			lbDisplay->Items->Add("Recursive mergesort example");
			lbDisplay->Items->Add("Input: array<int>^ numbers - random integers, size: 50");
			Random^ rGen = gcnew Random();
			array<int>^ numbers = gcnew array<int>(50);
			// Test number for binary search
			numbers[0] = 50;
			// Populate the array
			for(int i = 1; i < numbers->Length; i++)
				numbers[i] = rGen->Next(49);
			// String for array before mergesort
			String^ before = "";
			for(int i = 1; i < numbers->Length; i++)
				before += numbers[i]+ " ";
			//
			lbDisplay->Items->Add("Input: " + before);
			// Mergesort numbers
			MergeSort^ s = gcnew MergeSort();
			s->MergeRecursive( numbers, 0 , numbers->Length - 1 );
			// String for array after mergesort
			String^ after = "";
			for(int i = 1; i < numbers->Length; i++)
				after += numbers[i]+ " ";
			//
			lbDisplay->Items->Add("Output: " + after);
			lbDisplay->Items->Add("");

			// BinarySearch example
			lbDisplay->Items->Add("BinarySearch example");
			lbDisplay->Items->Add("Input: sorted array of numbers");
			lbDisplay->Items->Add("Input: " + after);
			lbDisplay->Items->Add("Search target: 49");
			bool binarySearch = r->BinarySearch(numbers, 49, 0, numbers->Length - 1);
			lbDisplay->Items->Add("Output: " + binarySearch);

			// Resfresh listbox
			lbDisplay->Refresh();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbDisplay;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// lbDisplay
			// 
			this->lbDisplay->BackColor = System::Drawing::SystemColors::Control;
			this->lbDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->lbDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lbDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->ItemHeight = 20;
			this->lbDisplay->Location = System::Drawing::Point(0, 0);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(284, 260);
			this->lbDisplay->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->lbDisplay);
			this->Name = L"Form1";
			this->Text = L"Recursion";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

