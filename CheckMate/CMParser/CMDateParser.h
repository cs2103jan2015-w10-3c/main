// @author A0111405B 
#ifndef CMDATEPARSER_H
#define CMDATEPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <boost/date_time.hpp>

// This class parses a given input and returns them as a 
// boost::gregorian::date format. It recognises several formats.
// It also has functions that can determine if a given string is
// a month or a weekday name.
class CMDateParser {
private:
	static const std::string MONTH[24];
	static const std::string LONG_WEEKDAY_NAME[7];
	static const std::string ABBREVIATED_WEEKDAY_NAME[7];
	static const int NOT_FOUND;

	// This function returns the index of the weekday name (0 = sunday, 7 = saturday), 
	// and -1 otherwise
	int getIndexFromWeekdayName (std::string);
	// This function returns a date corresponding to the weekday name. If the given string
	// is tuesday, it will return the date of the coming tuesday. If the given string is 
	// next tuesday, it will return the date of the next tuesday. This function will only
	// work if the string input is a weekday name.
	boost::gregorian::date getDateFromWeekdayName(std::string);
	// This function will firstly check if the given input is today or tomorrow and return 
	// the respective dates. If not, it will return the date if it is a valid date and return
	// the default constructor ("not-a-date-time") otherwise.
	boost::gregorian::date getDate(std::string);

public:
	// This function will parse a given string and return the respective date if it is a valid date
	// and return the default constructor ("not-a-date-time") otherwise
	boost::gregorian::date parseDate(std::string);

	// This function checks if a given string is a valid weekday name by going through an array
	// It is able to determine long weekday names and abbreviated weekday names. 
	bool isWeekdayName (std::string);
	// This function checks if a given string is a valid month by going through an array
	// It is able to determine long month names and abbreviated month names. 
	bool isMonth(std::string);
};

#endif