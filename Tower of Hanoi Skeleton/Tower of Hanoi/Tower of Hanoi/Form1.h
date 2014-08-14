#pragma once


#include "HanoiDisplay.h"

namespace TowerofHanoi {

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;




	private: System::Windows::Forms::Button^  btnPlay;
	private: System::Windows::Forms::TextBox^  txtSize;

	private: System::Windows::Forms::Label^  label1;


			 HanoiDisplay^ globalHanoiDisplay;
			 array<PictureBox^>^ pictureBoxArray;
			 array<PictureBox^>^ poleArray;
				

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->txtSize = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(26, 27);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(104, 23);
			this->btnPlay->TabIndex = 3;
			this->btnPlay->Text = L"Play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &Form1::btnPlay_Click);
			// 
			// txtSize
			// 
			this->txtSize->Location = System::Drawing::Point(26, 87);
			this->txtSize->Name = L"txtSize";
			this->txtSize->Size = System::Drawing::Size(104, 20);
			this->txtSize->TabIndex = 4;
			this->txtSize->Text = L"3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Number of Disks";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Wheat;
			this->ClientSize = System::Drawing::Size(708, 521);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtSize);
			this->Controls->Add(this->btnPlay);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				pictureBoxArray = gcnew array<PictureBox^>(MAXDISKS);
				poleArray = gcnew array<PictureBox^>(3);
				
				 for (int i=0; i<8; i++)
				 {
					 pictureBoxArray[i] = gcnew PictureBox();
					 pictureBoxArray[i]->Location = System::Drawing::Point(100, i*30 + 10);
					 pictureBoxArray[i]->Name = L"pictureBox" + Convert::ToString(i);
					 String^ fileName = "Disk" + Convert::ToString(i+1) + ".bmp";
					 pictureBoxArray[i]->Image = Image::FromFile( fileName );
					 pictureBoxArray[i]->Visible = false;
					 pictureBoxArray[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
					 this->Controls->Add(pictureBoxArray[i]);
				 }

				 	for (int i=0; i<3; i++)
				{

					 poleArray[i] = gcnew PictureBox();
					 poleArray[i]->Location = System::Drawing::Point((i+1)*150, 150);
					 poleArray[i]->Name = L"poleShape" + Convert::ToString(i+1);
				
					 poleArray[i]->Image = Image::FromFile( "poleImage.bmp" );
					 poleArray[i]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
	
					 poleArray[i]->Visible = true;
					 this->Controls->Add(poleArray[i]);
				 }

				 globalHanoiDisplay = gcnew HanoiDisplay(pictureBoxArray,poleArray[0], poleArray[1], poleArray[2]);
			 }



public:

//-----------------------------------------------------------------------------------

	void solveTowers(int nDisks, int sourcePole, int destPole, int auxPole)
	{
		if(nDisks == 1)
		{
			// move disk from source to dest			
			globalHanoiDisplay->moveTopDisk(sourcePole, destPole);
			// update display
			Refresh();
			System::Threading::Thread::Sleep(500);
		}
		else
		{
			// Recursive
			solveTowers(nDisks - 1, sourcePole, auxPole, destPole);
			
			// move disk from source to dest
			globalHanoiDisplay->moveTopDisk(sourcePole, destPole);
			// update display
			Refresh();
			System::Threading::Thread::Sleep(500);

			// Recursive
			solveTowers(nDisks - 1, auxPole, destPole, sourcePole);
		}
	}
	
private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				  int size = Convert::ToInt16(txtSize->Text);
				  globalHanoiDisplay->setUp(size);
				  Refresh();
				  System::Threading::Thread::Sleep(500);
				 
			      solveTowers(size, 1, 3, 2);
			 }

};
}

