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
	CMDateParser dateParser;
	CMTimeParser timeParser;

	std::string _description;
	std::string _category;
	ptime _start;
	ptime _end;

	ptime getDateAndTime(std::string);
	bool hasTime(std::string);
	bool hasDate(std::string);

public:
	std::string getDescription();
	ptime getStart();
	ptime getEnd();

	std::string determineType(std::string);
	
	ptime changeTime (ptime, std::string);
	ptime changeDate (ptime, std::string);
	
	std::string getToday();
	std::string getTomorrow();

	void parseDataFromFile(std::string);
	void parseData(std::string, std::string);

	std::string interpretDirectoryString (std::string);
};

#endif