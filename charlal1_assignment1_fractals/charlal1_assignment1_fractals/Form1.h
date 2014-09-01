#pragma once

#include "Koch.h"
#include "Tree.h"
#include "SierPinski.h"
#include "Dragon.h"

namespace charlal1_assignment1_fractals {

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
	private: System::Windows::Forms::NumericUpDown^  nUpDownDepth;
	protected: 
	private: System::Windows::Forms::GroupBox^  gbDepth;
	private: System::Windows::Forms::GroupBox^  gbPattern;
	private: System::Windows::Forms::Button^  bTriangle;

	private: System::Windows::Forms::Panel^  pDisplay;
	private: SierPinski^ s;
	private: Tree^ t;
	private: Koch^ k;
	private: Dragon^ d;

	private: System::Windows::Forms::Button^  bTree;
	private: Graphics^ canvas;
	private: System::Windows::Forms::Button^  bKoch;
	private: System::Windows::Forms::Button^  bCarpet;

	private: System::Windows::Forms::Button^  bDragon;

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
			this->nUpDownDepth = (gcnew System::Windows::Forms::NumericUpDown());
			this->gbDepth = (gcnew System::Windows::Forms::GroupBox());
			this->gbPattern = (gcnew System::Windows::Forms::GroupBox());
			this->bDragon = (gcnew System::Windows::Forms::Button());
			this->bCarpet = (gcnew System::Windows::Forms::Button());
			this->bKoch = (gcnew System::Windows::Forms::Button());
			this->bTree = (gcnew System::Windows::Forms::Button());
			this->bTriangle = (gcnew System::Windows::Forms::Button());
			this->pDisplay = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUpDownDepth))->BeginInit();
			this->gbDepth->SuspendLayout();
			this->gbPattern->SuspendLayout();
			this->SuspendLayout();
			// 
			// nUpDownDepth
			// 
			this->nUpDownDepth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->nUpDownDepth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->nUpDownDepth->Location = System::Drawing::Point(6, 25);
			this->nUpDownDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->nUpDownDepth->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->nUpDownDepth->Name = L"nUpDownDepth";
			this->nUpDownDepth->Size = System::Drawing::Size(120, 26);
			this->nUpDownDepth->TabIndex = 0;
			this->nUpDownDepth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// gbDepth
			// 
			this->gbDepth->Controls->Add(this->nUpDownDepth);
			this->gbDepth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gbDepth->Location = System::Drawing::Point(12, 12);
			this->gbDepth->Name = L"gbDepth";
			this->gbDepth->Size = System::Drawing::Size(132, 62);
			this->gbDepth->TabIndex = 1;
			this->gbDepth->TabStop = false;
			this->gbDepth->Text = L"Depth";
			// 
			// gbPattern
			// 
			this->gbPattern->Controls->Add(this->bDragon);
			this->gbPattern->Controls->Add(this->bCarpet);
			this->gbPattern->Controls->Add(this->bKoch);
			this->gbPattern->Controls->Add(this->bTree);
			this->gbPattern->Controls->Add(this->bTriangle);
			this->gbPattern->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gbPattern->Location = System::Drawing::Point(12, 81);
			this->gbPattern->Name = L"gbPattern";
			this->gbPattern->Size = System::Drawing::Size(132, 284);
			this->gbPattern->TabIndex = 2;
			this->gbPattern->TabStop = false;
			this->gbPattern->Text = L"Fractal Pattern";
			// 
			// bDragon
			// 
			this->bDragon->Location = System::Drawing::Point(6, 234);
			this->bDragon->Name = L"bDragon";
			this->bDragon->Size = System::Drawing::Size(120, 42);
			this->bDragon->TabIndex = 5;
			this->bDragon->Text = L"Dragon";
			this->bDragon->UseVisualStyleBackColor = true;
			this->bDragon->Click += gcnew System::EventHandler(this, &Form1::bDragon_Click);
			// 
			// bCarpet
			// 
			this->bCarpet->Location = System::Drawing::Point(6, 186);
			this->bCarpet->Name = L"bCarpet";
			this->bCarpet->Size = System::Drawing::Size(120, 42);
			this->bCarpet->TabIndex = 3;
			this->bCarpet->Text = L"Carpet";
			this->bCarpet->UseVisualStyleBackColor = true;
			this->bCarpet->Click += gcnew System::EventHandler(this, &Form1::bCarpet_Click);
			// 
			// bKoch
			// 
			this->bKoch->Location = System::Drawing::Point(6, 138);
			this->bKoch->Name = L"bKoch";
			this->bKoch->Size = System::Drawing::Size(120, 42);
			this->bKoch->TabIndex = 2;
			this->bKoch->Text = L"Koch";
			this->bKoch->UseVisualStyleBackColor = true;
			this->bKoch->Click += gcnew System::EventHandler(this, &Form1::bKoch_Click);
			// 
			// bTree
			// 
			this->bTree->Location = System::Drawing::Point(6, 90);
			this->bTree->Name = L"bTree";
			this->bTree->Size = System::Drawing::Size(120, 42);
			this->bTree->TabIndex = 1;
			this->bTree->Text = L"Tree";
			this->bTree->UseVisualStyleBackColor = true;
			this->bTree->Click += gcnew System::EventHandler(this, &Form1::bTree_Click);
			// 
			// bTriangle
			// 
			this->bTriangle->Location = System::Drawing::Point(6, 42);
			this->bTriangle->Name = L"bTriangle";
			this->bTriangle->Size = System::Drawing::Size(120, 42);
			this->bTriangle->TabIndex = 0;
			this->bTriangle->Text = L"Triangle";
			this->bTriangle->UseVisualStyleBackColor = true;
			this->bTriangle->Click += gcnew System::EventHandler(this, &Form1::bSierpinski_Click);
			// 
			// pDisplay
			// 
			this->pDisplay->BackColor = System::Drawing::Color::White;
			this->pDisplay->Location = System::Drawing::Point(189, 12);
			this->pDisplay->Name = L"pDisplay";
			this->pDisplay->Size = System::Drawing::Size(537, 537);
			this->pDisplay->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->pDisplay);
			this->Controls->Add(this->gbPattern);
			this->Controls->Add(this->gbDepth);
			this->Name = L"Form1";
			this->Text = L"Fractals";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUpDownDepth))->EndInit();
			this->gbDepth->ResumeLayout(false);
			this->gbPattern->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void bSierpinski_Click(System::Object^  sender, System::EventArgs^  e) {
			 //
			 s->DrawTriangle((int)nUpDownDepth->Value, pDisplay->Width, pDisplay->Height);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 canvas = pDisplay->CreateGraphics();

			 s = gcnew SierPinski(canvas);
			 t = gcnew Tree(canvas);
			 k = gcnew Koch(canvas);
			 d = gcnew Dragon(canvas);
		 }
private: System::Void bTree_Click(System::Object^  sender, System::EventArgs^  e) {
			 //
			 t->Draw((int)nUpDownDepth->Value, pDisplay->Width, pDisplay->Height);
		 }
private: System::Void bKoch_Click(System::Object^  sender, System::EventArgs^  e) {
			 k->Draw((int)nUpDownDepth->Value, pDisplay->Width, pDisplay->Height);
		 }
private: System::Void bCarpet_Click(System::Object^  sender, System::EventArgs^  e) {
			 s->DrawCarpet((int)nUpDownDepth->Value, pDisplay->Width, pDisplay->Height);
		 }
private: System::Void bDragon_Click(System::Object^  sender, System::EventArgs^  e) {
			 d->Draw((int)nUpDownDepth->Value, pDisplay->Width, pDisplay->Height);
		 }
};
}

