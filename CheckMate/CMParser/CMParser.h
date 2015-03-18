#ifndef CMPARSER_H
#define CMPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include "boost/date_time.hpp"


using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

class CMParser {
private:
	ptime getDateAndTime(std::string str);
	bool hasTime(std::string str);
	bool hasDate(std::string str);
	std::string _description;
	std::string _category;
	ptime _start;
	ptime _end;
public:
	std::string getDescription(std::string str, std::string type);
	ptime getStart(std::string str, std::string type);
	ptime getEnd(std::string str);
	std::string getCategory(std::string str);
	
};

#endif