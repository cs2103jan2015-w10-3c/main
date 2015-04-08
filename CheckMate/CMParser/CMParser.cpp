#include "CMParser.h"

const std::string CMParser::TIMED = "timed";
const std::string CMParser::DEADLINE = "deadline";
const std::string CMParser::FLOAT = "float";
const std::string CMParser::TIME_ATTRIBUTE[6] = {":", "am", "pm", "PM", "AM", "."};
const std::string CMParser::VALID_DATE[7] = {"tmrw", "today", "tdy", "tomorrow", "tmr", " ", "/"};


ptime CMParser::getDateAndTime(std::string str) {
	std::string timeStr, dateStr;
	ptime dateAndTime;
	date d;

	int lastSpace = str.find_last_of(" ");
	
	for (size_t i=0; i<str.length(); ++i) {
		str[i]=tolower(str[i]);
	}
	
	if (hasTime(str) && hasDate(str)){
		timeStr = str.substr(lastSpace+1);
		dateStr = str.erase(lastSpace);
		
		timeParser.parseTime(timeStr);
		
		d = dateParser.parseDate(dateStr);
		dateAndTime = ptime(d ,hours(timeParser.getHour())+minutes(timeParser.getMin()));
	}
	else if (hasDate(str)) {
		dateStr = str;
		
		timeParser.setHour(23);
		timeParser.setMin(59);
		
		d = dateParser.parseDate(dateStr);
		dateAndTime = ptime(d ,hours(timeParser.getHour())+minutes(timeParser.getMin()));
	}
	else if (hasTime(str)) {
		timeStr = str;
		timeParser.parseTime(timeStr);
		
		if (_start.date()==date())
			_start = second_clock::local_time();

		d = _start.date();
		dateAndTime = ptime(d ,hours(timeParser.getHour())+minutes(timeParser.getMin()));
		if (dateAndTime<second_clock::local_time() || dateAndTime<_start){
			dateAndTime += date_duration(1);	
		}
	} else {
		dateAndTime = ptime();
	} 
	
	return dateAndTime;
}

bool CMParser::hasTime(std::string str) {
	for (int i=0; i<6; ++i) {
		if (str.find(TIME_ATTRIBUTE[i])!=str.npos) {
			return true;
		}
	}
	
	return false;
}

bool CMParser::hasDate(std::string str) {
	if (dateParser.isWeekdayName(str)) {
		return true;
	}

	for (int i=0; i<7; ++i) {
		if (str.find(VALID_DATE[i])!=str.npos) {
			return true;
		}
	}

	return false;
}

bool CMParser::isConnectingWord(std::string str) {
	std::string connectingWords[5] = {"from", "to", "on", "by", "due"};
	for (size_t i=0; i<str.length(); ++i) {
		str[i]=tolower(str[i]);
	}
	for (int i=0; i<5; ++i) {
		if (str==connectingWords[i]) {
			return true;
		}
	}
	return false;
}

bool CMParser::isTdyOrTmr (std::string str) {
	for (int i=0; i<5; ++i) {
		if (str==VALID_DATE[i]) {
			return true;
		}
	}
	return false;
}

void CMParser::parseData(std::string str) {
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string buffer;
	std::string startTimeAndDate; 
	std::string endTimeAndDate;
	std::vector<std::string> description;
	bool isDescription = true;
	bool isStart = true;
	_start = ptime();
	_end = ptime();
	
	while (ss>>buffer){
		tokens.push_back(buffer);
	}

	for (unsigned int i=0; i<tokens.size(); ++i) {
		std::ostringstream bufferTimeAndDate;
		buffer = tokens[i];
		if (isTdyOrTmr(tokens[i])) {
			bufferTimeAndDate << tokens[i];
			if ((i+1<tokens.size())&&(hasTime(tokens[i+1]))) {
				bufferTimeAndDate << " " << tokens[i+1];
				++i;
			}
		} else if (dateParser.isWeekdayName(tokens[i])) {
			if (tokens[i-1]=="next") {
					description.pop_back();
					bufferTimeAndDate << tokens[i-1]<<" ";
			} 
			bufferTimeAndDate <<tokens[i];
			if ((i+1<tokens.size()) && (hasTime(tokens[i+1]))) {
				bufferTimeAndDate << " " << tokens[i+1];
				++i;
			}
		} else if (dateParser.parseDate(buffer)!=date()) {
			bufferTimeAndDate << tokens[i];
			if ((i+1<tokens.size()) && (hasTime(tokens[i+1]))) {
				bufferTimeAndDate << " " << tokens[i+1];
				++i;
			}
		} else if (dateParser.isMonth(tokens[i])) {
			std::string dateStr = tokens[i-1];
			if (dateStr.length()>2) {
				dateStr.erase(dateStr.length()-2);

			}
			int date = atoi(dateStr.c_str());
			if ((date>=1) && (date <=31)) {
				if (isStart) {
					description.pop_back();
				}
				bufferTimeAndDate << dateStr <<" "<<tokens[i];
				if ((i+1<tokens.size()) && (atoi(tokens[i+1].c_str())>=1)){
					bufferTimeAndDate << " " << tokens[i+1];
				}
				if ((i+2<tokens.size()) && (hasTime(tokens[i+2]))) {
					bufferTimeAndDate << " " << tokens[i+2];
					i=i+2;
				} else {
					++i;
				}
			}
		} else if (hasTime(tokens[i])) {
			bufferTimeAndDate << tokens[i];
		}
		
		if (!(bufferTimeAndDate.str().empty())){
			if (isStart) {
				startTimeAndDate = bufferTimeAndDate.str();
				isStart = false;
				isDescription = false;
			} else {
				endTimeAndDate = bufferTimeAndDate.str();
				isDescription = false;
			}
		}

		if (isDescription){
			description.push_back(buffer);
		} 
	}
	_start = getDateAndTime(startTimeAndDate);
	_end = getDateAndTime(endTimeAndDate);
	determineType();
	if (_type==DEADLINE){
		_end = _start;
		_start = ptime();
	}
	if (!description.empty()){
		if (isConnectingWord(description.back())) {
			description.pop_back();
		}
	}

	std::string s;

	for (std::vector<std::string>::const_iterator i = description.begin(); i != description.end(); ++i) {
		if (i==description.begin()){
			s += *i;
		} else {
			s += " ";
			s += *i;
		}
	}
	
	_description = s;
	
}

void CMParser::parseDataFromFile(std::string str){
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string buffer;
	std::string startTimeAndDate; 
	std::string endTimeAndDate;
	std::vector<std::string> description;
	bool isDescription = true;
	bool isStart = true;
	date bufferDate;
	_start = ptime();
	_end = ptime();

	while (ss>>buffer){
		tokens.push_back(buffer);
	}


	for (unsigned int i=0; i<tokens.size(); ++i) {
		buffer = tokens[i];
		std::istringstream bufferTimeAndDate(buffer);
	//	bufferTimeAndDate.imbue(std::locale(std::locale::classic(), new date_input_facet("%d-%m-%Y")));
		bufferTimeAndDate>>bufferDate;
		if (buffer=="-") {
			++i;
			isDescription = false;
		} else if (bufferDate!=date()){
			if (isStart) {
				startTimeAndDate = tokens[i] + " " + tokens[i+1];
				_start = time_from_string(startTimeAndDate);
				isStart = false;
			} else {
				endTimeAndDate = tokens[i] + " " + tokens[i+1];
				_end = time_from_string(endTimeAndDate);
			}
			isDescription = false;
			++i;
		} 
		
		if (isDescription){
			description.push_back(buffer);
		} 
	}
	determineType();

	if (_type==DEADLINE){
		_end = _start;
		_start = ptime();
	}
	
	std::string s;
	for (std::vector<std::string>::const_iterator i = description.begin(); i != description.end(); ++i) {
		if (i==description.begin()){
			s += *i;
		} else {
			s += " ";
			s += *i;
		}
	}
	_description = s;
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

std::string CMParser::getType() {
	return _type;
}

void CMParser::determineType(){
	if (_start == ptime()){
		_type = FLOAT;
	} else if (_end == ptime()) {
		_type = DEADLINE;
	} else {
		_type = TIMED;
	}
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
//	date_output->format("%d %b %Y");

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
	if (directory==""){
		return directory;
	} else return directory+"\\";
}