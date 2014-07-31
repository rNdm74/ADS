#include "stdafx.h"

#include "TStack.h"
#include "TQueue.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace charlal1_stack_queue_tests
{
	[TestClass]
	public ref class charlal1_stack_queue_tests
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestPushInt()
		{
			TStack<int>^ target = gcnew TStack<int>(); 
	
			int data = 5;

			target->Push(data);

			int  expected = 5; 
			int  actual;
			actual = target->Peek();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestPushChar()
		{
			TStack<char>^ target = gcnew TStack<char>(); 
	
			char data = 'a';

			target->Push(data);

			char  expected = 'a'; 
			char  actual;
			actual = target->Peek();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestPopInt()
		{
			TStack<int>^ target = gcnew TStack<int>(); 
	
			int data = 5;

			target->Push(data);
			target->Pop();

			bool  expected = true; 
			bool  actual;
			actual = target->IsEmpty();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestPopChar()
		{
			TStack<char>^ target = gcnew TStack<char>(); 
	
			char data = 'a';

			target->Push(data);
			target->Pop();

			bool  expected = true; 
			bool  actual;
			actual = target->IsEmpty();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestPeekInt()
		{
			TStack<int>^ target = gcnew TStack<int>(); 
	
			int data = 5;

			target->Push(data);
			target->Peek();

			bool  expected = false; 
			bool  actual;
			actual = target->IsEmpty();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestPeekChar()
		{
			TStack<char>^ target = gcnew TStack<char>(); 
	
			char data = 'a';

			target->Push(data);
			target->Peek();

			bool  expected = false; 
			bool  actual;
			actual = target->IsEmpty();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestCountInt()
		{
			TStack<int>^ target = gcnew TStack<int>(); 
	
			int one = 1;
			int two = 2;
			int three = 3;

			target->Push(one);
			target->Push(two);
			target->Push(three);

			int  expected = 3; 
			int  actual;
			actual = target->Count();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestCountChar()
		{
			TStack<char>^ target = gcnew TStack<char>(); 
	
			char a = 'a';
			char b = 'b';
			char c = 'c';

			target->Push(a);
			target->Push(b);
			target->Push(c);

			int  expected = 3; 
			int  actual;
			actual = target->Count();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestIsEmptyInt()
		{
			TStack<int>^ target = gcnew TStack<int>(); 
	
			bool  expected = true; 
			bool  actual;
			actual = target->IsEmpty();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod]
		void TestIsEmptyChar()
		{
			TStack<char>^ target = gcnew TStack<char>(); 
	
			bool  expected = true; 
			bool  actual;
			actual = target->IsEmpty();

			Assert::AreEqual(expected, actual);
		};

		[TestMethod, ExpectedException( InvalidOperationException::typeid )]
		void TestPopEmptyStack()
		{
			TStack<int>^ target = gcnew TStack<int>(); 	
			target->Pop();
		};

		[TestMethod, ExpectedException( InvalidOperationException::typeid )]
		void TestPopEmptyQueue()
		{
			TStack<char>^ target = gcnew TStack<char>(); 	
			target->Pop();
		};

		[TestMethod, ExpectedException( InvalidOperationException::typeid )]
		void TestPeekEmptyStack()
		{
			TStack<int>^ target = gcnew TStack<int>(); 	
			target->Peek();
		};

		[TestMethod, ExpectedException( InvalidOperationException::typeid )]
		void TestPeekEmptyQueue()
		{
			TStack<char>^ target = gcnew TStack<char>(); 	
			target->Peek();
		};
	};
}
