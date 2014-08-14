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
			
			tbDisplay->Text =	"Recursive permutation\n\nRepetition:\n" + 
								p->Permute("", 1, 3) + 
								"\n\nBool Array:\n" + 
								p->Permute("", gcnew array<bool>(3), 1, 3);
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
	private: System::Windows::Forms::RichTextBox^  tbDisplay;
	protected: 

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
			this->tbDisplay = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// tbDisplay
			// 
			this->tbDisplay->BackColor = System::Drawing::SystemColors::Control;
			this->tbDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbDisplay->Location = System::Drawing::Point(0, 0);
			this->tbDisplay->Name = L"tbDisplay";
			this->tbDisplay->Size = System::Drawing::Size(284, 261);
			this->tbDisplay->TabIndex = 0;
			this->tbDisplay->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->tbDisplay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

