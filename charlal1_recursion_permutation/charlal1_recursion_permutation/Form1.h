#pragma once

#include "Permutation.h"

namespace charlal1_recursion_permutation {

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
			Permutation^ p = gcnew Permutation();

			//String^ input = "123";
			//array<wchar_t>^ i = input->ToCharArray();

			//p->Permute(i, 0);

			

			//p->PermuteV2("", 1, 3);

			//String^ permutation = p->result;
			
			//array<bool>^ used = gcnew array<bool>(4);

			p->PermuteV3("", gcnew array<bool>(3), 1, 3);

			String^ permutation = p->result;

			/*for(int i = 0; i < result->Length; i++)
			{
				permutation += result[i];

				if(i == 3)
					permutation += ",";

				if(i > 3 && i % 3 == 0)
					permutation += ",";
			}*/

			MessageBox::Show(p->result);
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

