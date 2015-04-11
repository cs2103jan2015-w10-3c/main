// @author A0111405B
#ifndef CMPARSER_H
#define CMPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <assert.h>
#include "boost/date_time.hpp"
#include "CMDateParser.h"
#include "CMTimeParser.h"

// This class is able to parse a given line of user input words or line of words from 
// the txt file into description, type, start(ptime) and end(ptime). They can be then 
// retrieved by calling the getter functions. There are also functions that enable 
// changing the date or time of a ptime. There are also functions that can return 
// "today" and "tomorrow" as a date in string format
class CMParser {
private:
	static const std::string TIMED;
	static const std::string DEADLINE;
	static const std::string FLOAT;
	static const std::string TIME_ATTRIBUTE[3];
	static const std::string VALID_DATE[8];
	static const std::string connectingWords[6];
	
	CMDateParser dateParser;
	CMTimeParser timeParser;

	std::string _description;
	std::string _type;
	boost::posix_time::ptime _start;
	boost::posix_time::ptime _end;

	// This function determines if the type of task by whether _start and _end are valid
	// date and time.
	void determineType();
	
	// This function parses a given string into ptime format. If the given string is not
	// a valid date and time string, the default constructor of ptime is returned. If the 
	// given string only contains a date, the time is set at 23:59. If the given string only
	// contains a time, the date is set as today, however, if the time has passed, the date 
	// will be changed to tomorrow. For example, if the current time is 4pm and the string
	// is 2pm, the date will be tomorrow instead of today.
	boost::posix_time::ptime getDateAndTime(std::string);
	
	// Determines if a given string has any of the time attributes "am", "pm" or ":".
	bool hasTime(std::string);
	// Determines if a given string has any of the date attributes "tmrw", "today", "tdy",
	// "tomorrow", "tmr", " ", "/", "."
	bool hasDate(std::string);
	// Determines if a given string is a connecting word that is not part of the description
	// For example, in the sentence "Meeting from today 2pm to 4pm", from is a connecting word.
	// The common connecting words are "from", "to", "on", "by", "due", "at".
	bool isConnectingWord(std::string str);
	// Determines if a given string is today or tomorrow. Even able to recognise common short
	// forms like "tmrw", "tdy", "tmr".
	bool isTdyOrTmr (std::string str);
	
	// Combines a given vector of strings into a string
	std::string vectorToString (std::vector<std::string>);

public:
	// Getter functions for private attributes
	std::string getDescription();
	boost::posix_time::ptime getStart();
	boost::posix_time::ptime getEnd();
	std::string getType();

	// This function parses a given string into description, start time, end time and at the same
	// time also sets the type of task. All these attributes can be retrieved through the getter 
	// functions.
	void parseData(std::string);
	// This function parses a given string into description, start time, end time and at the same
	// time also sets the type of task. The description is delimited by either a valid date or 
	// "--NIL--". 
	void parseDataFromFile(std::string);

	// Changes the time and date of a given ptime and returns the new ptime
	boost::posix_time::ptime changeTime (boost::posix_time::ptime, std::string);
	boost::posix_time::ptime changeDate (boost::posix_time::ptime, std::string);

	// Returns the date of today and tmr in a string
	std::string getToday();
	std::string getTomorrow();
		
	// Edits the given string is a valid directory by ensuring that the end of the string is a backslash
	std::string interpretDirectoryString (std::string);
};

#endif