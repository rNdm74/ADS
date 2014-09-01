#pragma once

#include "LinkedListStack.h"
#include "ExpressionTree.h"
#include "BinaryTree.h"
#include "BinaryTreeNode.h"

namespace charlal1_simple_binary_tree {

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

	private: BinaryTree^ globalTree;
	private: Graphics^ treeCanvas;

	private: System::Windows::Forms::ListBox^  lbDisplay;

	private: System::Windows::Forms::Label^  lDisplay;
	private: System::Windows::Forms::Label^  lTree;

	private: System::Windows::Forms::Button^  bPreOrder;
	private: System::Windows::Forms::Button^  bInOrder;
	private: System::Windows::Forms::Button^  bPostOrder;	
	private: System::Windows::Forms::Button^  bSolve;
	private: System::Windows::Forms::Button^  bPostFix;
	

	private: System::Windows::Forms::RadioButton^  rbBinaryTree;
	private: System::Windows::Forms::RadioButton^  rbExpressionTreeOne;
	private: System::Windows::Forms::RadioButton^  rbExpressionTreeTwo;
	private: System::Windows::Forms::Panel^  pGraphicalDisplay;

	private: System::Windows::Forms::Label^  lGraphicalDisplay;

	private: delegate void Display(BinaryTreeNode^, ListBox^);

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
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->lDisplay = (gcnew System::Windows::Forms::Label());
			this->bPreOrder = (gcnew System::Windows::Forms::Button());
			this->bInOrder = (gcnew System::Windows::Forms::Button());
			this->bPostOrder = (gcnew System::Windows::Forms::Button());
			this->bSolve = (gcnew System::Windows::Forms::Button());
			this->lTree = (gcnew System::Windows::Forms::Label());
			this->rbBinaryTree = (gcnew System::Windows::Forms::RadioButton());
			this->rbExpressionTreeOne = (gcnew System::Windows::Forms::RadioButton());
			this->rbExpressionTreeTwo = (gcnew System::Windows::Forms::RadioButton());
			this->bPostFix = (gcnew System::Windows::Forms::Button());
			this->pGraphicalDisplay = (gcnew System::Windows::Forms::Panel());
			this->lGraphicalDisplay = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbDisplay
			// 
			this->lbDisplay->BackColor = System::Drawing::SystemColors::Control;
			this->lbDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lbDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->ItemHeight = 20;
			this->lbDisplay->Location = System::Drawing::Point(27, 207);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(192, 342);
			this->lbDisplay->TabIndex = 0;
			// 
			// lDisplay
			// 
			this->lDisplay->AutoSize = true;
			this->lDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lDisplay->Location = System::Drawing::Point(23, 178);
			this->lDisplay->Name = L"lDisplay";
			this->lDisplay->Size = System::Drawing::Size(63, 20);
			this->lDisplay->TabIndex = 1;
			this->lDisplay->Text = L"Results";
			// 
			// bPreOrder
			// 
			this->bPreOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bPreOrder->Location = System::Drawing::Point(225, 207);
			this->bPreOrder->Name = L"bPreOrder";
			this->bPreOrder->Size = System::Drawing::Size(94, 43);
			this->bPreOrder->TabIndex = 2;
			this->bPreOrder->Tag = L"0";
			this->bPreOrder->Text = L"Pre Order";
			this->bPreOrder->UseVisualStyleBackColor = true;
			this->bPreOrder->Click += gcnew System::EventHandler(this, &Form1::bTree_Click);
			// 
			// bInOrder
			// 
			this->bInOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bInOrder->Location = System::Drawing::Point(225, 256);
			this->bInOrder->Name = L"bInOrder";
			this->bInOrder->Size = System::Drawing::Size(94, 43);
			this->bInOrder->TabIndex = 3;
			this->bInOrder->Tag = L"1";
			this->bInOrder->Text = L"In Order";
			this->bInOrder->UseVisualStyleBackColor = true;
			this->bInOrder->Click += gcnew System::EventHandler(this, &Form1::bTree_Click);
			// 
			// bPostOrder
			// 
			this->bPostOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bPostOrder->Location = System::Drawing::Point(225, 305);
			this->bPostOrder->Name = L"bPostOrder";
			this->bPostOrder->Size = System::Drawing::Size(94, 43);
			this->bPostOrder->TabIndex = 5;
			this->bPostOrder->Tag = L"2";
			this->bPostOrder->Text = L"Post Order";
			this->bPostOrder->UseVisualStyleBackColor = true;
			this->bPostOrder->Click += gcnew System::EventHandler(this, &Form1::bTree_Click);
			// 
			// bSolve
			// 
			this->bSolve->Enabled = false;
			this->bSolve->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bSolve->Location = System::Drawing::Point(225, 354);
			this->bSolve->Name = L"bSolve";
			this->bSolve->Size = System::Drawing::Size(94, 43);
			this->bSolve->TabIndex = 8;
			this->bSolve->Tag = L"3";
			this->bSolve->Text = L"Solve";
			this->bSolve->UseVisualStyleBackColor = true;
			this->bSolve->Click += gcnew System::EventHandler(this, &Form1::bTree_Click);
			// 
			// lTree
			// 
			this->lTree->AutoSize = true;
			this->lTree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lTree->Location = System::Drawing::Point(23, 14);
			this->lTree->Name = L"lTree";
			this->lTree->Size = System::Drawing::Size(45, 20);
			this->lTree->TabIndex = 12;
			this->lTree->Text = L"Tree:";
			// 
			// rbBinaryTree
			// 
			this->rbBinaryTree->AutoSize = true;
			this->rbBinaryTree->Checked = true;
			this->rbBinaryTree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->rbBinaryTree->Location = System::Drawing::Point(27, 37);
			this->rbBinaryTree->Name = L"rbBinaryTree";
			this->rbBinaryTree->Size = System::Drawing::Size(192, 24);
			this->rbBinaryTree->TabIndex = 16;
			this->rbBinaryTree->TabStop = true;
			this->rbBinaryTree->Tag = L"0";
			this->rbBinaryTree->Text = L"Binary: 1,2,3,4,5,6,7,8,9";
			this->rbBinaryTree->UseVisualStyleBackColor = true;
			this->rbBinaryTree->CheckedChanged += gcnew System::EventHandler(this, &Form1::rbTree_CheckedChanged);
			// 
			// rbExpressionTreeOne
			// 
			this->rbExpressionTreeOne->AutoSize = true;
			this->rbExpressionTreeOne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rbExpressionTreeOne->Location = System::Drawing::Point(27, 67);
			this->rbExpressionTreeOne->Name = L"rbExpressionTreeOne";
			this->rbExpressionTreeOne->Size = System::Drawing::Size(165, 24);
			this->rbExpressionTreeOne->TabIndex = 17;
			this->rbExpressionTreeOne->Tag = L"1";
			this->rbExpressionTreeOne->Text = L"Expression: (2*3)+6";
			this->rbExpressionTreeOne->UseVisualStyleBackColor = true;
			this->rbExpressionTreeOne->CheckedChanged += gcnew System::EventHandler(this, &Form1::rbTree_CheckedChanged);
			// 
			// rbExpressionTreeTwo
			// 
			this->rbExpressionTreeTwo->AutoSize = true;
			this->rbExpressionTreeTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->rbExpressionTreeTwo->Location = System::Drawing::Point(27, 97);
			this->rbExpressionTreeTwo->Name = L"rbExpressionTreeTwo";
			this->rbExpressionTreeTwo->Size = System::Drawing::Size(165, 24);
			this->rbExpressionTreeTwo->TabIndex = 18;
			this->rbExpressionTreeTwo->Tag = L"2";
			this->rbExpressionTreeTwo->Text = L"Expression: 2*(3+6)";
			this->rbExpressionTreeTwo->UseVisualStyleBackColor = true;
			this->rbExpressionTreeTwo->CheckedChanged += gcnew System::EventHandler(this, &Form1::rbTree_CheckedChanged);
			// 
			// bPostFix
			// 
			this->bPostFix->Enabled = false;
			this->bPostFix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->bPostFix->Location = System::Drawing::Point(225, 403);
			this->bPostFix->Name = L"bPostFix";
			this->bPostFix->Size = System::Drawing::Size(94, 43);
			this->bPostFix->TabIndex = 19;
			this->bPostFix->Tag = L"4";
			this->bPostFix->Text = L"PostFix";
			this->bPostFix->UseVisualStyleBackColor = true;
			this->bPostFix->Click += gcnew System::EventHandler(this, &Form1::bTree_Click);
			// 
			// pGraphicalDisplay
			// 
			this->pGraphicalDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pGraphicalDisplay->Location = System::Drawing::Point(325, 207);
			this->pGraphicalDisplay->Name = L"pGraphicalDisplay";
			this->pGraphicalDisplay->Size = System::Drawing::Size(432, 342);
			this->pGraphicalDisplay->TabIndex = 20;
			// 
			// lGraphicalDisplay
			// 
			this->lGraphicalDisplay->AutoSize = true;
			this->lGraphicalDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lGraphicalDisplay->Location = System::Drawing::Point(321, 178);
			this->lGraphicalDisplay->Name = L"lGraphicalDisplay";
			this->lGraphicalDisplay->Size = System::Drawing::Size(60, 20);
			this->lGraphicalDisplay->TabIndex = 21;
			this->lGraphicalDisplay->Text = L"Display";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->lGraphicalDisplay);
			this->Controls->Add(this->pGraphicalDisplay);
			this->Controls->Add(this->bPostFix);
			this->Controls->Add(this->rbExpressionTreeTwo);
			this->Controls->Add(this->rbExpressionTreeOne);
			this->Controls->Add(this->rbBinaryTree);
			this->Controls->Add(this->lTree);
			this->Controls->Add(this->bSolve);
			this->Controls->Add(this->bPostOrder);
			this->Controls->Add(this->bInOrder);
			this->Controls->Add(this->bPreOrder);
			this->Controls->Add(this->lDisplay);
			this->Controls->Add(this->lbDisplay);
			this->Name = L"Form1";
			this->Text = L"Trees";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void rbTree_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 RadioButton^ rb = safe_cast<RadioButton^>(sender);

			 bool selected = false;

			 switch(Convert::ToInt16(rb->Tag))
			 {
				 case 0: globalTree = createSimpleBinaryTree();	 selected = false;	break;
				 case 1: globalTree = createExpressionTreeOne(); selected = true;	break;
				 case 2: globalTree = createExpressionTreeTwo(); selected = true;	break;
			 }

			 bSolve->Enabled = selected;
			 bPostFix->Enabled = selected;

			 // Clear canvas
			 treeCanvas->Clear(Color::White);

			 globalTree->Draw(globalTree->getRootNode(), pGraphicalDisplay->Width / 2, 50, 75, treeCanvas);
		 }		

private: System::Void bTree_Click(System::Object^  sender, System::EventArgs^  e) {
			 Button^ b = safe_cast<Button^>(sender);

			 // Clear the display
			 lbDisplay->Items->Clear();
			 lbDisplay->Items->Add(b->Text + ":");
			 
			 Display^ display = nullptr;

			 // Change tree
			 switch(Convert::ToInt16(b->Tag))
			 {
				 case 0: display = gcnew Display(globalTree, &BinaryTree::PreOrder);	break;
				 case 1: display = gcnew Display(globalTree, &BinaryTree::InOrder);		break;
				 case 2: display = gcnew Display(globalTree, &BinaryTree::PostOrder);	break;
				 case 3: display = gcnew Display(globalTree, &BinaryTree::Parse);		break;
				 case 4: display = gcnew Display(globalTree, &BinaryTree::PostFix);		break;
			 }
			 
			 display(globalTree->getRootNode(), lbDisplay);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 // Init
			 globalTree = createSimpleBinaryTree();

			 // Clear canvas
			 treeCanvas = pGraphicalDisplay->CreateGraphics();
			 treeCanvas->Clear(Color::White);
			 
			 
			 globalTree->Draw(globalTree->getRootNode(), pGraphicalDisplay->Width / 2, 50, 75, treeCanvas);
		 }
private: BinaryTree^ createSimpleBinaryTree() {

			 /**
			  * Binary tree to create
			  *
			  *				1
			  *			   / \
			  *			  2   3
			  *			 / \
			  *			4	5
			  *		   /   / \
			  *		  6	  7   8
			  *		 /
			  *		9
			  *
			  * Start from the bottom up
			  */

			 // Create new binary tree with value 6 and left child node with value 9
			 BinaryTree^ t6 = gcnew BinaryTree("6");
			 t6->makeLeftChildNode("9");

			 // Create new binary tree with value 4 and attach binary tree 6 to left child node 
			 BinaryTree^ t4 = gcnew BinaryTree("4");
			 t4->addLeftSubTree(t6);

			 // Create new binary tree with value 5 with left and right child nodes with values 7 & 8
			 BinaryTree^ t5 = gcnew BinaryTree("5");
			 t5->makeLeftChildNode("7");
			 t5->makeRightChildNode("8");

			 // Create new tree node value 2 and attach left and right sub trees 4 & 5 
			 BinaryTree^ t2 = gcnew BinaryTree("2", t4, t5);

			 // Create new tree node with value 3 
			 BinaryTree^ t3 = gcnew BinaryTree("3");

			 // Create new global tree node with left and right sub trees 2 & 3
			 return gcnew BinaryTree("1", t2, t3);
		 }
private: ExpressionTree^ createExpressionTreeOne() {

			 /**
			  * Expression tree to create
			  *
			  *				+
			  *			   / \
			  *			  *   3
			  *			 / \
			  *			2	6
			  *
			  */

			 ExpressionTree^ two = gcnew ExpressionTree("2");
			 ExpressionTree^ six = gcnew ExpressionTree("6");
			 ExpressionTree^ three = gcnew ExpressionTree("3");

			 ExpressionTree^ times = gcnew ExpressionTree("*", two, six);

			 return gcnew ExpressionTree("+", times, three);
		 }
private: ExpressionTree^ createExpressionTreeTwo() {

			 /**
			  * Expression tree to create
			  *
			  *				*
			  *			   / \
			  *			  2   +
			  *			     / \
			  *			 	6   3
			  *
			  */

			 ExpressionTree^ two = gcnew ExpressionTree("2");
			 ExpressionTree^ six = gcnew ExpressionTree("6");
			 ExpressionTree^ three = gcnew ExpressionTree("3");

			 ExpressionTree^ plus = gcnew ExpressionTree("+", six, three);
			 return gcnew ExpressionTree("*", two, plus);
		 }
};
}

