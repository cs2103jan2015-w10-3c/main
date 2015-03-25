#include "CMParser.h"

ptime CMParser::getDateAndTime(std::string str) {
	std::string timeStr, dateStr;
	date d;
	int lastSpace = str.find_last_of(" ");

	if (hasTime(str) && hasDate(str)){
		std::cout <<"has both";
		timeStr = str.substr(lastSpace+1);
		dateStr = str.erase(lastSpace);
		
		timeParser.parseTime(timeStr);
		
		d = dateParser.getDate(dateStr);
	}
	else if (hasDate(str)) {
		std::cout <<"has date";
		dateStr = str;
		
		timeParser.setHour(23);
		timeParser.setMin(59);
		
		d = dateParser.getDate(dateStr);
	}
	else if (hasTime(str)) {
		std::cout <<"has time";
		timeStr = str;
		
		timeParser.parseTime(timeStr);
		
		if (_start.date()==date())
			_start = second_clock::local_time();

		d = _start.date();
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
	
	for (int i=0; i<6; ++i) {
		if (str.find(validDate[i])!=str.npos) {
			return true;
		}
	}

	return false;
}

std::string CMParser::getDescription(std::string str, std::string type) {
	int pos = str.npos;

	if (type=="timed") {
		pos = str.rfind(" from ");
	} else if (type=="float") {
		pos = str.rfind(" cat ");
	} else if (type=="deadline") {
		pos = str.rfind(" by ");
	}

	if (pos!=str.npos) {
		_description = str.substr(0,pos);
	} else {
		_description = "";
	}

	return _description;
}

std::string CMParser::getCategory (std::string str){
	std::string str1;

	if (str.find(" cat ")==str.npos) {
		str1 = "-";
	} else {
		str1 = str.substr(str.find(" cat ")+5);
	}

	_category = str1;

	return _category;
}

ptime CMParser::getStart(std::string str, std::string type) {
	//type cannot be float (use exception)
	std::string startTimeAndDate;

	if (type == "timed") {
		startTimeAndDate = str.substr(str.rfind(" from ")+6);
		startTimeAndDate = startTimeAndDate.erase(startTimeAndDate.find(" to "));
	} else if (type == "deadline") {
		startTimeAndDate = str.substr(str.rfind(" by ")+4);
		
		int pos = startTimeAndDate.rfind(" cat ");
		
		if (pos!=startTimeAndDate.npos) {
			startTimeAndDate = startTimeAndDate.erase(pos);
		}
	}

	startTimeAndDate.substr(1);

	_start = getDateAndTime(startTimeAndDate);

	return _start;
}

ptime CMParser::getEnd(std::string str) {
	std::string endTimeAndDate;

	endTimeAndDate = str.substr(str.rfind(" to ")+4);

	int pos = endTimeAndDate.find(" cat ");

	if (pos!=endTimeAndDate.npos)
	endTimeAndDate.erase(pos);

	_end = getDateAndTime(endTimeAndDate);

	return _end;
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
	return ptime(dateParser.getDate(newDate), hours(current.time_of_day().hours())+minutes(current.time_of_day().minutes()));
}