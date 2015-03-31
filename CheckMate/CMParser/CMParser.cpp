#include "CMParser.h"

ptime CMParser::getDateAndTime(std::string str) {
	std::string timeStr, dateStr;
	date d;
	int lastSpace = str.find_last_of(" ");
	
	for (size_t i=0; i<str.length(); ++i) {
		str[i]=tolower(str[i]);
	}
	
	if (hasTime(str) && hasDate(str)){
		std::cout <<"has both";
		timeStr = str.substr(lastSpace+1);
		dateStr = str.erase(lastSpace);
		
		timeParser.parseTime(timeStr);
		
		d = dateParser.parseDate(dateStr);
	}
	else if (hasDate(str)) {
		std::cout <<"has date";
		dateStr = str;
		
		timeParser.setHour(23);
		timeParser.setMin(59);
		
		d = dateParser.parseDate(dateStr);
	}
	else if (hasTime(str)) {
		std::cout <<"has time";
		timeStr = str;
		
		timeParser.parseTime(timeStr);
		
		if (_start.date()==date())
			_start = second_clock::local_time();

		d = _start.date();
	} else {
		return ptime();
	} 
	
	return ptime(d ,hours(timeParser.getHour())+minutes(timeParser.getMin()));
}

bool CMParser::hasTime(std::string str) {
	std::string timeAttributes[6] = {":", "am", "pm", "PM", "AM", "."};

	for (int i=0; i<6; ++i) {
		if (str.find(timeAttributes[i])!=str.npos) {
			return true;
		}
	}

	return false;
}

bool CMParser::hasDate(std::string str) {
	std::string validDate[6] = {"today", "tdy", "tomorrow", "tmr", " ", "/"};
	
	if (dateParser.isWeekdayName(str)) {
		return true;
	}

	for (int i=0; i<6; ++i) {
		if (str.find(validDate[i])!=str.npos) {
			return true;
		}
	}

	return false;
}
void CMParser::parseData(std::string str, std::string type) {
	int pos;
	std::string startTimeAndDate;
	std::string endTimeAndDate;

	if (type=="timed") {
		pos = str.rfind(" from ");
		_description = str.substr(0,pos);

		startTimeAndDate = str.substr(str.rfind(" from ")+6);
		startTimeAndDate = startTimeAndDate.erase(startTimeAndDate.find(" to "));
		_start = getDateAndTime(startTimeAndDate);

		endTimeAndDate = str.substr(str.rfind(" to ")+4);
		_end = getDateAndTime(endTimeAndDate);
	} else if (type=="deadline") {
		pos = str.rfind(" by ");
		_description = str.substr(0,pos);

		startTimeAndDate = str.substr(str.rfind(" by ")+4);
		_start = getDateAndTime(startTimeAndDate);

		_end = ptime();
	} else if (type=="float") {
		_description = str;
		_start = ptime();
		_end = ptime();
	} 
	
}

void CMParser::parseDataFromFile(std::string str){
	std::string startTimeAndDate;
	std::string endTimeAndDate;
	int pos = str.find_last_of(" ");

	if (str[pos+1]=='-'){
		_end = ptime();
<<<<<<< HEAD
=======
		pos = str.find_last_of("-", pos);
		_type = "deadline";
>>>>>>> 48e009e649ff6d6cabf2f2defa281bfc2b05c550
	} else {
		pos = str.find_last_of(" ", pos-1);
		endTimeAndDate = str.substr(pos+1);
		_end = time_from_string(endTimeAndDate);
	}
	pos = str.find_last_not_of(" ",pos);
	str.erase(pos+1);
	pos = str.find_last_of(" ",pos-1);
	if (str[pos+1]=='-'){
		_start = ptime();
	} else {
		pos = str.find_last_of(" ", pos-1);
		startTimeAndDate = str.substr(pos+1);
		_start = time_from_string(startTimeAndDate);
	}
	pos = str.find_last_not_of(" ",pos);
	str.erase(pos+1);

	_description = str;
}

std::string CMParser::getDescription() {
	return _description;
}

ptime CMParser::getStart() {
	return _start;
}

ptime CMParser::getEnd() {
	return _end;
}

std::string CMParser::determineType(std::string str){
<<<<<<< HEAD
	if ((str.find(" from ")!=str.npos)||(str.find(" to ")!=str.npos)) {
=======

	if (str.find(" from ")!=str.npos) {
		std::string start = str.substr(str.rfind(" from ")+6);
		if (start.find(" by ")==start.npos) {
			if (start.find(" to ")!=start.npos) {
				start = start.erase(start.find(" to "));
				if (getDateAndTime(start)!=ptime()){
					std::string end = str.substr(str.rfind(" to ")+4);
					if (getDateAndTime(end)!=ptime()){
						return "timed";
					}
				}
			} else {
				if (getDateAndTime(start)!=ptime()){
					return "timed";
				}
			}
		}
	}
	/*
	if (str.find(" to ")!=str.npos) {
>>>>>>> 48e009e649ff6d6cabf2f2defa281bfc2b05c550
		int pos = str.rfind(" to ")+4;
		std::string buffer = str.substr(pos);
		if ((buffer.find(" by ")==buffer.npos) && (hasDate(str.substr(pos)) || hasTime(str.substr(pos)))) {
			return "timed";
		}
	}

	if (str.find(" by ")!=str.npos) {
		int pos = str.rfind(" by ") + 4;
		if (hasDate(str.substr(pos))||hasTime(str.substr(pos))) {
			return "deadline";
		}
	}
	return "float";
}

std::string CMParser::getToday() {
	date today = day_clock::local_day();
	date_facet* date_output = new date_facet();


	std::ostringstream output;
	output.imbue(std::locale(output.getloc(), date_output)); 
	
	output<<today;

	return output.str();
}

std::string CMParser::getTomorrow() {
	date tomorrow = day_clock::local_day()+date_duration(1);
	date_facet* date_output = new date_facet();
	date_output->format("%d %b %Y");

	std::ostringstream output;
	output.imbue(std::locale(output.getloc(), date_output)); 
	
	output<<tomorrow;

	return output.str();
}

ptime CMParser::changeTime (ptime current, std::string newTime) {
	date currentDate = current.date();
	timeParser.parseTime(newTime);
	
	return ptime(currentDate ,hours(timeParser.getHour())+minutes(timeParser.getMin()));
}

ptime CMParser::changeDate (ptime current, std::string newDate) {
	return ptime(dateParser.parseDate(newDate), hours(current.time_of_day().hours())+minutes(current.time_of_day().minutes()));
}