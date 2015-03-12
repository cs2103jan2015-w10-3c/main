#include "CMParser.h"

using namespace std;

int main(){
	CMParser test;
	string tester;
	
	tester = "Meeting with david from 24/03/2015, 14:00 to 25/03/15, 16:00 cat work";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester, "timed")<<endl;
	cout <<"Start: "<<test.getStart(tester, "timed")<<endl;
	cout <<"End: "<<test.getEnd(tester)<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;
	
	tester = "Meeting with david from 24 Feb 2015, 14:00 to 25 March 15, 16:00";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester, "timed")<<endl;
	cout <<"Start: "<<test.getStart(tester, "timed")<<endl;
	cout <<"End: "<<test.getEnd(tester)<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Submit proposal by 24 Feb 2015, 14:00 cat work";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester, "deadline")<<endl;
	cout <<"Start: "<<test.getStart(tester, "deadline")<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Submit proposal by 15/03/15, 14:00";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester, "deadline")<<endl;
	cout <<"Start: "<<test.getStart(tester, "deadline")<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Sweep Floor cat housework";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester, "float")<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Sweep Floor";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester, "float")<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;
	
	system("pause");
	return 0;
}
