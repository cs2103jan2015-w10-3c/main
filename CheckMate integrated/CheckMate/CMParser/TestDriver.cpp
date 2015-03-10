#include "CMParser.h"

using namespace std;

int main(){
	CMParser test;
	string tester;
	
	tester = "Meeting with david from 24/03/15 14:00 to 25/03/15 16:00 cat work";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester)<<endl;
	cout <<"Start Date: "<<test.getStartDate(tester, "timed")<<endl;
	cout <<"Start Time: "<<test.getStartTime(tester, "timed")<<endl;
	cout <<"End Date: "<<test.getEndDate(tester)<<endl;
	cout <<"End Time: "<<test.getEndTime(tester)<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Meeting with david from 24/03/15 14:00 to 25/03/15 16:00";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester)<<endl;
	cout <<"Start Date: "<<test.getStartDate(tester, "timed")<<endl;
	cout <<"Start Time: "<<test.getStartTime(tester, "timed")<<endl;
	cout <<"End Date: "<<test.getEndDate(tester)<<endl;
	cout <<"End Time: "<<test.getEndTime(tester)<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Submit proposal by 15/03/15 14:00 cat work";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester)<<endl;
	cout <<"Start Date: "<<test.getStartDate(tester, "")<<endl;
	cout <<"Start Time: "<<test.getStartTime(tester, "")<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Submit proposal by 15/03/15 14:00";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester)<<endl;
	cout <<"Start Date: "<<test.getStartDate(tester, "")<<endl;
	cout <<"Start Time: "<<test.getStartTime(tester, "")<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Sweep Floor cat housework";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester)<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	tester = "Sweep Floor";
	cout << tester<<endl;
	cout <<"Description: "<< test.getDescription(tester)<<endl;
	cout <<"Category: "<< test.getCategory(tester)<<endl<<endl;

	system("pause");
	return 0;
}
