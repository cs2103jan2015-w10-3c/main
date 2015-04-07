#ifndef CMPARSER_H
#define CMPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include "boost/date_time.hpp"
#include "CMDateParser.h"
#include "CMTimeParser.h"

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

class CMParser {
private:
	static const std::string TIMED;
	static const std::string DEADLINE;
	static const std::string FLOAT;
	static const std::string TIME_ATTRIBUTE[6];
	static const std::string VALID_DATE[6];
	
	CMDateParser dateParser;
	CMTimeParser timeParser;

	std::string _description;
	ptime _start;
	ptime _end;
	std::string _type;

	void determineType();
	ptime getDateAndTime(std::string);
	bool hasTime(std::string);
	bool hasDate(std::string);
	bool isConnectingWord(std::string str);
	bool isTdyOrTmr (std::string str);

public:
	//getter functions for private attributes
	std::string getDescription();
	ptime getStart();
	ptime getEnd();
	std::string getType();

	void parseDataFromFile(std::string);
	void parseData(std::string);
	
	//changes the time and date of a given ptime and returns the new ptime
	ptime changeTime (ptime, std::string);
	ptime changeDate (ptime, std::string);

	//returns the date of today and tmr in a string
	std::string getToday();
	std::string getTomorrow();
		
	//edits the given string to ensure that all backslashes are double slash
	std::string interpretDirectoryString (std::string);
};

#endif