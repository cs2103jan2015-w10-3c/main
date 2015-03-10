#ifndef CMPARSER_H
#define CMPARSER_H

#include <iostream> 
#include <string> 
#include <boost/date_time.hpp>

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

class CMParser {
private:
	ptime getDateAndTime(string str);
		
public:
	string getDescription(string str, string type);
	ptime getStart(string str, string type);
	ptime getEnd(string str);
	string getCategory(string str);
};

#endif