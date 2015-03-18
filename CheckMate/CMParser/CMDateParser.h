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
	
public:
	date getDate(std::string str);
};

#endif