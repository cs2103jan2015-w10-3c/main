//@author A0111405B
#include "CMParser.h"

const std::string CMParser::TIMED = "timed";
const std::string CMParser::DEADLINE = "deadline";
const std::string CMParser::FLOAT = "float";
const std::string CMParser::TIME_ATTRIBUTE[3] = {":", "am", "pm"};
const std::string CMParser::VALID_DATE[8] = {"tmrw", "today", "tdy", "tomorrow", "tmr", " ", "/", "."};
const std::string CMParser::connectingWords[6] = {"from", "to", "on", "by", "due", "at"};

void CMParser::parseData(std::string str) {
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string buffer;
	std::string timeAndDate1; 
	std::string timeAndDate2;
	std::vector<std::string> description;
	
	bool isDescription = true;
	bool isStart = true;
	bool openInvertedCommas = false;
	
	_start = boost::posix_time::ptime();
	_end = boost::posix_time::ptime();

	try{
		if (str.length() == 0 ) {
			_description = "";
			_type = "";

			throw std::string("ERROR: NOTHING TO PARSE");
		} else {
			std::cout << "PARSER: parsing from input \"" << str << "\"" << std::endl; 
		
			while (ss >> buffer){
				tokens.push_back(buffer);
			}

			for (unsigned int i = 0; i < tokens.size(); ++i) {
				std::ostringstream bufferTimeAndDate;
				buffer = tokens[i];

				if (buffer.find('"') != buffer.npos) {
					description.push_back(buffer);
			
					if (openInvertedCommas) {
						openInvertedCommas = false;	
					} else {
						openInvertedCommas = true;
					}
					if (buffer.find('"') != buffer.rfind('"')) {
						openInvertedCommas = false;
					}
					continue;
				}

				if (isTdyOrTmr(tokens[i])) {
						bufferTimeAndDate << tokens[i];
						if ((i+1 < tokens.size()) && (hasTime(tokens[i+1]))) {
							bufferTimeAndDate << " " << tokens[i+1];
							++i;
						}
					} else if (dateParser.isWeekdayName(tokens[i])) {
						if (tokens[i-1] == "next") {
							description.pop_back();
							bufferTimeAndDate << tokens[i-1] << " ";
						} 
						bufferTimeAndDate <<tokens[i];
						if ((i+1 < tokens.size()) && (hasTime(tokens[i+1]))) {
							bufferTimeAndDate << " " << tokens[i+1];
							++i;
						}
					} else if (dateParser.parseDate(buffer) != boost::gregorian::date()) {
						bufferTimeAndDate << tokens[i];
						if ((i+1 < tokens.size()) && (hasTime(tokens[i+1]))) {
						bufferTimeAndDate << " " << tokens[i+1];
							++i;
						}
					} else if (dateParser.isMonth(tokens[i])) {
						std::string dateStr = tokens[i-1];
						if (dateStr.length() > 2) {
							dateStr.erase(dateStr.length() - 2);
						}
						int date = atoi(dateStr.c_str());
						if ((date >= 1) && (date <= 31)) {
							if (isStart) {
								description.pop_back();
							}
							bufferTimeAndDate << dateStr << " " << tokens[i];
							if ((i+1 < tokens.size()) && (atoi(tokens[i+1].c_str()) >= 1)){
								bufferTimeAndDate << " " << tokens[i+1];
							}
							if ((i+2 < tokens.size()) && (hasTime(tokens[i+2]))) {
								bufferTimeAndDate << " " << tokens[i+2];
								i = i + 2;
							} else {
								++i;
							}
						}
					} else if (hasTime(tokens[i])) {
						bufferTimeAndDate << tokens[i];
					}
			
					if (!(bufferTimeAndDate.str().empty())){
						if (isStart) {
							timeAndDate1 = bufferTimeAndDate.str();
							isStart = false;
							isDescription = false;
						} else {
							timeAndDate2 = bufferTimeAndDate.str();
							isDescription = false;
						}
					}
		
				if (isDescription){
					description.push_back(buffer);
				} 
		
			}
			std::cout << "PARSER: time 1 is \"" << timeAndDate1 << "\"" << std::endl;
			std::cout << "PARSER: time 2 is \"" << timeAndDate2 << "\"" << std::endl;

			_start = getDateAndTime(timeAndDate1);
			_end = getDateAndTime(timeAndDate2);
	
			determineType();
			std::cout << "PARSER:: type is \"" << _type << "\"" <<std::endl;

			if (_type == DEADLINE){
				_end = _start;
				_start = boost::posix_time::ptime();
			}

			std::cout << "PARSER: start time is \"" << _start << "\"" << std::endl;
			std::cout << "PARSER: end time is \"" << _end << "\"" << std::endl;

			if (!description.empty()){
				if (isConnectingWord(description.back())) {
					description.pop_back();
				}
			}

			std::string s;

			_description = vectorToString(description);
			std::cout << "PARSER: description is \"" << _description << "\"" << std::endl << std::endl;
		}
	}
	catch(std::string e) {
		std::cerr << e << std::endl;
	}
}
	

void CMParser::parseDataFromFile(std::string str){
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string buffer;
	std::string timeAndDate1; 
	std::string timeAndDate2;
	std::vector<std::string> description;
	
	bool isDescription = true;
	bool isStart = true;
	bool openInvertedCommas = false;

	boost::gregorian::date bufferDate;
	
	_start = boost::posix_time::ptime();
	_end = boost::posix_time::ptime();

	try{
		if (str.length() == 0 ) {
			_description = "";
			_type = "";

			throw std::string("ERROR: NOTHING TO PARSE");
		} else {
			std::cout << "PARSER: parsing from file \"" << str << "\"" << std::endl; 

			while (ss >> buffer){
				tokens.push_back(buffer);
			}

			for (unsigned int i = 0; i < tokens.size(); ++i) {
				buffer = tokens[i];
		
				if (buffer.find('"') != buffer.npos) {
					description.push_back(buffer);
			
					if (openInvertedCommas) {
						openInvertedCommas = false;	
					} else {
						openInvertedCommas = true;
					}
					if (buffer.find('"') != buffer.rfind('"')) {
						openInvertedCommas = false;
					}
					continue;
				}
		
				std::istringstream bufferTimeAndDate(buffer);
		
				bufferTimeAndDate >> bufferDate;
		
				if (buffer == "-") {
					++i;
					isDescription = false;
				} else if (bufferDate != boost::gregorian::date()){
					if (isStart) {
						timeAndDate1 = tokens[i] + " " + tokens[i+1];
						_start = boost::posix_time::time_from_string(timeAndDate1);
						isStart = false;
					} else {
						timeAndDate2 = tokens[i] + " " + tokens[i+1];
						_end = boost::posix_time::time_from_string(timeAndDate2);
					}
					isDescription = false;
					++i;
				} 
	
				if (isDescription){
					description.push_back(buffer);
				} 
			}

			determineType();
			std::cout << "PARSER:: type is \"" << _type << "\"" <<std::endl;


			if (_type == DEADLINE){
				_end = _start;
				_start = boost::posix_time::ptime();
			}

			std::cout << "PARSER: start time is \"" << _start << "\"" << std::endl;
			std::cout << "PARSER: end time is \"" << _end << "\"" << std::endl;

			_description = vectorToString(description);
			std::cout << "PARSER: description is \"" << _description << "\"" << std::endl << std::endl;
		}
	}
	catch(std::string e) {
		std::cerr << e << std::endl;
	}
}

std::string CMParser::vectorToString (std::vector<std::string> description){
	std::string s;

	for (std::vector<std::string>::const_iterator i = description.begin(); i != description.end(); ++i) {
		if (i == description.begin()){
			s += *i;
		} else {
			s += " ";
			s += *i;
		}
	}
	return s;
}

boost::posix_time::ptime CMParser::getDateAndTime(std::string str) {
	std::string timeStr;
	std::string dateStr;
	boost::posix_time::ptime dateAndTime;
	boost::gregorian::date bufferDate;
	int hours;
	int minutes;

	int lastSpace = str.find_last_of(" ");
	
	//change given string to lower case
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = tolower(str[i]);
	}
	
	if (hasTime(str) && hasDate(str)){
		timeStr = str.substr(lastSpace+1);
		dateStr = str.erase(lastSpace);
		
		timeParser.parseTime(timeStr);
		hours = timeParser.getHour();
		minutes = timeParser.getMin();
		
		bufferDate = dateParser.parseDate(dateStr);

		dateAndTime = boost::posix_time::ptime(bufferDate ,boost::posix_time::hours(hours) + boost::posix_time::minutes(minutes));
	}
	else if (hasDate(str)) {
		dateStr = str;
		
		timeParser.setHour(23);
		timeParser.setMin(59);

		hours = timeParser.getHour();
		minutes = timeParser.getMin();
		
		bufferDate = dateParser.parseDate(dateStr);

		dateAndTime = boost::posix_time::ptime(bufferDate ,boost::posix_time::hours(hours) + boost::posix_time::minutes(minutes));
	}
	else if (hasTime(str)) {
		timeStr = str;
		timeParser.parseTime(timeStr);

		hours = timeParser.getHour();
		minutes = timeParser.getMin();
		
		if (_start.date() == boost::gregorian::date())
			_start = boost::posix_time::second_clock::local_time();

		bufferDate = _start.date();
		dateAndTime = boost::posix_time::ptime(bufferDate ,boost::posix_time::hours(hours) + boost::posix_time::minutes(minutes));
		if (dateAndTime < boost::posix_time::second_clock::local_time() || dateAndTime < _start){
			dateAndTime += boost::gregorian::date_duration(1);	
		}
	} else { //if given string has no time or date attributes
		dateAndTime = boost::posix_time::ptime();
	} 
	
	std::cout << "PARSER: \"" << str << "\" is \"" << dateAndTime << "\"" << std::endl;

	return dateAndTime;
}
	
bool CMParser::hasTime(std::string str) {
	std::string buffer;
	std::string timeStr;
	
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = tolower(str[i]);
	}

	int pos = str.find_last_of(" ");
	if (pos != str.npos){
		str = str.substr(pos + 1);
	}

	//checking for am/pm format time
	for (int i = 1; i < 3; ++i) {
		if (str.length() > 2){
			//removing delimiters
			int pos = str.find_first_of(":");			
			if (pos != str.npos) {
				str.erase(pos, 1);
			}

			if ( std::all_of(str.begin(), str.end(), std::isdigit) ) {
				return true;
			} else {
				buffer = str.substr(str.length() - 2);
			
				if (buffer == TIME_ATTRIBUTE[i]) {
					timeStr = str.substr(0, str.length() - 2); 
						
					if ( std::all_of(timeStr.begin(), timeStr.end(), std::isdigit) ) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool CMParser::hasDate(std::string str) {
	if (dateParser.isWeekdayName(str)) {
		return true;
	}

	for (int i = 0; i < 8; ++i) {
		if (str.find(VALID_DATE[i]) != str.npos) {
			return true;
		}
	}

	return false;
}

bool CMParser::isConnectingWord(std::string str) {
	assert( str != "");

	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = tolower(str[i]);
	}
	for (int i = 0; i < 6; ++i) {
		if (str == connectingWords[i]) {
			return true;
		}
	}
	return false;
}

bool CMParser::isTdyOrTmr (std::string str) {
	assert( str != "");

	for (int i = 0; i < 5; ++i) {
		if (str == VALID_DATE[i]) {
			return true;
		}
	}
	return false;
}

std::string CMParser::getDescription() {
	return _description;
}

boost::posix_time::ptime CMParser::getStart() {
	return _start;
}

boost::posix_time::ptime CMParser::getEnd() {
	return _end;
}

std::string CMParser::getType() {
	return _type;
}

void CMParser::determineType(){
	if (_start == boost::posix_time::ptime()){
		_type = FLOAT;
	} else if (_end == boost::posix_time::ptime()) {
		_type = DEADLINE;
	} else {
		_type = TIMED;
	}
}

std::string CMParser::getToday() {
	boost::gregorian::date today = boost::gregorian::day_clock::local_day();
	std::ostringstream output;	

	output<<today;

	return output.str();
}

std::string CMParser::getTomorrow() {
	boost::gregorian::date tomorrow = boost::gregorian::day_clock::local_day() + boost::gregorian::date_duration(1);
	std::ostringstream output;

	output<<tomorrow;

	return output.str();
}

boost::posix_time::ptime CMParser::changeTime (boost::posix_time::ptime current, std::string newTime) {
	boost::gregorian::date currentDate = current.date();
	timeParser.parseTime(newTime);
	
	int hours = timeParser.getHour();
	int minutes = timeParser.getMin();

	return boost::posix_time::ptime(currentDate , boost::posix_time::hours(hours) + boost::posix_time::minutes(minutes));
}

boost::posix_time::ptime CMParser::changeDate (boost::posix_time::ptime current, std::string newDate) {
	int hours = current.time_of_day().hours();
	int minutes = current.time_of_day().minutes();

	return boost::posix_time::ptime(dateParser.parseDate(newDate), boost::posix_time::hours(hours) + boost::posix_time::minutes(minutes));
}

std::string CMParser::interpretDirectoryString (std::string directory){
	if (directory == ""){
		return directory;
	} else return directory + "\\";
}