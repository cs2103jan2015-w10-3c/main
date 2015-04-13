// @author A0111405B
#ifndef CMTIMEPARSER_H
#define CMTIMEPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <boost/date_time.hpp>

// This class parses a given input and separates them into 
// the private attributes _hours and _minutes, which can be 
// then retrieved by the getter functions. It also has functions
// that allow you to set the time manually.
class CMTimeParser {
private:
	static const std::string TIME_ATTRIBUTE[3];

	int _hours;
	int _minutes;

public:
	// This function will parse a string with valid time into _hours and _minutes. 
	// After which they can be retrieved using the getter functions. Several valid
	// time formats are as follow:
	//		11am, 11pm, 1130am, 1130pm, 11:30am, 11:30pm, 11:30
	void parseTime(std::string);

	// Determines if a given string has any of the time attributes "am", "pm" or ":".
	bool hasTime(std::string);

	// These 2 functions enable to client to set the values of _hours and _minutes
	// manually.
	void setHour(int);
	void setMin(int);

	// Getter functions for _hours and _minutes
	int getHour();
	int getMin();
};

#endif