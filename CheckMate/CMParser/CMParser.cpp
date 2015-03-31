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
		_description = str.substr(0, pos);
		startTimeAndDate = str.substr(str.rfind(" from ")+6);
					
		if (startTimeAndDate.find(" to ")!=startTimeAndDate.npos) {
			startTimeAndDate = startTimeAndDate.erase(startTimeAndDate.find(" to "));
			_start = getDateAndTime(startTimeAndDate);
	
			endTimeAndDate = str.substr(str.rfind(" to ")+4);
			_end = getDateAndTime(endTimeAndDate);
		} else {
			_start = getDateAndTime(startTimeAndDate);
			_end = _start + hours(1);
		}
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
	} else {
		pos = str.find_last_of(" ", pos-1);
		endTimeAndDate = str.substr(pos+1);
		_end = getDateAndTime(endTimeAndDate);
	}
	str.erase(pos);

	pos = str.find_last_of(" ",pos-1);
	if (str[pos+1]=='-'){
		_start = ptime();
	} else {
		pos = str.find_last_of(" ", pos-1);
		startTimeAndDate = str.substr(pos+1);
		_start = getDateAndTime(startTimeAndDate);
	}
	str.erase(pos);

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
//lunch with peter from time date || take poster from peter and pass to tom by tmr || take poster from peter and pass to tom
std::string CMParser::determineType(std::string str){
	if (str.find(" from ")!=str.npos) {
		std::string buffer = str.substr(str.rfind(" from ")+6);
		if (buffer.find(" to ")!=buffer.npos) {
			buffer = str.substr(str.rfind(" to ")+4);
		}
		if (buffer.find(" by ")==buffer.npos) {
			if (getDateAndTime(buffer)!=ptime())
				return "timed";
		}
	}
	/*
	if (str.find(" to ")!=str.npos) {
		int pos = str.rfind(" to ")+4;
		std::string buffer = str.substr(pos);
		if ((buffer.find(" by ")==buffer.npos) && (hasDate(buffer) || hasTime(buffer))) {
			return "timed";
		}
	}
	*/
	if (str.find(" by ")!=str.npos) {
		int pos = str.rfind(" by ") + 4;
		std::string buffer = str.substr(str.rfind(" by ")+4);
		if (getDateAndTime(buffer)!=ptime()) {
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

std::string CMParser::interpretDirectoryString (std::string directory){
	bool singleSlash = false;
	bool doubleSlash = false;

	for (size_t i=0; i<directory.length(); ++i) {
		if (directory[i]=='/'){
			if (!singleSlash){
				singleSlash = true;
			} else {
				doubleSlash = true;
				singleSlash = false;
			}
			if (doubleSlash) {
				directory.erase(i, 1);
			}
		} else {
			if (singleSlash) {
				directory.insert(i, "/");
			}
			singleSlash = false;
			doubleSlash = false;
		}
	}
		/*

	
	size_t found = directory.find("/");
	while (found!=directory.npos) {
		directory.insert(found, "/");
		found=found+2;
		found = directory.find("/", found);
	}*/
	return directory;
}