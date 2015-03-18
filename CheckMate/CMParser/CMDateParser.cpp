#include "CMDateParser.h"

date CMDateParser::getDate(std::string str) {
	date d, today = day_clock::local_day();
	int pos;
	std::string dateStr, monthStr, yearStr;
	
	if (str=="today" || str=="tdy") {
		return today;
	}

	pos = str.find_first_of(" /");
	dateStr = str.substr(0, pos);
	str.erase(0, pos+1);

	pos = str.find_first_of(" /");
	monthStr = str.substr(0, pos);
	str.erase(0, pos+1);

	if (pos==str.npos) {
		std::ostringstream os;
		os<<today.year();
		yearStr = os.str();
	}
	else {
		yearStr = str;
		int yr = atoi(yearStr.c_str());
		if (yr<2000) {
			yr = yr + 2000;
		}
		yearStr = std::to_string(yr);
	}
	
	std::stringstream UKFormat;
	UKFormat << dateStr <<" "<< monthStr <<" "<< yearStr;
	d = from_uk_string(UKFormat.str());
	
	return d;
}