#ifndef CMDATEPARSER_H
#define CMDATEPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <boost/date_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

class CMDateParser {
private:
	int getIndexFromWeekdayName (std::string);
	date getDateFromWeekdayName(std::string);
	date getDate(std::string);

public:
	date parseDate(std::string);
	bool isWeekdayName (std::string);
};

#endif