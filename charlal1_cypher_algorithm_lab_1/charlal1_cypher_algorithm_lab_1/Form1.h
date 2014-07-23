#pragma once

#include "VigenereCipher.h"

namespace charlal1_cypher_algorithm_lab_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
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
	private: System::Windows::Forms::Button^  bLoadFile;
	private: System::Windows::Forms::ListBox^  lbDisplay;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: 
		/// <summary>
		/// Load file that contains cipher keys and text to be deciphered
		/// </summary>
		System::Void loadFile_Click(System::Object^  sender, System::EventArgs^  e) {

		List<String^>^ inputText = gcnew List<String^>();

		Stream^ myStream;

		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		openFileDialog->InitialDirectory = "c:\\";
		openFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog->FilterIndex = 2;
		openFileDialog->RestoreDirectory = true;

		if ( openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
		{
			if ( (myStream = openFileDialog->OpenFile()) != nullptr )
			{
				// Read all lines in the text file and add to list
				StreamReader^ sr = gcnew StreamReader(myStream);
										
				while(!sr->EndOfStream)
					inputText->Add(sr->ReadLine());

				myStream->Close();
			}
		}

		// Instaniate the cipher
		VigenereCipher^ vc = gcnew VigenereCipher();
		// Display results
		lbDisplay->Items->AddRange(vc->deCipherTextFile(inputText)->ToArray());
}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bLoadFile = (gcnew System::Windows::Forms::Button());
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->SuspendLayout();
			// 
			// bLoadFile
			// 
			this->bLoadFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bLoadFile->Location = System::Drawing::Point(861, 657);
			this->bLoadFile->Name = L"bLoadFile";
			this->bLoadFile->Size = System::Drawing::Size(135, 60);
			this->bLoadFile->TabIndex = 0;
			this->bLoadFile->Text = L"Load File";
			this->bLoadFile->UseVisualStyleBackColor = true;
			this->bLoadFile->Click += gcnew System::EventHandler(this, &Form1::loadFile_Click);
			// 
			// lbDisplay
			// 
			this->lbDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->lbDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lbDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->ItemHeight = 20;
			this->lbDisplay->Location = System::Drawing::Point(0, 0);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(1008, 640);
			this->lbDisplay->TabIndex = 1;
			// 
			// statusStrip1
			// 
			this->statusStrip1->AutoSize = false;
			this->statusStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->statusStrip1->Location = System::Drawing::Point(0, 642);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1008, 87);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->lbDisplay);
			this->Controls->Add(this->bLoadFile);
			this->Controls->Add(this->statusStrip1);
			this->Name = L"Form1";
			this->Text = L"Vigenere Cipher";
			this->ResumeLayout(false);

		}
#pragma endregion
	

			 
};
}

