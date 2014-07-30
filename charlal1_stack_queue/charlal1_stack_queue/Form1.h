#pragma once

#include "TStack.h"
#include "TQueue.h"
#include "TestHarness.h"


namespace charlal1_stack_queue {

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
			
			TStack<char>^ stack = gcnew TStack<char>();
			TQueue<int>^ queue = gcnew TQueue<int>();

			stack->Push('a');
			stack->Push('b');
			stack->Push('c');

			char charTest1 = stack->Pop();
			char charTest2 = stack->Pop();
			char charTest3 = stack->Pop();
			
			queue->Push(1);
			queue->Push(2);
			queue->Push(3);

			int intTest1 = queue->Pop();
			int intTest2 = queue->Pop();
			int intTest3 = queue->Pop();

			//stack->Peek();
			//queue->Peek();

			for(int i = 0; i < 10000; i++)
				queue->Push(i);

			for(int i = 0; i < 10000; i++)
				lbDisplay->Items->Add(queue->Pop());

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
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

