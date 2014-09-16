#pragma once

#include "Huffman.h"

namespace charlal1_assignment2_huffman_coding {

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

	private: Huffman^ h;
	private: Graphics^ g;


	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  tsslHuffmanCode;

	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripStatusLabel^  tsslFixedLengthCode;


	private: System::Windows::Forms::TextBox^  tb8;
	private: System::Windows::Forms::TextBox^  tb7;
	private: System::Windows::Forms::TextBox^  tb6;
	private: System::Windows::Forms::TextBox^  tb5;
	private: System::Windows::Forms::TextBox^  tb4;
	private: System::Windows::Forms::TextBox^  tb3;
	private: System::Windows::Forms::TextBox^  tb2;
	private: System::Windows::Forms::TextBox^  tb1;
	
	private: System::Windows::Forms::TextBox^  f8;
	private: System::Windows::Forms::TextBox^  f7;
	private: System::Windows::Forms::TextBox^  f6;
	private: System::Windows::Forms::TextBox^  f5;
	private: System::Windows::Forms::TextBox^  f4;
	private: System::Windows::Forms::TextBox^  f3;
	private: System::Windows::Forms::TextBox^  f2;
	private: System::Windows::Forms::TextBox^  f1;

	private: System::Windows::Forms::TextBox^  tbLegalEncodedString;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  pTreeDisplay;
	private: System::Windows::Forms::DataGridView^  dgvHuffmanCodeDisplay;




	private: System::Windows::Forms::DataGridViewTextBoxColumn^  symbol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  frequency;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  gbHuffmanCodeDisplay;
	private: System::Windows::Forms::GroupBox^  gbTreeDisplay;


	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  gbTextDisplay;
	private: System::Windows::Forms::RichTextBox^  rtbDisplay;



	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel5;
		
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tsslHuffmanCode = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel5 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tsslFixedLengthCode = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->f8 = (gcnew System::Windows::Forms::TextBox());
			this->f7 = (gcnew System::Windows::Forms::TextBox());
			this->f6 = (gcnew System::Windows::Forms::TextBox());
			this->f5 = (gcnew System::Windows::Forms::TextBox());
			this->f4 = (gcnew System::Windows::Forms::TextBox());
			this->f3 = (gcnew System::Windows::Forms::TextBox());
			this->f2 = (gcnew System::Windows::Forms::TextBox());
			this->f1 = (gcnew System::Windows::Forms::TextBox());
			this->tb8 = (gcnew System::Windows::Forms::TextBox());
			this->tb7 = (gcnew System::Windows::Forms::TextBox());
			this->tb6 = (gcnew System::Windows::Forms::TextBox());
			this->tb5 = (gcnew System::Windows::Forms::TextBox());
			this->tb4 = (gcnew System::Windows::Forms::TextBox());
			this->tb3 = (gcnew System::Windows::Forms::TextBox());
			this->tb2 = (gcnew System::Windows::Forms::TextBox());
			this->tb1 = (gcnew System::Windows::Forms::TextBox());
			this->pTreeDisplay = (gcnew System::Windows::Forms::Panel());
			this->dgvHuffmanCodeDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->symbol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->frequency = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->gbHuffmanCodeDisplay = (gcnew System::Windows::Forms::GroupBox());
			this->gbTreeDisplay = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->tbLegalEncodedString = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->gbTextDisplay = (gcnew System::Windows::Forms::GroupBox());
			this->rtbDisplay = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvHuffmanCodeDisplay))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->gbHuffmanCodeDisplay->SuspendLayout();
			this->gbTreeDisplay->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->gbTextDisplay->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->AutoSize = false;
			this->statusStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->statusStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripStatusLabel3, 
				this->toolStripStatusLabel1, this->tsslHuffmanCode, this->toolStripStatusLabel5, this->tsslFixedLengthCode});
			this->statusStrip1->Location = System::Drawing::Point(0, 689);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1008, 40);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripStatusLabel3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripStatusLabel3->Margin = System::Windows::Forms::Padding(10, 3, 0, 2);
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(167, 35);
			this->toolStripStatusLabel3->Text = L"Set Fixed Code Length:";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripStatusLabel1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripStatusLabel1->Margin = System::Windows::Forms::Padding(400, 3, 0, 2);
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(114, 35);
			this->toolStripStatusLabel1->Text = L"Huffman Code:";
			// 
			// tsslHuffmanCode
			// 
			this->tsslHuffmanCode->BackColor = System::Drawing::SystemColors::Control;
			this->tsslHuffmanCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tsslHuffmanCode->Name = L"tsslHuffmanCode";
			this->tsslHuffmanCode->Size = System::Drawing::Size(19, 35);
			this->tsslHuffmanCode->Text = L"0";
			// 
			// toolStripStatusLabel5
			// 
			this->toolStripStatusLabel5->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripStatusLabel5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->toolStripStatusLabel5->Margin = System::Windows::Forms::Padding(10, 3, 0, 2);
			this->toolStripStatusLabel5->Name = L"toolStripStatusLabel5";
			this->toolStripStatusLabel5->Size = System::Drawing::Size(141, 35);
			this->toolStripStatusLabel5->Text = L"Fixed Length Code:";
			// 
			// tsslFixedLengthCode
			// 
			this->tsslFixedLengthCode->BackColor = System::Drawing::SystemColors::Control;
			this->tsslFixedLengthCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tsslFixedLengthCode->Name = L"tsslFixedLengthCode";
			this->tsslFixedLengthCode->Size = System::Drawing::Size(19, 35);
			this->tsslFixedLengthCode->Text = L"0";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::SystemColors::Control;
			this->numericUpDown1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(181, 701);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {8, 0, 0, 0});
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(49, 22);
			this->numericUpDown1->TabIndex = 28;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(153, 321);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 48);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(201, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 20);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Frequency";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(95, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 20);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Symbol";
			// 
			// f8
			// 
			this->f8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f8->Location = System::Drawing::Point(205, 289);
			this->f8->Name = L"f8";
			this->f8->Size = System::Drawing::Size(100, 26);
			this->f8->TabIndex = 24;
			// 
			// f7
			// 
			this->f7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f7->Location = System::Drawing::Point(205, 257);
			this->f7->Name = L"f7";
			this->f7->Size = System::Drawing::Size(100, 26);
			this->f7->TabIndex = 23;
			// 
			// f6
			// 
			this->f6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f6->Location = System::Drawing::Point(205, 225);
			this->f6->Name = L"f6";
			this->f6->Size = System::Drawing::Size(100, 26);
			this->f6->TabIndex = 22;
			// 
			// f5
			// 
			this->f5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f5->Location = System::Drawing::Point(205, 193);
			this->f5->Name = L"f5";
			this->f5->Size = System::Drawing::Size(100, 26);
			this->f5->TabIndex = 21;
			// 
			// f4
			// 
			this->f4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f4->Location = System::Drawing::Point(205, 161);
			this->f4->Name = L"f4";
			this->f4->Size = System::Drawing::Size(100, 26);
			this->f4->TabIndex = 20;
			this->f4->Text = L"41";
			// 
			// f3
			// 
			this->f3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f3->Location = System::Drawing::Point(205, 129);
			this->f3->Name = L"f3";
			this->f3->Size = System::Drawing::Size(100, 26);
			this->f3->TabIndex = 19;
			this->f3->Text = L"8";
			// 
			// f2
			// 
			this->f2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f2->Location = System::Drawing::Point(205, 97);
			this->f2->Name = L"f2";
			this->f2->Size = System::Drawing::Size(100, 26);
			this->f2->TabIndex = 18;
			this->f2->Text = L"10";
			// 
			// f1
			// 
			this->f1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->f1->Location = System::Drawing::Point(205, 65);
			this->f1->Name = L"f1";
			this->f1->Size = System::Drawing::Size(100, 26);
			this->f1->TabIndex = 17;
			this->f1->Text = L"25";
			// 
			// tb8
			// 
			this->tb8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb8->Location = System::Drawing::Point(99, 289);
			this->tb8->Name = L"tb8";
			this->tb8->Size = System::Drawing::Size(100, 26);
			this->tb8->TabIndex = 16;
			// 
			// tb7
			// 
			this->tb7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb7->Location = System::Drawing::Point(99, 257);
			this->tb7->Name = L"tb7";
			this->tb7->Size = System::Drawing::Size(100, 26);
			this->tb7->TabIndex = 15;
			// 
			// tb6
			// 
			this->tb6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb6->Location = System::Drawing::Point(99, 225);
			this->tb6->Name = L"tb6";
			this->tb6->Size = System::Drawing::Size(100, 26);
			this->tb6->TabIndex = 14;
			// 
			// tb5
			// 
			this->tb5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb5->Location = System::Drawing::Point(99, 193);
			this->tb5->Name = L"tb5";
			this->tb5->Size = System::Drawing::Size(100, 26);
			this->tb5->TabIndex = 13;
			// 
			// tb4
			// 
			this->tb4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb4->Location = System::Drawing::Point(99, 161);
			this->tb4->Name = L"tb4";
			this->tb4->Size = System::Drawing::Size(100, 26);
			this->tb4->TabIndex = 12;
			this->tb4->Text = L"d";
			// 
			// tb3
			// 
			this->tb3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb3->Location = System::Drawing::Point(99, 129);
			this->tb3->Name = L"tb3";
			this->tb3->Size = System::Drawing::Size(100, 26);
			this->tb3->TabIndex = 11;
			this->tb3->Text = L"c";
			// 
			// tb2
			// 
			this->tb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb2->Location = System::Drawing::Point(99, 97);
			this->tb2->Name = L"tb2";
			this->tb2->Size = System::Drawing::Size(100, 26);
			this->tb2->TabIndex = 10;
			this->tb2->Text = L"b";
			// 
			// tb1
			// 
			this->tb1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->tb1->Location = System::Drawing::Point(99, 65);
			this->tb1->Name = L"tb1";
			this->tb1->Size = System::Drawing::Size(100, 26);
			this->tb1->TabIndex = 9;
			this->tb1->Text = L"a";
			// 
			// pTreeDisplay
			// 
			this->pTreeDisplay->AutoScroll = true;
			this->pTreeDisplay->AutoSize = true;
			this->pTreeDisplay->BackColor = System::Drawing::Color::White;
			this->pTreeDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pTreeDisplay->Location = System::Drawing::Point(3, 22);
			this->pTreeDisplay->Name = L"pTreeDisplay";
			this->pTreeDisplay->Size = System::Drawing::Size(583, 485);
			this->pTreeDisplay->TabIndex = 9;
			// 
			// dgvHuffmanCodeDisplay
			// 
			this->dgvHuffmanCodeDisplay->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvHuffmanCodeDisplay->BackgroundColor = System::Drawing::Color::White;
			this->dgvHuffmanCodeDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvHuffmanCodeDisplay->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			this->dgvHuffmanCodeDisplay->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvHuffmanCodeDisplay->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvHuffmanCodeDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvHuffmanCodeDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->symbol, 
				this->code, this->frequency});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvHuffmanCodeDisplay->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvHuffmanCodeDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvHuffmanCodeDisplay->EnableHeadersVisualStyles = false;
			this->dgvHuffmanCodeDisplay->Location = System::Drawing::Point(3, 22);
			this->dgvHuffmanCodeDisplay->Name = L"dgvHuffmanCodeDisplay";
			this->dgvHuffmanCodeDisplay->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dgvHuffmanCodeDisplay->RowHeadersVisible = false;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->dgvHuffmanCodeDisplay->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvHuffmanCodeDisplay->Size = System::Drawing::Size(287, 136);
			this->dgvHuffmanCodeDisplay->TabIndex = 28;
			// 
			// symbol
			// 
			this->symbol->HeaderText = L"Symbol";
			this->symbol->Name = L"symbol";
			// 
			// code
			// 
			this->code->HeaderText = L"Code";
			this->code->Name = L"code";
			// 
			// frequency
			// 
			this->frequency->HeaderText = L"Frequency";
			this->frequency->Name = L"frequency";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->tb1);
			this->groupBox1->Controls->Add(this->tb2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->tb3);
			this->groupBox1->Controls->Add(this->tb4);
			this->groupBox1->Controls->Add(this->tb5);
			this->groupBox1->Controls->Add(this->f8);
			this->groupBox1->Controls->Add(this->tb6);
			this->groupBox1->Controls->Add(this->f7);
			this->groupBox1->Controls->Add(this->tb7);
			this->groupBox1->Controls->Add(this->f6);
			this->groupBox1->Controls->Add(this->tb8);
			this->groupBox1->Controls->Add(this->f5);
			this->groupBox1->Controls->Add(this->f1);
			this->groupBox1->Controls->Add(this->f4);
			this->groupBox1->Controls->Add(this->f2);
			this->groupBox1->Controls->Add(this->f3);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(-1, 190);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(422, 395);
			this->groupBox1->TabIndex = 29;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Manual Entry";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(-1, 575);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(422, 117);
			this->groupBox2->TabIndex = 30;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"From File";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(153, 39);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 48);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Load";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// gbHuffmanCodeDisplay
			// 
			this->gbHuffmanCodeDisplay->Controls->Add(this->dgvHuffmanCodeDisplay);
			this->gbHuffmanCodeDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->gbHuffmanCodeDisplay->Location = System::Drawing::Point(715, 34);
			this->gbHuffmanCodeDisplay->Name = L"gbHuffmanCodeDisplay";
			this->gbHuffmanCodeDisplay->Size = System::Drawing::Size(293, 161);
			this->gbHuffmanCodeDisplay->TabIndex = 31;
			this->gbHuffmanCodeDisplay->TabStop = false;
			this->gbHuffmanCodeDisplay->Text = L"Huffman Code Display";
			// 
			// gbTreeDisplay
			// 
			this->gbTreeDisplay->Controls->Add(this->pTreeDisplay);
			this->gbTreeDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gbTreeDisplay->Location = System::Drawing::Point(419, 190);
			this->gbTreeDisplay->Name = L"gbTreeDisplay";
			this->gbTreeDisplay->Size = System::Drawing::Size(589, 510);
			this->gbTreeDisplay->TabIndex = 32;
			this->gbTreeDisplay->TabStop = false;
			this->gbTreeDisplay->Text = L"Tree Display";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->tbLegalEncodedString);
			this->groupBox5->Controls->Add(this->button2);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(-1, 34);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(421, 167);
			this->groupBox5->TabIndex = 33;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Legal Encoded String";
			// 
			// tbLegalEncodedString
			// 
			this->tbLegalEncodedString->Location = System::Drawing::Point(99, 49);
			this->tbLegalEncodedString->Name = L"tbLegalEncodedString";
			this->tbLegalEncodedString->Size = System::Drawing::Size(206, 26);
			this->tbLegalEncodedString->TabIndex = 29;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(153, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 48);
			this->button2->TabIndex = 28;
			this->button2->Text = L"Decode";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// gbTextDisplay
			// 
			this->gbTextDisplay->Controls->Add(this->rtbDisplay);
			this->gbTextDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gbTextDisplay->Location = System::Drawing::Point(419, 34);
			this->gbTextDisplay->Name = L"gbTextDisplay";
			this->gbTextDisplay->Size = System::Drawing::Size(297, 167);
			this->gbTextDisplay->TabIndex = 34;
			this->gbTextDisplay->TabStop = false;
			this->gbTextDisplay->Text = L"Text Display";
			// 
			// rtbDisplay
			// 
			this->rtbDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->rtbDisplay->Location = System::Drawing::Point(3, 22);
			this->rtbDisplay->Name = L"rtbDisplay";
			this->rtbDisplay->Size = System::Drawing::Size(291, 142);
			this->rtbDisplay->TabIndex = 0;
			this->rtbDisplay->Text = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1008, 729);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->gbTreeDisplay);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->gbTextDisplay);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->gbHuffmanCodeDisplay);
			this->MaximumSize = System::Drawing::Size(1024, 768);
			this->MinimumSize = System::Drawing::Size(1024, 768);
			this->Name = L"Form1";
			this->Text = L"Huffman Coding";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dgvHuffmanCodeDisplay))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->gbHuffmanCodeDisplay->ResumeLayout(false);
			this->gbTreeDisplay->ResumeLayout(false);
			this->gbTreeDisplay->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->gbTextDisplay->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {				
				g = pTreeDisplay->CreateGraphics();
			 }

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 array<TextBox^>^ symbols = gcnew array<TextBox^>{
					 tb1,tb2,tb3,tb4,tb5,tb6,tb7,tb8
				 };

				 array<TextBox^>^ freq = gcnew array<TextBox^>{
					 f1,f2,f3,f4,f5,f6,f7,f8
				 };

				 h = gcnew Huffman();

				 rtbDisplay->Text = h->Encode(symbols, freq);
				 tsslHuffmanCode->Text = h->HuffCodeLength();
				 tsslFixedLengthCode->Text = h->FixedCodeLength(Convert::ToInt16(numericUpDown1->Value));
				 
				 h->DrawCodes(dgvHuffmanCodeDisplay);
				 h->DrawTree(pTreeDisplay->Width, pTreeDisplay->Height, g);
				 
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			rtbDisplay->Text = h->Decode(tbLegalEncodedString->Text);
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			  if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			  {
				 System::IO::StreamReader ^ sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
				 
				 h = gcnew Huffman();

				 rtbDisplay->Text = h->Encode(sr->ReadToEnd());
				 tsslHuffmanCode->Text = h->HuffCodeLength();
				 tsslFixedLengthCode->Text = h->FixedCodeLength(Convert::ToInt16(numericUpDown1->Value));
				 
				 h->DrawCodes(dgvHuffmanCodeDisplay);
				 h->DrawTree(pTreeDisplay->Width, pTreeDisplay->Height, g);

				 sr->Close();
			  }
		 }
};
}

