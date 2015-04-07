#include "CMParser.h"

const std::string CMParser::TIMED = "timed";
const std::string CMParser::DEADLINE = "deadline";
const std::string CMParser::FLOAT = "float";
const std::string CMParser::TIME_ATTRIBUTE[6] = {":", "am", "pm", "PM", "AM", "."};
const std::string CMParser::VALID_DATE[6] = {"today", "tdy", "tomorrow", "tmr", " ", "/"};


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
		if (dateAndTime<second_clock::local_time()){
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

	for (int i=0; i<6; ++i) {
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
	for (int i=0; i<24; ++i) {
		if (str.find(connectingWords[i])!=str.npos) {
			return true;
		}
	}
	return false;
}

bool CMParser::isTdyOrTmr (std::string str) {
	for (int i=0; i<4; ++i) {
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
			//_type = _type+ "1";
			if ((isStart) && (isConnectingWord(tokens[i-1]))) {
				description.pop_back();
			}
			bufferTimeAndDate << tokens[i];
			if ((i+1<tokens.size())&&(hasTime(tokens[i+1]))) {
				bufferTimeAndDate << " " << tokens[i+1];
				++i;
			}
		} else if (dateParser.isWeekdayName(tokens[i])) {
			//_type = _type+ "2";
			if (tokens[i-1]=="next") {
				if (isStart) {
					description.pop_back();
				}
				if ((isStart) && (isConnectingWord(tokens[i-2]))) {
					description.pop_back();
				}
				bufferTimeAndDate << tokens[i-1];
			} else {
				if ((isStart) && (isConnectingWord(tokens[i-1]))) {
					description.pop_back();
				}
			}
			bufferTimeAndDate << " " << tokens[i];
			if ((i+1<tokens.size()) && (hasTime(tokens[i+1]))) {
				bufferTimeAndDate << " " << tokens[i+1];
				++i;
			}
		} else if (dateParser.parseDate(buffer)!=date()) {
			//_type = _type + "3";
			if ((isStart) && (isConnectingWord(tokens[i-1]))) {
				description.pop_back();
			}
			bufferTimeAndDate << tokens[i];
			if ((i+1<tokens.size()) && (hasTime(tokens[i+1]))) {
				bufferTimeAndDate << " " << tokens[i+1];
				++i;
			}
		} else if (dateParser.isMonth(tokens[i])) {
			//_type = _type+ "4";
			int date = atoi(tokens[i-1].c_str());
			if ((date>=1) && (date <=31)) {
				if ((isStart) && (isConnectingWord(tokens[i-2]))) {
					description.pop_back();
				}
				if (isStart) {
					description.pop_back();
				}
				bufferTimeAndDate << tokens[i-1] <<" "<<tokens[i];
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
			//_type = _type+ "5";
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
	_type = _type + startTimeAndDate+"!"+endTimeAndDate;
	//_start = ptime();
	//_end = ptime();
	
	_start = getDateAndTime(startTimeAndDate);
	_end = getDateAndTime(endTimeAndDate);
	determineType();
	

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
	
	/*std::string startTimeAndDate;
	std::string endTimeAndDate;
	_start = ptime();
	_end = ptime();
	int pos = str.find_last_not_of(" ");
	str.erase(pos+1);
	pos = str.find_last_of(" ");
	
	_type = TIMED;

	if (str[pos+1]=='-'){
		_end = ptime();
		pos = str.find_last_of("-", pos);
		str.erase(pos);
		_type = DEADLINE;
	} else {
		pos = str.find_last_of(" ", pos-1);
		endTimeAndDate = str.substr(pos+1);
		_end = time_from_string(endTimeAndDate);
	}
	pos = str.find_last_not_of(" ", pos);
	str.erase(pos+1);

	pos = str.find_last_of(" ",pos-1);
	if (str[pos+1]=='-'){
		_start = ptime();
		pos = str.find_last_of("-", pos);
		str.erase(pos);
		_type = FLOAT;
	} else {
		pos = str.find_last_of(" ", pos-1);
		startTimeAndDate = str.substr(pos+1);
		_start = time_from_string(startTimeAndDate);
	}
	pos = str.find_last_not_of(" ", pos);
	str.erase(pos+1);

	_description = str;
	*/
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

	return directory;
}