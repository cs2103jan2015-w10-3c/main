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
	static const std::string MONTH[24];
	static const std::string LONG_WEEKDAY_NAME[7];
	static const std::string ABBREVIATED_WEEKDAY_NAME[7];

	int getIndexFromWeekdayName (std::string);
	date getDateFromWeekdayName(std::string);
	date getDate(std::string);

public:
	date parseDate(std::string);
	bool isWeekdayName (std::string);
	bool isMonth(std::string);
};

#endif