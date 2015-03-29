#ifndef EDITREADER_H
#define EDITREADER_H
#include<iostream>
#include<string>

const std::string DESCRIPTION="desc";
const std::string CATEGORY = "cat";
const std::string STARTTIME = "stime";
const std::string ENDTIME = "etime";
const std::string STARTDATE = "sdate";
const std::string ENDDATE = "edate";

const int DESCRIPTIONINDEX= 1;
const int CATEGORYINDEX= 2;
const int STARTTIMEINDEX= 3;
const int ENDTIMEINDEX= 4;
const int STARTDATEINDEX= 5;
const int ENDDATEINDEX= 6;
const int INVALIDINDEX=20;

class EditReader{ 

private:
	int _TaskIndex;
	int _Categoryindex;
	std::string _NewInput;


public:
	EditReader(void);
	~EditReader(void);
	void interpretCommand(std::string);
	int indexCategory(std::string);
	int getTaskindex() const;
	int getSelectedCategory() const;
	std::string getNewInput() const;
};

#endif