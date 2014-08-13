#pragma once

#include "Recursion.h"

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

			Recursion^ r = gcnew Recursion();

			String^ reverseIt = r->ReverseIt("abcde");
			int sumToN = r->SumToN(5);
			bool palindrome = r->Palindrome("abcba");
			bool powerOfThree = r->PowerOfThree(21);

			String^ removeIt = r->RemoveIt("o","The quick brown fox jumped over the lazy dog");


			Random^ rGen = gcnew Random();
			array<int>^ d = gcnew array<int>(100);

			d[0] = 50;

			for(int i = 1; i < d->Length; i++)
				d[i] = rGen->Next(49);

			Array::Sort(d);

			bool binarySearch = r->BinarySearch(d, 51, 0, d->Length - 1);


			MessageBox::Show("Finished");
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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"Form1";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}

