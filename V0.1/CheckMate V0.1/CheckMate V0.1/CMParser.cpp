#include "CMParser.h"

string CMParser::getDescription(string str) {
	return str;
}

string CMParser::getStartDate(string str) {
	return str;
}

string CMParser::getStartTime(string str) {
	return str;
}

string CMParser::getEndDate(string str) {
	return str;
}

string CMParser::getEndTime(string str) {
	return str;
}

string CMParser::getCategory (string str){
	return str;
}

int main(){
	CMParser test;
	string tester;
	test.getCategory(tester);

	boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
	cout << now.time_of_day() << endl;

	string str;
	cin >> str;
	cout << str;

	return 0;
}
