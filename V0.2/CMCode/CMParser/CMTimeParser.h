#ifndef CMTIMEPARSER_H
#define CMTIMEPARSER_H

#include <iostream> 
#include <string> 
#include <sstream>
#include <boost/date_time.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

class CMTimeParser {
private:
	int _hours;
	int _minutes;
		
public:
	void parseTime(std::string str);
	void setHour(int hours);
	void setMin(int minutes);
	int getHour();
	int getMin();
	
};

#endif