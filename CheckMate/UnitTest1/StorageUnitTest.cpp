//@author A0115990B
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace boost::posix_time;
using namespace boost::gregorian;

namespace UnitTesting
{
	TEST_CLASS(StorageUnitTest)
	{
	public:

		TEST_METHOD(STORAGEAddActiveFloatTask)
		{
			FloatingTask* task = new FloatingTask("Go to library");
			CMActive active;
			active.addActiveFloatingTask(task);
			std::string actual = active.getActiveTasks()[0]->getInfo();

			std::ostringstream expected;

			expected << std::left << std::setw(60)<<"Go to library"
				<<std::setw(30)<<"      --NIL--"
				<<std::setw(30)<<"      --NIL--";

			Assert::AreEqual(expected.str(),actual);
		}

		TEST_METHOD(STORAGEAddActiveDeadlineTask)
		{
			Deadline* task = new Deadline("Do assignment",ptime(date(2015,4,19),time_duration(1,2,3)));
			CMActive active;
			active.addActiveDeadline(task);
			ptime expected(date(2015,4,19), time_duration(1,2,3));
			ptime actual = active.getActiveTasks()[0]->getEnd();

			Assert::AreEqual(to_simple_string(expected), to_simple_string(actual));
		}

		TEST_METHOD(STORAGEAddActiveTimedTask)
		{
			TimedTask* task = new TimedTask("CS exam",ptime(date(2015,4,19),time_duration(1,2,3)),ptime(date(2015,4,20),time_duration(1,2,3)));
			CMActive active;
			active.addActiveTimedTask(task);
			ptime expected(date(2015,4,19), time_duration(1,2,3));
			ptime actual = active.getActiveTasks()[0]->getStart();

			Assert::AreEqual(to_simple_string(expected), to_simple_string(actual));
		}

		
		TEST_METHOD(STORAGEEditActiveTimedTask)
		{
		TimedTask* task = new TimedTask("CS exam",ptime(date(2015,4,19),time_duration(1,2,3)),ptime(date(2015,4,20),time_duration(1,2,3)));

		CMStorage storage;
		storage.addTimedTask(task);
		storage.getActiveDisplay();
		storage.getTask(1); //take out the edit task for logic to edit
	
		std::string actual = storage.getTask(1)->getInfo();
		std::string expected = task -> getInfo();

		Assert::AreEqual(expected,actual);
		}
		

		TEST_METHOD(STORAGEDeleteTask)
		{
			TimedTask* task1 = new TimedTask("CS exam",ptime(date(2015,4,19),time_duration(1,2,3)),ptime(date(2015,4,20),time_duration(1,2,3)));
			TimedTask* task2 = new TimedTask("MKT exam",ptime(date(2015,5,19),time_duration(1,2,3)),ptime(date(2015,5,20),time_duration(1,2,3)));
			TimedTask* task3 = new TimedTask("MATHS exam",ptime(date(2015,6,19),time_duration(1,2,3)),ptime(date(2015,6,20),time_duration(1,2,3)));

			CMStorage storage;
			storage.addTimedTask(task1);
			storage.addTimedTask(task1);
			storage.addTimedTask(task1);
			std::string expected = storage.getActiveDisplay()[1]->getInfo();
			std::string actual= storage.deleteTask(2);

			Assert::AreEqual(expected, actual);
		}
	};
}