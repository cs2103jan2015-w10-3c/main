#include "CMParser.h"

string CMParser::getDescription(string str) {
	return str.substr(0,str.rfind("from"));
}

string CMParser::getStartDate(string str, string type) {
	string str1;
	
	local_time_input_facet* input_facet = new local_time_input_facet();
	local_time_facet* output_facet = new local_time_facet();
	stringstream ss;
	
	string inFormat = "%d/%m/%y";
	string outFormat = "%d/%m/%y";
	
	ss.imbue(locale(locale::classic(), output_facet));
	ss.imbue(locale(ss.getloc(), input_facet));
	
	input_facet->format(inFormat.c_str());
	output_facet->format(outFormat.c_str());
	
	local_date_time ldt(not_a_date_time);
	
	if (type == "timed") {
		str1 = str.substr(str.rfind("from")+5);
	}
	else {
		str1 = str.substr(str.rfind("by")+3);
	}

	str1.erase(str1.find(" "));
	ss.str(str1);
	ss>>ldt;

	ss.str("");
	ss<<ldt;
	
	return ss.str();
}

string CMParser::getStartTime(string str, string type) {
	string str1; 
		
	local_time_input_facet* input_facet = new local_time_input_facet();
	local_time_facet* output_facet = new local_time_facet();
	stringstream ss;
	
	string inFormat = "%H:%M";
	string outFormat = "%I:%M %p";
	
	ss.imbue(locale(locale::classic(), output_facet));
	ss.imbue(locale(ss.getloc(), input_facet));
	
	input_facet->format(inFormat.c_str());
	output_facet->format(outFormat.c_str());
	
	local_date_time ldt(not_a_date_time);

	if (type == "timed") {
		str1 = str.substr(str.rfind("from")+5);
	}
	else {
		str1 = str.substr(str.rfind("by")+3);
	}

	str1 = str1.substr(str1.find(" ")+1);
	
	if (str1.find(" ")!=str1.npos){
		str1.erase(str1.find(" "));
	}

	ss.str(str1);
	ss>>ldt;

	ss.str("");
	ss<<ldt;
	
	return ss.str();
}

string CMParser::getEndDate(string str) {
	string str1;
	str1 = str.substr(str.rfind("to")+3);
	str1.erase(str1.find(" "));

	local_time_input_facet* input_facet = new local_time_input_facet();
	local_time_facet* output_facet = new local_time_facet();
	stringstream ss;
	
	string inFormat = "%d/%m/%y";
	string outFormat = "%d/%m/%y";
	
	ss.imbue(locale(locale::classic(), output_facet));
	ss.imbue(locale(ss.getloc(), input_facet));
	
	input_facet->format(inFormat.c_str());
	output_facet->format(outFormat.c_str());
	
	local_date_time ldt(not_a_date_time);

	ss.str(str1);
	ss>>ldt;

	ss.str("");
	ss<<ldt;
	
	return ss.str();
}

string CMParser::getEndTime(string str) {
	string str1 = str.substr(str.rfind("to")+3);
	str1 = str1.substr(str1.find(" ")+1);
	
	if (str1.find(" ")!=str1.npos){
	str1.erase(str1.find(" "));
	}
	
	local_time_input_facet* input_facet = new local_time_input_facet();
	local_time_facet* output_facet = new local_time_facet();
	stringstream ss;
	
	string inFormat = "%H:%M";
	string outFormat = "%R";
	
	ss.imbue(locale(locale::classic(), output_facet));
	ss.imbue(locale(ss.getloc(), input_facet));
	
	input_facet->format(inFormat.c_str());
	output_facet->format(outFormat.c_str());
	
	local_date_time ldt(not_a_date_time);

	ss.str(str1);
	ss>>ldt;

	ss.str("");
	ss<<ldt;
	
	return ss.str();
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
