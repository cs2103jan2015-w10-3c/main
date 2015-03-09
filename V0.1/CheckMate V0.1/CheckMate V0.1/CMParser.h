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

public:
	string getDescription(string str);
	string getStartDate(string str, string type);
	string getStartTime(string str, string type);
	string getEndDate(string str);
	string getEndTime(string str);
	string getCategory(string str);

};


#endif