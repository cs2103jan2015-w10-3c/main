#include "CMTimeParser.h"

void CMTimeParser::parseTime(std::string timeStr) {
	_hours=0;
	_minutes=0;
	std::string pmOrAm;

	//to remove the delimiter
	int pos = timeStr.find_first_of(":");
	if (pos!=timeStr.npos)
		timeStr.erase(pos, 1);

	pos = timeStr.find_first_of("apAP");
	if (pos!=timeStr.npos) {
		pmOrAm = (timeStr.substr(pos, 1));
		timeStr = timeStr.substr(0, pos);
		if (pmOrAm=="p") {
			_hours = 12;
		}	
	}
	if (timeStr.length()<3) {
		_hours += atoi(timeStr.c_str());
		if ((atoi(timeStr.c_str())==12) && (pmOrAm!="")) {
			_hours -= 12;
		}
		_minutes += 0;
	}
	else {
		_hours += atoi(timeStr.substr(0, timeStr.length()-2).c_str());
		if ((atoi(timeStr.c_str())==12) && (pmOrAm!="")) {
			_hours -= 12;
		}
		_minutes += atoi(timeStr.substr(timeStr.length()-2, 2).c_str());
	}
}

void CMTimeParser::setHour(int hours) {
	_hours = hours;
}

void CMTimeParser::setMin(int minutes) {
	_minutes = minutes;
}

int CMTimeParser::getHour() {
	return _hours;
}

int CMTimeParser::getMin() {
	return _minutes;
}