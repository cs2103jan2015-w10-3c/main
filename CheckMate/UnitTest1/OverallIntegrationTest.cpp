//@author A0118918W
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(OVERALLAddDeadlineTaskTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add finish assn by 23/10/2015 7pm");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "finish assn                                                       --NIL--                 2015-Oct-23 19:00:00          ";	
			Assert::AreEqual(actualFeedback, expectedFeedback);	
		}

		TEST_METHOD(OVERALLAddFloatingTaskTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Meet Elaine for lunch");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Meet Elaine for lunch                                             --NIL--                       --NIL--                 ";	
			Assert::AreEqual(actualFeedback, expectedFeedback);

		}

		TEST_METHOD(OVERALLAddTimedTaskTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment 23/10/2015 7pm to 8pm");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";	
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}

		TEST_METHOD(OVERALLEditDescriptionTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23/10/2015 7pm to 8pm");
			sample1->executeCommand("edit 1 desc Do Econs assignment");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Do Econs assignment                                         2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}


		TEST_METHOD(OVERALLDeleteTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("delete 2");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}

		TEST_METHOD(OVERALLEditStartDateTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 8pm to 9pm");
			sample1->executeCommand("edit 1 sdate 28 oct");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Do Math assignment                                          2015-Oct-28 20:00:00          2015-Oct-23 21:00:00          ";
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}

		TEST_METHOD(OVERALLSearchTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("search assignment");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback1 = TaskList[0]->getInfo();
			std::string expectedFeedback1 = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			std::string actualFeedback2 = TaskList[1]->getInfo();
			std::string expectedFeedback2 = "Do Econs assignment                                         2015-Oct-25 15:00:00          2015-Oct-25 16:00:00          ";			
			Assert::AreEqual(actualFeedback1, expectedFeedback1);
			Assert::AreEqual(actualFeedback2, expectedFeedback2);
		}

		TEST_METHOD(OVERALLCheckTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("check 1");
			sample1->executeCommand("completed");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}


		TEST_METHOD(OVERALLUncheckTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("check 1");
			sample1->executeCommand("completed");
			sample1->executeCommand("uncheck 1");
			sample1->executeCommand("home");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback1 = TaskList[0]->getInfo();
			std::string expectedFeedback1 = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			std::string actualFeedback2 = TaskList[1]->getInfo();
			std::string expectedFeedback2 = "Do Econs assignment                                         2015-Oct-25 15:00:00          2015-Oct-25 16:00:00          ";			
			Assert::AreEqual(actualFeedback1, expectedFeedback1);
			Assert::AreEqual(actualFeedback2, expectedFeedback2);
		}


		TEST_METHOD(OVERALLClearTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("clear");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			int expectedFeedback = 0;
			int actualFeedback = TaskList.size();
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}

		TEST_METHOD(OVERALLUndoTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("delete 1");
			sample1->executeCommand("undo");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback1 = TaskList[0]->getInfo();
			std::string expectedFeedback1 = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			std::string actualFeedback2 = TaskList[1]->getInfo();
			std::string expectedFeedback2 = "Do Econs assignment                                         2015-Oct-25 15:00:00          2015-Oct-25 16:00:00          ";			
			Assert::AreEqual(actualFeedback1, expectedFeedback1);
			Assert::AreEqual(actualFeedback2, expectedFeedback2);
		}

		TEST_METHOD(OVERALLRedoTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("delete 1");
			sample1->executeCommand("undo");
			sample1->executeCommand("redo");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback = TaskList[0]->getInfo();
			std::string expectedFeedback = "Do Econs assignment                                         2015-Oct-25 15:00:00          2015-Oct-25 16:00:00          ";
			Assert::AreEqual(actualFeedback, expectedFeedback);
		}

		TEST_METHOD(OVERALLHomeTest)	{
			CMLogic* sample1;
			sample1 = new CMLogic();
			sample1->executeCommand("add Do Math assignment from 23 oct 7pm to 8pm");
			sample1->executeCommand("add Do Econs assignment from 25 oct 3pm to 4pm");
			sample1->executeCommand("search Math");
			sample1->executeCommand("home");
			Output* obj1 = sample1->getDisplay();
			std::vector<Task*> TaskList = obj1->getDisplay();
			std::string actualFeedback1 = TaskList[0]->getInfo();
			std::string expectedFeedback1 = "Do Math assignment                                          2015-Oct-23 19:00:00          2015-Oct-23 20:00:00          ";
			std::string actualFeedback2 = TaskList[1]->getInfo();
			std::string expectedFeedback2 = "Do Econs assignment                                         2015-Oct-25 15:00:00          2015-Oct-25 16:00:00          ";			
			Assert::AreEqual(actualFeedback1, expectedFeedback1);
			Assert::AreEqual(actualFeedback2, expectedFeedback2);
		}
	};
}