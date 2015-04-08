#include "CMDateParser.h"
date today = day_clock::local_day();

int CMDateParser::getIndexFromWeekdayName (std::string str) {
	std::string longWeekdayName[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
	std::string abbreviatedWeekdayName[7] = {"sun", "mon", "tue", "wed", "thur", "fri", "sat"};

	for (int i=0; i<7; ++i){
		if (str.find(longWeekdayName[i])!=str.npos) {
			return i;
		}
	}
	for (int j=0; j<7; ++j){
		if (str.find(abbreviatedWeekdayName[j])!=str.npos) {
			return j;
		}
	}
	return -1;
}


bool CMDateParser::isWeekdayName (std::string str){
	if (getIndexFromWeekdayName(str)>=0){
			return true;
	} else {
		return false;
	}
}

date CMDateParser::getDateFromWeekdayName(std::string str) {
	date d=today;
	int index = getIndexFromWeekdayName(str);

	while (d.day_of_week()!=index) {
		d = d + date_duration(1);
	}

	if (str.find("next")!=str.npos) {
		d = d + date_duration(7);
	}

	return d;
}

date CMDateParser::getDate(std::string str) {
	std::string month[13] = {"","jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sept", "oct", "nov", "dec"};	
	date d;
	bool validDate = false, validMonth = false, validYear = false;
	std::string dateStr, monthStr, yearStr;

	if (str=="today" || str=="tdy") {
		return today;
	} else if (str=="tomorrow"||str=="tmr") {
		return (today + date_duration(1));
	}

	int pos = str.find_first_of(" /");
	dateStr = str.substr(0, pos);
	str.erase(0, pos+1);

	pos = str.find_first_of(" /");
	monthStr = str.substr(0, pos);
	str.erase(0, pos+1);

	if (pos==str.npos) {
		std::ostringstream os;
		os<<today.year();
		yearStr = os.str();
	} else {
		yearStr = str;
		int yr = atoi(yearStr.c_str());
		if (yr<2000) {
			yr = yr + 2000;
		}
		yearStr = std::to_string(yr);
	}

	std::stringstream UKFormat;
	UKFormat << dateStr <<" "<< monthStr <<" "<< yearStr;

	if ((atoi(dateStr.c_str())>=1)&&(atoi(dateStr.c_str())<=31)){
		validDate = true; 
	}
	
	for (int i=1; i<13; ++i) {
		if ((atoi(monthStr.c_str())==i)||(monthStr.find(month[i])!=monthStr.npos)) {
			validMonth = true;
		}
	}

	if (atoi(yearStr.c_str())>=2015){
			validYear = true; 
		}
	
	if ((validDate) && (validMonth) && (validYear)) {
		d = from_uk_string(UKFormat.str());
	} else d = date();

	return d;
}

date CMDateParser::parseDate(std::string str) {
	if (str.find("'")!=str.npos){
		return date();
	}

	if (isWeekdayName(str)){
		return getDateFromWeekdayName(str);
	} else {
		return getDate(str);
	}
}