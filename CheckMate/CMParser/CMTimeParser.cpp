// @author A0111405B
#include "CMTimeParser.h"

// Firstly, the delimiters are removed from the string. Next, am or pm is found and removed, 
// leaving only the numbers left. If the string length is less than 3, only hours remain, else,
// hours and minutes remain, with minutes being the last 2 digits.
void CMTimeParser::parseTime(std::string timeStr) {
	assert(timeStr.length() != 0); // An empty string should not be passed into this function

	std::string pmOrAm;

	_hours = 0;
	_minutes = 0;

	// To remove the delimiter
	int pos = timeStr.find_first_of(":");
	if (pos != timeStr.npos) {
		timeStr.erase(pos, 1);
	}

	// To determine if "am" or "pm" is present
	pos = timeStr.find_first_of("apAP");
	if (pos != timeStr.npos) {
		pmOrAm = (timeStr.substr(pos, 1));
		timeStr = timeStr.substr(0, pos);
		if (pmOrAm == "p" || pmOrAm == "P") {
			_hours = 12;
		}	
	}

	if (timeStr.length() < 3) {
		_hours += atoi(timeStr.c_str());
		if ((atoi(timeStr.c_str()) == 12) && (pmOrAm != "")) {
			_hours -= 12;
		}
		_minutes += 0;
	}
	else {
		_hours += atoi(timeStr.substr(0, timeStr.length() - 2).c_str());
		if ((atoi(timeStr.substr(0, timeStr.length()-2).c_str()) == 12) && (pmOrAm != "")) {
			_hours -= 12;
		}
		_minutes += atoi(timeStr.substr(timeStr.length() - 2, 2).c_str());
	}
	
	std::cout << "PARSER:: parsing time \"" << timeStr << "\"" << " to \"" << _hours << ":" << _minutes << "\"" <<std::endl;
}

void CMTimeParser::setHour(int hours) {
	try{
		if ((hours <= 24) && (hours >= 0)) {
			_hours = hours;
		} else {
			throw std::string ("ERROR: TRYING TO SET INVALID HOUR");
		}
	}
	catch (std::string e) {
		std::cerr << e << std::endl;
	}
}

void CMTimeParser::setMin(int minutes) {
	try{
		if ((minutes <= 60) && (minutes >= 0)) {
			_minutes = minutes;
		} else {
			throw std::string ("ERROR: TRYING TO SET INVALID MINUTE");
		}
	}
	catch (std::string e) {
		std::cerr << e << std::endl;
	}
}

int CMTimeParser::getHour() {
	return _hours;
}

int CMTimeParser::getMin() {
	return _minutes;
}