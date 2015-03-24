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
	std::string _description;
	std::string _category;
	ptime _start;
	ptime _end;
	CMDateParser dateParser;
	CMTimeParser timeParser;

	ptime getDateAndTime(std::string str);
	bool hasTime(std::string str);
	bool hasDate(std::string str);

public:
	std::string getDescription(std::string str, std::string type);
	std::string getCategory(std::string str);
	ptime getStart(std::string str, std::string type);
	ptime getEnd(std::string str);
	
	ptime changeTime (ptime, std::string);
	ptime changeDate (ptime, std::string);
	
	std::string getToday();
	std::string getTomorrow();
};

#endif