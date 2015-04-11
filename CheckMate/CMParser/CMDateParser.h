//@author A0111405B 
#ifndef CMDATEPARSER_H
#define CMDATEPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <boost/date_time.hpp>

//This class parses a given input and returns them as a 
//boost::gregorian::date format. It recognises several formats.
//It also has functions that can determine if a given string is
//a month or a weekday name.
class CMDateParser {
private:
	static const std::string MONTH[24];
	static const std::string LONG_WEEKDAY_NAME[7];
	static const std::string ABBREVIATED_WEEKDAY_NAME[7];
	static const int NOT_FOUND;

	int getIndexFromWeekdayName (std::string);
	boost::gregorian::date getDateFromWeekdayName(std::string);
	boost::gregorian::date getDate(std::string);

public:
	boost::gregorian::date parseDate(std::string);

	bool isWeekdayName (std::string);
	bool isMonth(std::string);
};

#endif