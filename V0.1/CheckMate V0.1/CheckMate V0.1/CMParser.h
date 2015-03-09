#ifndef CMPARSER_H
#define CMPARSER_H

#include <iostream> 
#include <string> 
#include <boost/date_time.hpp>

using namespace std;

class CMParser {
private:

public:
	string getDescription(string str);
	string getStartDate(string str);
	string getStartTime(string str);
	string getEndDate(string str);
	string getEndTime(string str);
	string getCategory(string str);
	

};


#endif