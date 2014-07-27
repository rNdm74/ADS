
#include "StdAfx.h"
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace charlal1_priority_queue_lab_2;
namespace charlal1_priority_queue_lab_2_tests {
    using namespace System;
    ref class PatientTest;
    
    
    /// <summary>
///This is a test class for PatientTest and is intended
///to contain all PatientTest Unit Tests
///</summary>
	[TestClass]
	public ref class PatientTest
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
			///A test for Priority
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void PriorityTest()
			{
				Patient_Accessor^  target = gcnew Patient_Accessor(1, "Bob"); 
				int expected = 1; 
				int actual;
				target->Priority = expected;
				actual = target->Priority;
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for Name
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void NameTest()
			{
				Patient_Accessor^  target = gcnew Patient_Accessor(1, "Bob"); 
				String^  expected = "Bob"; 
				String^  actual;
				target->Name = expected;
				actual = target->Name;
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for ToString
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void ToStringTest()
			{
				Patient_Accessor^  target = gcnew Patient_Accessor(1, "Bob"); 
				String^  expected = "Patient: Bob";
				String^  actual;
				actual = target->ToString();
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for CompareTo
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void CompareToTest()
			{
				Patient_Accessor^  target1 = gcnew Patient_Accessor(1, "Bob"); 
				Patient_Accessor^  target2 = gcnew Patient_Accessor(2, "Bill"); 
				Object^  obj = target2; 
				int expected = -1; 
				int actual;
				actual = target1->CompareTo(obj);
				Assert::AreEqual(expected, actual);
			}
			/// <summary>
			///A test for Patient Constructor
			///</summary>
	public: [TestMethod]
			[DeploymentItem(L"charlal1_priority_queue_lab_2.exe")]
			void PatientConstructorTest()
			{
				int priority = 10; 
				String^  name = "Bob"; 
				Patient_Accessor^  target = gcnew Patient_Accessor(priority, name);
				Assert::IsNotNull(target);
			}
	};
}
namespace charlal1_priority_queue_lab_2_tests {
    
}
