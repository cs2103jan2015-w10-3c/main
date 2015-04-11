//@author A0111405B
#ifndef CMPARSER_H
#define CMPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <assert.h>
#include "boost/date_time.hpp"
#include "CMDateParser.h"
#include "CMTimeParser.h"

//This class is able to parse a given line of user input words 
//or line of words from the txt file into description, type, 
//start(ptime) and end(ptime). They can be then retrieved by 
//calling the getter functions. There are also functions that
//enable changing the date or time of a ptime. There are also 
//functions that can return "today" and "tomorrow" as a date 
//in string format
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

	void determineType();
	
	boost::posix_time::ptime getDateAndTime(std::string);
	
	bool hasTime(std::string);
	bool hasDate(std::string);
	bool isConnectingWord(std::string str);
	bool isTdyOrTmr (std::string str);
	
	std::string vectorToString (std::vector<std::string>);

public:
	//getter functions for private attributes
	std::string getDescription();
	boost::posix_time::ptime getStart();
	boost::posix_time::ptime getEnd();
	std::string getType();

	void parseDataFromFile(std::string);
	void parseData(std::string);
	
	//changes the time and date of a given ptime and returns the new ptime
	boost::posix_time::ptime changeTime (boost::posix_time::ptime, std::string);
	boost::posix_time::ptime changeDate (boost::posix_time::ptime, std::string);

	//returns the date of today and tmr in a string
	std::string getToday();
	std::string getTomorrow();
		
	//edits the given string to ensure that all backslashes are double slash
	std::string interpretDirectoryString (std::string);
};

#endif