#pragma once

#include "Patient.h"
#include "PriorityQueue.h"

namespace charlal1_priority_queue_lab_2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	public delegate void Push(Patient^ p);
	public delegate Patient^ Peek();
	public delegate Patient^ Pop();

	template < class T, class U > 
	Boolean isinst(U u) {
	   return dynamic_cast< T >(u) != nullptr;
	}

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
		PriorityQueue^ pq;
		Random^ rGen;
		array<String^>^ patientName;
		array<Patient^>^ patients;
		Int64 ticksThisTime;

		int iterations;
			
	public: 
		Stopwatch ^ timePerParse;

		Form1(void)
		{
			InitializeComponent();

			iterations = safe_cast<int>(nUpDown->Value) + 1;
			pq = gcnew PriorityQueue(iterations);			
			patientName = gcnew array<String^>{
				"Joe",
				"Jane",
				"Jim",
				"Bob",
				"Kermit",
				"Piggie",
				"Adam",
				"John",
				"Jean",
				"Berty"
			};

			rGen = gcnew Random();	

			patients = gcnew array<Patient^>(iterations);

			for(int i = 0; i < patients->Length; i++)
				patients[i] = gcnew Patient(rGen->Next(1,11), patientName[rGen->Next(10)]);

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
	private: System::Windows::Forms::NumericUpDown^  nUpDown;
	private: System::Windows::Forms::ListBox^  lbDisplay;
	private: System::Windows::Forms::Button^  bPush;
	private: System::Windows::Forms::Button^  bPop;
	private: System::Windows::Forms::Button^  bPeek;	
	private: System::Windows::Forms::Label^  lIterations;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		System::Void fBenchmark(Object^ obj) {

			Int64 nanosecPerTick = (1000L * 1000L * 1000L) / Stopwatch::Frequency;
			const long numIterations = iterations;

			// Define variables for operation statistics.
			Int64 numTicks = 0;
			Int64 numRollovers = 0;
			Int64 maxTicks = 0;
			Int64 minTicks = Int64::MaxValue;
			int indexFastest = -1;
			int indexSlowest = -1;
			Int64 milliSec = 0;
			Stopwatch ^ time10kOperations = Stopwatch::StartNew();

			ticksThisTime = 0;

			for(int p = 0; p < iterations; p++)
			{
				if ( isinst<Push^>(obj) )
				{
					Push^ push = dynamic_cast<Push^>(obj);
					timePerParse = Stopwatch::StartNew();
					push(patients[p]);
					timePerParse->Stop();
					ticksThisTime = timePerParse->ElapsedTicks;
				}
				else if ( isinst<Pop^>(obj) )
				{
					Pop^ pop = dynamic_cast<Pop^>(obj);
					timePerParse = Stopwatch::StartNew();
					pop();
					timePerParse->Stop();
					ticksThisTime = timePerParse->ElapsedTicks;
				}
				else if ( isinst<Peek^>(obj) )
				{
					Peek^ peek = dynamic_cast<Peek^>(obj);
					timePerParse = Stopwatch::StartNew();
					peek();
					timePerParse->Stop();
					ticksThisTime = timePerParse->ElapsedTicks;
				}
				

				// Skip over the time for the first operation, 
				// just in case it caused a one-time 
				// performance hit. 
				if ( p == 0 )
				{
					time10kOperations->Reset();
					time10kOperations->Start();
				}
				else
				{
					// Update operation statistics 
					// for iterations 1-10001. 
					if ( maxTicks < ticksThisTime )
					{
					   indexSlowest = p;
					   maxTicks = ticksThisTime;
					}
					if ( minTicks > ticksThisTime )
					{
					   indexFastest = p;
					   minTicks = ticksThisTime;
					}
					numTicks += ticksThisTime;
					if ( numTicks < ticksThisTime )
					{
					   // Keep track of rollovers.
					   numRollovers++;
					}
				}
			}
			
			// Display the statistics for 10000 iterations.
			time10kOperations->Stop();
			milliSec = time10kOperations->ElapsedMilliseconds;
			lbDisplay->Items->Add("");
			lbDisplay->Items->Add( obj->GetType()->Name + " Summary:" );
			lbDisplay->Items->Add(String::Format( "  Slowest time:  #{0}/{1} = {2} ticks", indexSlowest, numIterations, maxTicks ));
			lbDisplay->Items->Add(String::Format( "  Fastest time:  #{0}/{1} = {2} ticks", indexFastest, numIterations, minTicks ));
			lbDisplay->Items->Add(String::Format( "  Average time:  {0} ticks = {1} nanoseconds", numTicks / numIterations, (numTicks * nanosecPerTick) / numIterations ));
			lbDisplay->Items->Add(String::Format( "  Total time looping through {0} operations: {1} milliseconds", numIterations, milliSec ));
		}

		System::Void bPush_Click(System::Object^  sender, System::EventArgs^  e) {
			try
			{
				fBenchmark(gcnew Push(pq, &PriorityQueue::Push));	
			}
			catch(Exception^ e)
			{
				MessageBox::Show(e->Message->ToString());
			}								
		}
		System::Void bPop_Click(System::Object^  sender, System::EventArgs^  e) {
			try
			{
				fBenchmark(gcnew Pop(pq, &PriorityQueue::Pop));
			}
			catch(Exception^ e)
			{
				MessageBox::Show(e->Message->ToString());
			}			
		}
		System::Void bPeek_Click(System::Object^  sender, System::EventArgs^  e) {
			try
			{
				fBenchmark(gcnew Peek(pq, &PriorityQueue::Peek));
			}
			catch(Exception^ e)
			{
				MessageBox::Show(e->Message->ToString());
			}			
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->bPush = (gcnew System::Windows::Forms::Button());
			this->bPop = (gcnew System::Windows::Forms::Button());
			this->bPeek = (gcnew System::Windows::Forms::Button());
			this->nUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->lIterations = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// lbDisplay
			// 
			this->lbDisplay->Dock = System::Windows::Forms::DockStyle::Top;
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->ItemHeight = 20;
			this->lbDisplay->Location = System::Drawing::Point(0, 0);
			this->lbDisplay->Margin = System::Windows::Forms::Padding(0);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(624, 304);
			this->lbDisplay->TabIndex = 0;
			// 
			// bPush
			// 
			this->bPush->Location = System::Drawing::Point(103, 366);
			this->bPush->Name = L"bPush";
			this->bPush->Size = System::Drawing::Size(130, 44);
			this->bPush->TabIndex = 1;
			this->bPush->Text = L"Push";
			this->bPush->UseVisualStyleBackColor = true;
			this->bPush->Click += gcnew System::EventHandler(this, &Form1::bPush_Click);
			// 
			// bPop
			// 
			this->bPop->Location = System::Drawing::Point(375, 366);
			this->bPop->Name = L"bPop";
			this->bPop->Size = System::Drawing::Size(130, 44);
			this->bPop->TabIndex = 2;
			this->bPop->Text = L"Pop";
			this->bPop->UseVisualStyleBackColor = true;
			this->bPop->Click += gcnew System::EventHandler(this, &Form1::bPop_Click);
			// 
			// bPeek
			// 
			this->bPeek->Location = System::Drawing::Point(239, 366);
			this->bPeek->Name = L"bPeek";
			this->bPeek->Size = System::Drawing::Size(130, 44);
			this->bPeek->TabIndex = 3;
			this->bPeek->Text = L"Peek";
			this->bPeek->UseVisualStyleBackColor = true;
			this->bPeek->Click += gcnew System::EventHandler(this, &Form1::bPeek_Click);
			// 
			// nUpDown
			// 
			this->nUpDown->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->nUpDown->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nUpDown->Location = System::Drawing::Point(209, 324);
			this->nUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
			this->nUpDown->Name = L"nUpDown";
			this->nUpDown->Size = System::Drawing::Size(266, 22);
			this->nUpDown->TabIndex = 4;
			this->nUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->nUpDown->ThousandsSeparator = true;
			this->nUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			// 
			// lIterations
			// 
			this->lIterations->AutoSize = true;
			this->lIterations->Location = System::Drawing::Point(127, 324);
			this->lIterations->Name = L"lIterations";
			this->lIterations->Size = System::Drawing::Size(76, 20);
			this->lIterations->TabIndex = 5;
			this->lIterations->Text = L"Iterations";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->lIterations);
			this->Controls->Add(this->nUpDown);
			this->Controls->Add(this->bPeek);
			this->Controls->Add(this->bPop);
			this->Controls->Add(this->bPush);
			this->Controls->Add(this->lbDisplay);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Priority Queue";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 
};
}

