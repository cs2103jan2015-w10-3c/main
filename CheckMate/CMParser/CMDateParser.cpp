//@author A0111405B
#include "CMDateParser.h"

boost::gregorian::date today = boost::gregorian::day_clock::local_day();

const std::string CMDateParser::MONTH[24] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", 
											"oct", "nov", "dec", "january", "february", "march", "april", "may",
											"june", "july", "august", "september", "october", "november", 
											"december"};
const std::string CMDateParser::LONG_WEEKDAY_NAME[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", 
														"friday", "saturday"};
const std::string CMDateParser::ABBREVIATED_WEEKDAY_NAME[7] = {"sun", "mon", "tue", "wed", "thur", "fri", "sat"};
const std::string CMDateParser::VALID_DATE[8] = {"tmrw", "today", "tdy", "tomorrow", "tmr", " ", "/", "."};

const int CMDateParser::NOT_FOUND = -1;

bool CMDateParser::isMonth(std::string str) {
	// Convert given string to lower case
	boost::algorithm::to_lower(str);

	// Checking if given string is a month
	for (int i = 0; i < 24; ++i) {
		if (str.find(MONTH[i]) != str.npos) {
			return true;
		}
	}
	return false;
}

int CMDateParser::getIndexFromWeekdayName (std::string str) {
	boost::algorithm::to_lower(str);
	
	// Checking if given string is a long weekday name
	for (int i = 0; i < 7; ++i){
		if (str.find(LONG_WEEKDAY_NAME[i]) != str.npos) {
			return i;
		}
	}

	// Checking if given string is a abreviated weekday name
	for (int j = 0; j < 7; ++j){
		if (str.find(ABBREVIATED_WEEKDAY_NAME[j]) != str.npos) {
			return j;
		}
	}
	return NOT_FOUND;
}

bool CMDateParser::isWeekdayName (std::string str){
	if (getIndexFromWeekdayName(str) >= 0){
		return true;
	} else {
		return false;
	}
}

boost::gregorian::date CMDateParser::getDateFromWeekdayName(std::string str) {
	boost::gregorian::date bufferDate = today;
	int index = getIndexFromWeekdayName(str);
	
	assert ((index >= 0) && (index < 7)); 

	while (bufferDate.day_of_week() != index) {
		bufferDate = bufferDate + boost::gregorian::date_duration(1);
	}

	if (str.find("next") != str.npos) {
		bufferDate = bufferDate + boost::gregorian::date_duration(7);
	}
	return bufferDate;
}


boost::gregorian::date CMDateParser::getDate(std::string str) {
	boost::gregorian::date bufferDate;
	bool validDate = false;
	bool validMonth = false; 
	bool validYear = false;
	std::string dateStr;
	std::string monthStr;
	std::string yearStr;

	if (str == "today" || str == "tdy") {
		return today;
	} else if (str == "tomorrow" || str == "tmr" || str == "tmrw") {
		return (today + boost::gregorian::date_duration(1));
	}

	int pos = str.find_first_of(" ./");
	if (pos == str.npos){
		return boost::gregorian::date();
	}

	dateStr = str.substr(0, pos);
	
	if (dateStr.length() > 2) {
		dateStr.erase(dateStr.length() - 2);
	}

	str.erase(0, pos + 1);

	pos = str.find_first_of(" ./");
	monthStr = str.substr(0, pos);
	str.erase(0, pos + 1);

	if (pos == str.npos) {
		std::ostringstream os;
		os << today.year();
		yearStr = os.str();
	} else {
		yearStr = str;
		int yr = atoi(yearStr.c_str());
		if (yr < 2000) {
			yr = yr + 2000;
		}
		yearStr = std::to_string(yr);
	}

	std::stringstream UKFormat;
	UKFormat << dateStr << " " << monthStr << " " << yearStr;

	if ((atoi(dateStr.c_str()) >= 1)&&(atoi(dateStr.c_str()) <= 31)){
		validDate = true; 
	}
	
	for (int i = 0; i < 12; ++i) {
		if ((atoi(monthStr.c_str()) == i + 1) || (monthStr.find(MONTH[i]) != monthStr.npos)) {
			validMonth = true;
		}
	}

	if (atoi(yearStr.c_str()) >= 2015){
			validYear = true; 
		}
	
	if ((validDate) && (validMonth) && (validYear)) {
		bufferDate = boost::gregorian::from_uk_string(UKFormat.str());
	} else {
		bufferDate = boost::gregorian::date();
	}

	return bufferDate;
}

boost::gregorian::date CMDateParser::parseDate(std::string str) {
	boost::gregorian::date bufferDate;

	if (isWeekdayName(str)){
		bufferDate = getDateFromWeekdayName(str);
	} else {
		bufferDate = getDate(str);
	}
	std::cout << "PARSER:: parsing date \"" << str << "\"" << " to \"" << bufferDate << "\"" <<std::endl;
	
	return bufferDate;
}

bool CMDateParser::isTdyOrTmr (std::string str) {
	assert( str != "");

	for (int i = 0; i < 5; ++i) {
		if (str == VALID_DATE[i]) {
			return true;
		}
	}
	return false;
}

bool CMDateParser::hasDate(std::string str) {
	if (isWeekdayName(str)) {
		return true;
	}

	for (int i = 0; i < 8; ++i) {
		if (str.find(VALID_DATE[i]) != str.npos) {
			return true;
		}
	}

	return false;
}