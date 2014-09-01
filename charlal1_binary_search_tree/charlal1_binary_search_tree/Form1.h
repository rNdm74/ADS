#pragma once

#include "BinarySearchTree.h"

namespace charlal1_binary_search_tree {

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
	private: System::Windows::Forms::Panel^  pDisplay;
	protected: 
	private: System::Windows::Forms::TextBox^  tbSearch;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  bBuild;

	private: BinarySearchTree^ bst;
	private: Graphics^ graphics;
	private: System::Windows::Forms::Label^  lPost;
	private: System::Windows::Forms::Label^  lPre;
	private: System::Windows::Forms::ListBox^  lbPost;

	private: System::Windows::Forms::ListBox^  lbPre;


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
			this->pDisplay = (gcnew System::Windows::Forms::Panel());
			this->lPost = (gcnew System::Windows::Forms::Label());
			this->lPre = (gcnew System::Windows::Forms::Label());
			this->tbSearch = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bBuild = (gcnew System::Windows::Forms::Button());
			this->lbPre = (gcnew System::Windows::Forms::ListBox());
			this->lbPost = (gcnew System::Windows::Forms::ListBox());
			this->pDisplay->SuspendLayout();
			this->SuspendLayout();
			// 
			// pDisplay
			// 
			this->pDisplay->Controls->Add(this->lbPost);
			this->pDisplay->Controls->Add(this->lbPre);
			this->pDisplay->Controls->Add(this->lPost);
			this->pDisplay->Controls->Add(this->lPre);
			this->pDisplay->Controls->Add(this->tbSearch);
			this->pDisplay->Controls->Add(this->button1);
			this->pDisplay->Controls->Add(this->bBuild);
			this->pDisplay->Location = System::Drawing::Point(-1, 1);
			this->pDisplay->Name = L"pDisplay";
			this->pDisplay->Size = System::Drawing::Size(784, 560);
			this->pDisplay->TabIndex = 0;
			// 
			// lPost
			// 
			this->lPost->AutoSize = true;
			this->lPost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lPost->Location = System::Drawing::Point(90, 415);
			this->lPost->Name = L"lPost";
			this->lPost->Size = System::Drawing::Size(45, 20);
			this->lPost->TabIndex = 5;
			this->lPost->Text = L"Post:";
			// 
			// lPre
			// 
			this->lPre->AutoSize = true;
			this->lPre->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lPre->Location = System::Drawing::Point(13, 415);
			this->lPre->Name = L"lPre";
			this->lPre->Size = System::Drawing::Size(37, 20);
			this->lPre->TabIndex = 4;
			this->lPre->Text = L"Pre:";
			// 
			// tbSearch
			// 
			this->tbSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tbSearch->Location = System::Drawing::Point(13, 11);
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(204, 26);
			this->tbSearch->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(13, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 26);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// bBuild
			// 
			this->bBuild->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bBuild->Location = System::Drawing::Point(585, 11);
			this->bBuild->Name = L"bBuild";
			this->bBuild->Size = System::Drawing::Size(188, 55);
			this->bBuild->TabIndex = 3;
			this->bBuild->Text = L"Build";
			this->bBuild->UseVisualStyleBackColor = true;
			this->bBuild->Click += gcnew System::EventHandler(this, &Form1::bBuild_Click);
			// 
			// lbPre
			// 
			this->lbPre->FormattingEnabled = true;
			this->lbPre->Location = System::Drawing::Point(17, 438);
			this->lbPre->Name = L"lbPre";
			this->lbPre->Size = System::Drawing::Size(71, 95);
			this->lbPre->TabIndex = 6;
			// 
			// lbPost
			// 
			this->lbPost->FormattingEnabled = true;
			this->lbPost->Location = System::Drawing::Point(94, 438);
			this->lbPost->Name = L"lbPost";
			this->lbPost->Size = System::Drawing::Size(71, 95);
			this->lbPost->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->pDisplay);
			this->Name = L"Form1";
			this->Text = L"Binary Search Tree";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->pDisplay->ResumeLayout(false);
			this->pDisplay->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 graphics = pDisplay->CreateGraphics();
			 }
	private: System::Void bBuild_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				
				 //array<String^>^ bst1 = gcnew array<String^>{"84", "67", "59", "43", "56", "25", "18", "15", "74"};
				 lbPre->Items->Clear();
				 lbPost->Items->Clear();

				 Random^ rGen = gcnew Random();

				 array<String^>^ bst1 = gcnew array<String^>(32);

				 for(int i = 0; i < bst1->Length; i++)
				 {					 
					 bst1[i] = Convert::ToString(rGen->Next(99));
					 lbPre->Items->Add(bst1[i]);
				 }

				 

				 bst = gcnew BinarySearchTree(bst1[16]);

				 for(int i = 0; i < bst1->Length; i++)
				 {
					 bst->addNode(bst1[i]);
				 }

				 bst->InOrder(bst->getRootNode(), lbPost);

				 graphics->Clear(Color::White);

				 bst->Draw(bst->getRootNode(), pDisplay->Width / 2, 50, 75, graphics);
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ target = tbSearch->Text;
			 
			 if(target != "")
			 {
				 MessageBox::Show(Convert::ToString(bst->search(target)), "Search results:");					 
			 }
		 }
};
}

