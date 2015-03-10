#include "CMParser.h"

string CMParser::getDescription(string str, string type) {
	int pos;
	if (type=="timed") {
		pos = str.rfind("from");
	}
	else if (type=="float") {
		pos = str.rfind("cat");
	}
	else if (type=="deadline") {
		pos = str.rfind("by");
	}

	return str.substr(0,pos);
}

string CMParser::getCategory (string str){
	string str1;

	if (str.find("cat")!=str.npos) {
		str1 = str.substr(str.find("cat")+1);
		str1 = str1.substr(str1.find(" "));
	}

	else
		str1 = "nil";

	return str1;
}

ptime CMParser::getStart(string str, string type) {
	string str1;

	if (type == "timed") {
		str1 = str.substr(str.rfind("from")+5);
	}
	else {
		str1 = str.substr(str.rfind("by")+3);
	}

	int pos = str1.find("to");
	if (pos==str1.npos) {
	str1.find("cat");
	}
	if (pos!=str1.npos)
	str1.erase(pos);

	return getDateAndTime(str1);
}

ptime CMParser::getEnd(string str) {
	string str1;

	str1 = str.substr(str.rfind("to")+3);

	int pos = str1.find("cat");

	if (pos!=str1.npos)
	str1.erase(pos);

	return getDateAndTime(str1);
}

ptime CMParser::getDateAndTime(string str) {
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
}