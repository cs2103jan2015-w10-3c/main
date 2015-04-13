//@author A0111448M
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogicTest
{		
	TEST_CLASS(LOGICREADTEST)
	{
	public:
		//FOR INDEXCOMMAND
		TEST_METHOD(LOGICIndexCommandTest)//When input is normal "add Case"
		{
			LogicRead _Reader;
			std::string input="add";
			int expectedOutput=1;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCommandTest1)//When input is normal
		{
			LogicRead _Reader;
			std::string input="search";
			int expectedOutput=2;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}


		TEST_METHOD(LOGICIndexCommandTest2)//When input is normal
		{
			LogicRead _Reader;
			std::string input="edit";
			int expectedOutput=3;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCommandTest3)//When input is normal
		{
			LogicRead _Reader;
			std::string input="delete";
			int expectedOutput=4;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCommandTest4)//When input is in uppercase
		{
			LogicRead _Reader;
			std::string input="ADD";
			int expectedOutput=1;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCommandTest5)//When input is in uppercase
		{
			LogicRead _Reader;
			std::string input="aDd";
			int expectedOutput=1;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCommandTest6)//When input is in uppercase
		{
			LogicRead _Reader;
			std::string input="Add";
			int expectedOutput=1;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}


		TEST_METHOD(LOGICIndexCommandTest7)//When input is invalid
		{
			LogicRead _Reader;
			std::string input="sdgeqrhgerhg";
			int expectedOutput=20;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}	

		TEST_METHOD(LOGICIndexCommandTest8)//When input is an integer
		{
			LogicRead _Reader;
			std::string input="3";
			int expectedOutput=20;
			int actualOutput;
			actualOutput=_Reader.indexCommand(input);
			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICInterpretCommandTest9)//When input is normal
		{
			LogicRead _Reader;
			std::string input = " add Dog haha";
			Command* actualOutput=_Reader.interpretCommand(input);
			int actualCommandIndex= actualOutput->getCommandIndex();
			std::string actualDetails=actualOutput->getCommandDescription();
			int expectedCommandIndex = 1;
			std::string expectedDetails = "Dog haha";

			Assert::AreEqual(actualCommandIndex,expectedCommandIndex);
			Assert::AreEqual(actualDetails,expectedDetails);

		}

		//FOR INTERPRETCOMMAND
		TEST_METHOD(LOGICInterpretCommandTest1)//When input is missing the details
		{
			LogicRead _Reader;
			std::string input = " add";
			Command* actualOutput=_Reader.interpretCommand(input);
			int actualCommandIndex= actualOutput->getCommandIndex();
			std::string actualDetails=actualOutput->getCommandDescription();
			int expectedCommandIndex = 1;
			std::string expectedDetails = "";

			Assert::AreEqual(actualCommandIndex,expectedCommandIndex);
			Assert::AreEqual(actualDetails,expectedDetails);

		}

		TEST_METHOD(LOGICInterpretCommandTest2)//When Command is Invalid
		{
			LogicRead _Reader;
			std::string input = "addsa dog haha";
			Command* actualOutput=_Reader.interpretCommand(input);
			int actualCommandIndex= actualOutput->getCommandIndex();
			std::string actualDetails=actualOutput->getCommandDescription();
			int expectedCommandIndex = 20;
			std::string expectedDetails = "dog haha";

			Assert::AreEqual(actualCommandIndex,expectedCommandIndex);
			Assert::AreEqual(actualDetails,expectedDetails);

		}

		TEST_METHOD(LOGICInterpretCommandTest3)//When input is invalid
		{
			LogicRead _Reader;
			std::string input = "addsdoghaha";
			Command* actualOutput=_Reader.interpretCommand(input);
			int actualCommandIndex= actualOutput->getCommandIndex();
			std::string actualDetails=actualOutput->getCommandDescription();
			int expectedCommandIndex = 20;
			std::string expectedDetails = "";

			Assert::AreEqual(actualCommandIndex,expectedCommandIndex);
			Assert::AreEqual(actualDetails,expectedDetails);

		}
	};




	TEST_CLASS(EDITREADERTEST)
	{
	public:
		//FOR INDEXCATEGORY
		TEST_METHOD(LOGICIndexCategoryTest1)//Description cateogory
		{
			EditReader _Reader;
			std::string input = "desc";
			int actualOutput=_Reader.indexCategory(input);
			int expectedOutput = 1;

			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCategoryTest2)//StarTime Category
		{
			EditReader _Reader;
			std::string input = "stime";
			int actualOutput=_Reader.indexCategory(input);
			int expectedOutput = 2;

			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCategoryTest3)//StartDate Category
		{
			EditReader _Reader;
			std::string input = "sdate";
			int actualOutput=_Reader.indexCategory(input);
			int expectedOutput = 4;

			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCategoryTest4)//EndTime Category with uppercase
		{
			EditReader _Reader;
			std::string input = "ETIME";
			int actualOutput=_Reader.indexCategory(input);
			int expectedOutput = 3;

			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCategoryTest5)//EndDate Cateogry with upper case
		{
			EditReader _Reader;
			std::string input = "EDATE";
			int actualOutput=_Reader.indexCategory(input);
			int expectedOutput = 5;

			Assert::AreEqual(actualOutput,expectedOutput);
		}

		TEST_METHOD(LOGICIndexCategoryTest6)//Invalid category
		{
			EditReader _Reader;
			std::string input = "sdgavr";
			int actualOutput=_Reader.indexCategory(input);
			int expectedOutput = 20;

			Assert::AreEqual(actualOutput,expectedOutput);
		}

		//Testing Interpret Command
		TEST_METHOD(LOGICInterpretCommandTest1) //VAlid Input
		{
			EditReader _Reader;
			std::string input = "2 desc Dog laugh";
			bool isValid=_Reader.interpretCommand(input);
			int expectedIndex=2;
			int expectedCategory=1;
			std::string expectedDetails="Dog laugh";
			int actualIndex=_Reader.getTaskIndex();
			int actualCategory=_Reader.getSelectedCategory();
			std::string actualDetails=_Reader.getNewInput();

			Assert::AreEqual(isValid,true);
			Assert::AreEqual(actualIndex,expectedIndex);
			Assert::AreEqual(actualCategory,expectedCategory);
			Assert::AreEqual(actualDetails,expectedDetails);
		}
		TEST_METHOD(LOGICInterpretCommandTest2) //Missing details to update
		{
			EditReader _Reader;
			std::string input = "2 desc";
			bool isValid=_Reader.interpretCommand(input);
			int expectedIndex=2;
			int expectedCategory=1;
			std::string expectedDetails="";
			int actualIndex=_Reader.getTaskIndex();
			int actualCategory=_Reader.getSelectedCategory();
			std::string actualDetails=_Reader.getNewInput();

			Assert::AreEqual(isValid,false);
			Assert::AreEqual(actualIndex,expectedIndex);
			Assert::AreEqual(actualCategory,expectedCategory);
			Assert::AreEqual(actualDetails,expectedDetails);
		}
		TEST_METHOD(LOGICInterpretCommandTest3)	//Missing both category and details
		{
			EditReader _Reader;
			std::string input = "2";
			bool isValid=_Reader.interpretCommand(input);
			int expectedIndex=2;
			int expectedCategory=20;
			std::string expectedDetails="";
			int actualIndex=_Reader.getTaskIndex();
			int actualCategory=_Reader.getSelectedCategory();
			std::string actualDetails=_Reader.getNewInput();

			Assert::AreEqual(isValid,false);
			Assert::AreEqual(actualIndex,expectedIndex);
			Assert::AreEqual(actualCategory,expectedCategory);
			Assert::AreEqual(actualDetails,expectedDetails);
		}

	};
}