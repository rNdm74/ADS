
#include "StdAfx.h"
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace charlal1_priority_queue_lab_2;
namespace charlal1_priority_queue_lab_2_tests {
    using namespace System;
    ref class PriorityQueueTest;
    
    
    /// <summary>
///This is a test class for PriorityQueueTest and is intended
///to contain all PriorityQueueTest Unit Tests
///</summary>
	[TestClass]
	public ref class PriorityQueueTest
	{

	private: Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  testContextInstance;
			 /// <summary>
			 ///Gets or sets the test context which provides
			 ///information about and functionality for the current test run.
			 ///</summary>
	public: property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  TestContext
			{
				Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  get()
				{
					return testContextInstance;
				}
				System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  value)
				{
					testContextInstance = value;
				}
			}

#pragma region Additional test attributes
			// 
			//You can use the following additional attributes as you write your tests:
			//
			//Use ClassInitialize to run code before running the first test in the class
			//public: [ClassInitialize]
			//static System::Void MyClassInitialize(TestContext^  testContext)
			//{
			//}
			//
			//Use ClassCleanup to run code after all tests in a class have run
			//public: [ClassCleanup]
			//static System::Void MyClassCleanup()
			//{
			//}
			//
			//Use TestInitialize to run code before running each test
			//public: [TestInitialize]
			//System::Void MyTestInitialize()
			//{
			//}
			//
			//Use TestCleanup to run code after each test has run
			//public: [TestCleanup]
			//System::Void MyTestCleanup()
			//{
			//}
			//
#pragma endregion
			/// <summary>
			///A test for Push
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void PushTest()
			{
				PriorityQueue_Accessor^  target = gcnew PriorityQueue_Accessor(10); 
				Patient_Accessor^  patient = gcnew Patient_Accessor(10, "Bob");
				target->Push(patient);
				Patient_Accessor^  expected = patient; 
				Patient_Accessor^  actual;
				actual = target->Peek();
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for Pop
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void PopTest()
			{
				PriorityQueue_Accessor^  target = gcnew PriorityQueue_Accessor(10);
				Patient_Accessor^  patient = gcnew Patient_Accessor(10, "Bob");
				target->Push(patient);
				Patient_Accessor^  currentPatient;
				currentPatient = target->Pop();
				int expected = 0;
				int actual = target->Count();
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for Peek
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void PeekTest()
			{
				PriorityQueue_Accessor^  target = gcnew PriorityQueue_Accessor(10); 
				Patient_Accessor^  patient = gcnew Patient_Accessor(10, "Bob");
				target->Push(patient);
				Patient_Accessor^  expectedPatient = patient;
				Patient_Accessor^  actualPatient;
				actualPatient = target->Peek();
				int expectedCount = 1;
				int actualCount = target->Count();
				Assert::AreEqual(expectedPatient, actualPatient);
				Assert::AreEqual(expectedCount, actualCount);
			}
			/// <summary>
			///A test for IsEmpty
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void IsEmptyTest()
			{
				PriorityQueue_Accessor^  target = gcnew PriorityQueue_Accessor(10);
				bool expected = true;
				bool actual;
				actual = target->IsEmpty();
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for Count
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void CountTest()
			{
				PriorityQueue_Accessor^  target = gcnew PriorityQueue_Accessor(10);
				Patient_Accessor^  patient = gcnew Patient_Accessor(10, "Bob");
				target->Push(patient);
				target->Push(patient);
				target->Push(patient);
				target->Push(patient);				
				int expectedCount = 4;
				int actualCount = target->Count();
				Assert::AreEqual(expectedCount, actualCount);
			}
			/// <summary>
			///A test for PriorityQueue Constructor
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void PriorityQueueConstructorTest()
			{
				PriorityQueue_Accessor^  target = gcnew PriorityQueue_Accessor(10);
				Assert::IsNotNull(target);
			}
	};
}
namespace charlal1_priority_queue_lab_2_tests {
    
}
