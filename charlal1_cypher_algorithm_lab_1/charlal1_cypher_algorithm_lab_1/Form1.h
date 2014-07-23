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
			//
			//TODO: Add the constructor code here
			//
			/*VigenereCipher^ vc = gcnew VigenereCipher();
			String^ encipheredWord = vc->enCipher("poo DLE", "BART");
			String^ decipheredWord = vc->deCipher(encipheredWord, "BART");*/
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
			this->bLoadFile = (gcnew System::Windows::Forms::Button());
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// bLoadFile
			// 
			this->bLoadFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bLoadFile->Location = System::Drawing::Point(12, 12);
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
			this->lbDisplay->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->lbDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->ItemHeight = 20;
			this->lbDisplay->Location = System::Drawing::Point(0, 89);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(1008, 640);
			this->lbDisplay->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->lbDisplay);
			this->Controls->Add(this->bLoadFile);
			this->Name = L"Form1";
			this->Text = L"Vigenere Cipher";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loadFile_Click(System::Object^  sender, System::EventArgs^  e) {

				 List<String^>^ inputText = gcnew List<String^>();
				 List<String^>^ keys = gcnew List<String^>();

				 Stream^ myStream;
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				 openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex = 2;
				 openFileDialog1->RestoreDirectory = true;

				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					if ( (myStream = openFileDialog1->OpenFile()) != nullptr )
					{
						// Insert code to read the stream here.
						StreamReader^ sr = gcnew StreamReader(myStream);
												
						while(!sr->EndOfStream)
						{
							inputText->Add(sr->ReadLine());
						}

						myStream->Close();
					}
				 }
				 
				 // Get KEY count
				 int keyCount = Convert::ToInt16(inputText[0]);
				 // Remove from list
				 inputText->RemoveAt(0);

				 // Get all keys from the list
				 while(keyCount > 0)
				 {
					 keys->Add(inputText[--keyCount]);					 
					 inputText->RemoveAt(keyCount);
				 }
				 
				 // Instaniate the cipher
				 VigenereCipher^ vc = gcnew VigenereCipher();

				 // to-do optimize
				 for(int j = 0; j < keys->Count; j++)
				 {
					 for(int i = 0; i < inputText->Count; i++)
					 {					 
						 String^ result = vc->deCipher(inputText[i], keys[j]);
						 if(result->Contains("ENCE") || result->Contains("TECH") ||result->Contains("THE") ||result->Contains("GOOD")||result->Contains("MORE")||result->Contains("SIX"))
							lbDisplay->Items->Add(result + " : " + keys[j]);							 						 
					 }					 					 					 
				 }
			 }
	};
}

