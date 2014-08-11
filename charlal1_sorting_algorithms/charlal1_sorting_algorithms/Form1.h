#pragma once

#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"


namespace charlal1_sorting_algorithms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public delegate int SortArray(array<int>^ list);
	public ref class Form1 : public System::Windows::Forms::Form
	{
	
	enum class Sort { Bubble, Selection, Insertion, Merge };

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  bRun;
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
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bRun
			// 
			this->bRun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bRun->Location = System::Drawing::Point(66, 97);
			this->bRun->Name = L"bRun";
			this->bRun->Size = System::Drawing::Size(140, 68);
			this->bRun->TabIndex = 0;
			this->bRun->Text = L"Run";
			this->bRun->UseVisualStyleBackColor = true;
			this->bRun->Click += gcnew System::EventHandler(this, &Form1::bRun_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->bRun);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bRun_Click(System::Object^  sender, System::EventArgs^  e) {
				  Stream^ myStream;
				  SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog;
				  saveFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				  saveFileDialog->FilterIndex = 2;
				  saveFileDialog->RestoreDirectory = true;
				  if ( saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				  {
					 if ( (myStream = saveFileDialog->OpenFile()) != nullptr )
					 {
						try 
						{
							//Pass the file path and file name to the StreamWriter Constructor.
							StreamWriter^ sw = gcnew StreamWriter(myStream);

							//Write a line of text.
							sw->WriteLine(AlgorithmStatistics(Sort::Bubble));
							//Write a line of text.
							sw->WriteLine(AlgorithmStatistics(Sort::Insertion));
							//Write a line of text.
							sw->WriteLine(AlgorithmStatistics(Sort::Selection));
							//Write a line of text.
							sw->WriteLine(AlgorithmStatistics(Sort::Merge));

							//Close the file.
							sw->Close();
						}
						catch(Exception^ e)
						{
							MessageBox::Show("Exception: {0}", e->Message);
						}
						__finally 
						{
							// Code to write the stream goes here.
							myStream->Close();
						}
					 }
				  }
			 }
	private: String^ Form1::AlgorithmStatistics(Sort e) {	
			SelectionSort^ s = gcnew SelectionSort();
			InsertionSort^ i = gcnew InsertionSort();
			BubbleSort^ b = gcnew BubbleSort();
			MergeSort^ m = gcnew MergeSort();

			SortArray^ ds;
			
			switch(e)
			{
				case Sort::Bubble:		ds = gcnew SortArray(b, &BubbleSort::Sort);		break;
				case Sort::Insertion:	ds = gcnew SortArray(i, &InsertionSort::Sort);	break;
				case Sort::Selection:	ds = gcnew SortArray(s, &SelectionSort::Sort);	break;
				case Sort::Merge:		ds = gcnew SortArray(m, &MergeSort::Sort);		break;
			}

			//int n = 32;

			String^ operations = "";

			for(int n = 32; n <= 2048; n*=2)
			{
				operations += ds(GetArray(n)) + ",";
			}
			
			return operations->TrimEnd(',');
		}

	private: array<int>^ Form1::GetArray(int size) {
			Random^ rGen = gcnew Random();
			
			array<int>^ test = gcnew array<int>(size);
			
			for(int i = 0; i < test->Length; i++)
				test[i] = rGen->Next(999);
			
			return test;
		}
};
}

