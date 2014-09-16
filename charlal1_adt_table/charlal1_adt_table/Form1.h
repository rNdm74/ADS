#pragma once

#include "Animal.h"
#include "Table.h"

namespace charlal1_adt_table {

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
	private: System::Windows::Forms::Button^  bLoadFromFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::ListBox^  lbDisplay;


	private: System::Windows::Forms::NumericUpDown^  nUpDownKey;
	private: System::Windows::Forms::Button^  bSearch;
	private: System::Windows::Forms::Button^  bDelete;
	private: System::Windows::Forms::DataGridView^  dataGridView;


	private: Table<Animal^>^ table;












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
			this->bLoadFromFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->nUpDownKey = (gcnew System::Windows::Forms::NumericUpDown());
			this->bSearch = (gcnew System::Windows::Forms::Button());
			this->bDelete = (gcnew System::Windows::Forms::Button());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUpDownKey))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// bLoadFromFile
			// 
			this->bLoadFromFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bLoadFromFile->Location = System::Drawing::Point(513, 12);
			this->bLoadFromFile->Name = L"bLoadFromFile";
			this->bLoadFromFile->Size = System::Drawing::Size(259, 44);
			this->bLoadFromFile->TabIndex = 0;
			this->bLoadFromFile->Text = L"Load from file";
			this->bLoadFromFile->UseVisualStyleBackColor = true;
			this->bLoadFromFile->Click += gcnew System::EventHandler(this, &Form1::bLoadFromFile_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			// 
			// lbDisplay
			// 
			this->lbDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->ItemHeight = 20;
			this->lbDisplay->Location = System::Drawing::Point(513, 145);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(259, 404);
			this->lbDisplay->TabIndex = 1;
			// 
			// nUpDownKey
			// 
			this->nUpDownKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nUpDownKey->Location = System::Drawing::Point(513, 63);
			this->nUpDownKey->Name = L"nUpDownKey";
			this->nUpDownKey->Size = System::Drawing::Size(259, 26);
			this->nUpDownKey->TabIndex = 3;
			// 
			// bSearch
			// 
			this->bSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bSearch->Location = System::Drawing::Point(513, 95);
			this->bSearch->Name = L"bSearch";
			this->bSearch->Size = System::Drawing::Size(124, 44);
			this->bSearch->TabIndex = 4;
			this->bSearch->Text = L"Search";
			this->bSearch->UseVisualStyleBackColor = true;
			this->bSearch->Click += gcnew System::EventHandler(this, &Form1::bSearch_Click);
			// 
			// bDelete
			// 
			this->bDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bDelete->Location = System::Drawing::Point(643, 95);
			this->bDelete->Name = L"bDelete";
			this->bDelete->Size = System::Drawing::Size(129, 44);
			this->bDelete->TabIndex = 5;
			this->bDelete->Text = L"Delete";
			this->bDelete->UseVisualStyleBackColor = true;
			this->bDelete->Click += gcnew System::EventHandler(this, &Form1::bDelete_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Location = System::Drawing::Point(13, 13);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(494, 536);
			this->dataGridView->TabIndex = 6;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->bDelete);
			this->Controls->Add(this->bSearch);
			this->Controls->Add(this->nUpDownKey);
			this->Controls->Add(this->lbDisplay);
			this->Controls->Add(this->bLoadFromFile);
			this->Name = L"Form1";
			this->Text = L"ADT Table";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUpDownKey))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Initiate DataGridView Columns
				 dataGridView->Columns->Add("ID","ID");
				 dataGridView->Columns->Add("Name","Name");
				 dataGridView->Columns->Add("Species","Species");
				 dataGridView->Columns->Add("CageNumber","Cage No#");
				 dataGridView->Columns->Add("Age","Age");
				 dataGridView->Columns->Add("Food","Food");

				 // Create the table
				 table = gcnew Table<Animal^>(15, dataGridView);
			 }
	private: System::Void bLoadFromFile_Click(System::Object^  sender, System::EventArgs^  e) {

				 table->LoadFromFile(openFileDialog);

				 table->DisplayLog(lbDisplay);

				 table->DisplayTable();
				 
			 }
	private: System::Void bSearch_Click(System::Object^  sender, System::EventArgs^  e) {
				 try
				 {
					 int key = (int)nUpDownKey->Value;

					 Animal^ a = table->FindItem(key);
					 lbDisplay->Items->Add(a->ToString());
				 }
				 catch(Exception^ e)
				 {
					 MessageBox::Show(e->Message);
				 }				 
			 }
	private: System::Void bDelete_Click(System::Object^  sender, System::EventArgs^  e) {
				try
				{
					int key = (int)nUpDownKey->Value;

					table->DeleteItem(key);
					table->DisplayTable();
				}
				catch(Exception^ e)
				{
					MessageBox::Show(e->Message);
				}
			 }
};
}

