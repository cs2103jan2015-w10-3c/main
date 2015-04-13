//@author A0111405B
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace boost::posix_time;
using namespace boost::gregorian;

namespace CMParserTest
{		
	TEST_CLASS(CMParserTest) {
public:
	TEST_METHOD(PARSERdateFormat1) {
		CMParser parser;
		std::string tester = "shopping 22 mar 2015 12am";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 00:00:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormat2){
		CMParser parser;
		std::string tester = "shopping 22 MAR 15 12:00";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 12:00:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormat3) {
		CMParser parser;
		std::string tester = "shopping 22/03/2015 12:34am";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 00:34:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormat4) {
		CMParser parser;
		std::string tester = "shopping 22/03/15 2pm";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 14:00:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormat5) {
		CMParser parser;
		std::string tester = "shopping 22/mar/15 2pm";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 14:00:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormat6) {
		CMParser parser;
		std::string tester = "shopping 22nd mar 2pm";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 14:00:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormat7) {
		CMParser parser;
		std::string tester = "shopping 22nd/mar 2pm";
		parser.parseData(tester);
		std::string end = "2015-Mar-22 14:00:00";

		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormattodayTomorrow) {
		CMParser parser;
		std::string tester = "Shopping from today to tomorrow";
		parser.parseData(tester);
		ptime start (day_clock::local_day(), time_duration(23, 59, 0));
		ptime end (day_clock::local_day()+date_duration(1), time_duration(23, 59, 0));

		Assert::AreEqual(to_simple_string(start), to_simple_string(parser.getStart()));
		Assert::AreEqual(to_simple_string(end), to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdateFormatWeekdayNames) {
		CMParser parser;
		std::string tester = "Shopping from tuesday to wednesday";
		parser.parseData(tester);
		std::string start = "2015-Apr-14 23:59:00";
		std::string end = "2015-Apr-15 23:59:00";

		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERdescriptionWithInvertedCommas) {
		CMParser parser;
		std::string tester = "meeting at \"thank god its friday\" 22 mar 15 12am 13 may 12pm";
		parser.parseData(tester);
		std::string desc = "meeting at \"thank god its friday\"";
		std::string start = "2015-Mar-22 00:00:00";
		std::string end = "2015-May-13 12:00:00";
		std::string type = "timed";

		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
		Assert::AreEqual(desc, parser.getDescription());
		Assert::AreEqual(type, parser.getType());
	}

	TEST_METHOD(PARSERtimedTask) {
		CMParser parser;
		std::string tester = "SHOPPING 22 mar 15 12am 13 may 12pm";
		parser.parseData(tester);
		std::string desc = "SHOPPING";
		std::string start = "2015-Mar-22 00:00:00";
		std::string end = "2015-May-13 12:00:00";
		std::string type = "timed";

		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
		Assert::AreEqual(desc, parser.getDescription());
		Assert::AreEqual(type, parser.getType());
	}

	TEST_METHOD(PARSERdeadlineTask) {
		CMParser parser;
		std::string tester = "submit report by 9 april 10pm";
		parser.parseData(tester);
		std::string desc = "submit report";
		std::string end = "2015-Apr-09 22:00:00";
		std::string start = "not-a-date-time";
		std::string type = "deadline";

		Assert::AreEqual(type, parser.getType());
		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
		Assert::AreEqual(desc, parser.getDescription());
	}

	TEST_METHOD(PARSERfloatTask) {
		CMParser parser;
		std::string tester = "Shopping by the bay from peter to john";
		parser.parseData(tester);
		std::string desc = "Shopping by the bay from peter to john";
		std::string start = "not-a-date-time";
		std::string end = "not-a-date-time";
		std::string type = "float";

		Assert::AreEqual(type, parser.getType());
		Assert::AreEqual(desc, parser.getDescription());
		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERparseTimedFromFile) {
		CMParser parser;
		std::string tester = "Shopping by the bay                                2015-Apr-01 10:00:00                    2015-Apr-01 11:00:00                    ";
		parser.parseDataFromFile(tester);
		std::string desc = "Shopping by the bay";
		std::string start = "2015-Apr-01 10:00:00";
		std::string end = "2015-Apr-01 11:00:00";
		std::string type = "timed";

		Assert::AreEqual(type, parser.getType());
		Assert::AreEqual(desc, parser.getDescription());
		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERparseDeadlineFromFile) {
		CMParser parser;
		std::string tester = "submit CS2103 report                    2015-Apr-01 23:59:00 --NIL--                   ";
		parser.parseDataFromFile(tester);
		std::string desc = "submit CS2103 report";
		std::string end = "2015-Apr-01 23:59:00";
		std::string start = "not-a-date-time";
		std::string type = "deadline";

		Assert::AreEqual(type, parser.getType());
		Assert::AreEqual(desc, parser.getDescription());
		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	TEST_METHOD(PARSERparseFloatFromFile) {
		CMParser parser;
		std::string tester = "do laundry                              --NIL--                   --NIL--                   ";
		parser.parseDataFromFile(tester);
		std::string desc = "do laundry";
		std::string start = "not-a-date-time";
		std::string end = "not-a-date-time";
		std::string type = "float";

		Assert::AreEqual(type, parser.getType());
		Assert::AreEqual(desc, parser.getDescription());
		Assert::AreEqual(start, to_simple_string(parser.getStart()));
		Assert::AreEqual(end, to_simple_string(parser.getEnd()));
	}

	//equivalence partition 
	TEST_METHOD(PARSERgetDescription) {
		CMParser parser;
		std::string tester = "Shopping 22 mar 13:00 to 23/3/15 400pm";
		parser.parseData(tester);
		std::string expected = "Shopping";

		Assert::AreEqual(expected, parser.getDescription());
	}

	//This is the boundary case for the getPtime with both date and time partition
	TEST_METHOD(PARSERgetPtime) {
		CMParser parser;
		std::string tester = "Shopping from 22 mar 15 2pm 23/3/15 400pm";
		parser.parseData(tester);
		ptime time (date(2015, Mar, 22), time_duration(14, 0, 0));
		std::string type = "timed";

		Assert::AreEqual(type, parser.getType());
		Assert::AreEqual(to_simple_string(time), to_simple_string(parser.getStart()));
	}

	//This is the boundary case for the getPtime with date partition
	TEST_METHOD(PARSERgetPtimeWithoutTime) {
		CMParser parser;
		std::string tester = "Shopping from 22 mar 15 to 23/3/15";
		parser.parseData(tester);
		ptime time (date(2015, Mar, 22), time_duration(23, 59, 0));

		Assert::AreEqual(to_simple_string(time), to_simple_string(parser.getStart()));
	}

	TEST_METHOD(PARSERgetPtimeWithoutDate) {
		CMParser parser;
		std::string tester = "Shopping from 23:59 to 23/3/15 14:00";
		parser.parseData(tester);
		ptime time (day_clock::local_day(), time_duration(23, 59, 0));

		Assert::AreEqual(to_simple_string(time), to_simple_string(parser.getStart()));
	}

	TEST_METHOD(PARSERgetToday) {
		CMParser parser;

		Assert::AreEqual(to_simple_string(day_clock::local_day()), parser.getToday());
	}

	TEST_METHOD(PARSERgetTomorrow) {
		CMParser parser;
		date expected = day_clock::local_day()+date_duration(1);

		Assert::AreEqual(to_simple_string(expected), parser.getTomorrow());
	}

	TEST_METHOD(PARSERinterpretDirectoryString) {
		CMParser parser;
		std::string expected = "C:\\users\\desktop\\";
		std::string directory = "C:\\users\\desktop";

		Assert::AreEqual(expected, parser.interpretDirectoryString(directory));
	}


	TEST_METHOD(PARSERchangeTime) {
		CMParser parser;
		ptime current(date(2015, Mar, 23), time_duration(13, 0, 0)); 
		std::string newTime = "10pm";
		ptime newptime = parser.changeTime(current, newTime);
		std::string expected = "2015-Mar-23 22:00:00";

		Assert::AreEqual(expected, to_simple_string(newptime));
	}

	TEST_METHOD(PARSERchangeDate) {
		CMParser parser;
		ptime current(date(2015, Apr, 4), time_duration(13, 0, 0)); 
		std::string newDate = "5 april";
		ptime newptime = parser.changeDate(current, newDate);
		std::string expected = "2015-Apr-05 13:00:00";

		Assert::AreEqual(expected, to_simple_string(newptime));
	}
	};
}