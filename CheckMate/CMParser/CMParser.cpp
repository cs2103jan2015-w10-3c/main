#include "CMParser.h"
#include "CMDateParser.h"
#include "CMTimeParser.h"

std::string CMParser::getDescription(std::string str, std::string type) {
	int pos;
	
	if (type=="timed") {
		pos = str.rfind(" from ");
	}
	else if (type=="float") {
		pos = str.rfind(" cat ");
	}
	else if (type=="deadline") {
		pos = str.rfind(" by ");
	}

	_description = str.substr(0,pos);

	return _description;
}

std::string CMParser::getCategory (std::string str){
	std::string str1;

	if (str.find(" cat ")!=str.npos) {
		str1 = str.substr(str.find(" cat ")+5);
		str1 = str1.substr(str1.find(" ")+1);
	}

	else {
		str1 = "nil";
	}

	_category = str1;

	return _category;
}

ptime CMParser::getStart(std::string str, std::string type) {
	std::string str1;

	if (type == "timed") {
		str1 = str.substr(str.rfind(" from ")+6);
	}
	else {
		str1 = str.substr(str.rfind(" by ")+4);
	}

	int pos = str1.find(" to ");
	if (pos==str1.npos) {
	str1.find(" cat ");
	}
	if (pos!=str1.npos)
	str1.erase(pos);

	str1.substr(1);

	_start = getDateAndTime(str1);
	return _start;
}

ptime CMParser::getEnd(std::string str) {
	std::string str1;

	str1 = str.substr(str.rfind(" to ")+4);

	int pos = str1.find(" cat ");

	if (pos!=str1.npos)
	str1.erase(pos);

	_end = getDateAndTime(str1);
	std::cout <<_end.time_of_day()<<std::endl;
	time_duration td (16,0,0);
	time_facet *facet = new time_facet("%d-%b-%Y %H:%M");
	std::cout.imbue(std::locale(std::cout.getloc(), facet));

	return _end;
}

bool CMParser::hasTime(std::string str) {
	int pos;
	std::string timeAttributes[6] = {":", "am", "pm", "PM", "AM"};

	for (int i=0; i<6; ++i) {
		pos= str.find(timeAttributes[i]);
		if (pos!=str.npos)
			return true;
	}

	return false;
}

bool CMParser::hasDate(std::string str) {
	if (str.find_last_of(" /")==str.npos)
		return false;
	else
		return true;
}

ptime CMParser::getDateAndTime(std::string str) {

	int lastSpace = str.find_last_of(" ");
	std::string timeStr, dateStr;
	CMDateParser dateParser;
	CMTimeParser timeParser;
	date d;

	if (hasTime(str) && hasDate(str)){
		timeStr = str.substr(lastSpace+1);
		dateStr = str.erase(lastSpace);
		timeParser.parseTime(timeStr);
		d = dateParser.getDate(dateStr);
	}
	else if (hasDate(str)) {
		dateStr = str;
		timeParser.setHour(23);
		timeParser.setMin(59);
		d = dateParser.getDate(dateStr);
	}
	else if (hasTime(str)) {
		timeStr = str;
		timeParser.parseTime(timeStr);
		d = _start.date();
	}
	
	return ptime(d ,hours(timeParser.getHour())+minutes(timeParser.getMin()));
}


/*ptime CMParser::getDateAndTime(string str) {
	locale format[16] = {
		locale(locale::classic(), new time_input_facet("%d/%m/%Y, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d/%m/%y, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d %B %Y, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d %B %y, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d %b %Y, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d %b %y, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d %B, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d %b, %H:%M")),
		locale(locale::classic(), new time_input_facet("%d/%m/%Y")),
		locale(locale::classic(), new time_input_facet("%d/%m/%y")),
		locale(locale::classic(), new time_input_facet("%d %B %Y")),
		locale(locale::classic(), new time_input_facet("%d %B %y")),
		locale(locale::classic(), new time_input_facet("%d %b %Y")),
		locale(locale::classic(), new time_input_facet("%d %b %y")),
		locale(locale::classic(), new time_input_facet("%d %B")),
		locale(locale::classic(), new time_input_facet("%d %b"))
		};

	ptime pt;
	
	for (int i=0; i<16; ++i)
	{
		istringstream ss(str);
		ss.imbue(format[i]);
		ss>>pt;
		if (pt!=ptime())
			break;
	}
	return pt;
}*/