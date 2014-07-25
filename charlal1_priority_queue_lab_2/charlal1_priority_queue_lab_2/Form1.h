#pragma once

#include "Patient.h"
#include "PriorityQueue.h"


namespace charlal1_priority_queue_lab_2 {

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

			Patient^ p1 = gcnew Patient(10, "Joe");
			Patient^ p2 = gcnew Patient(3, "Jane");
			Patient^ p3 = gcnew Patient(6, "Jim");
			Patient^ p4 = gcnew Patient(1, "Bob");
			Patient^ p5 = gcnew Patient(9, "Kermit");

			PriorityQueue^ pq = gcnew PriorityQueue(10);
			pq->Push(p1);
			pq->Push(p2);
			pq->Push(p3);
			pq->Push(p4);
			pq->Push(p5);

			Patient^ next = pq->Pop();

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

