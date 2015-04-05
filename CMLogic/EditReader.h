#ifndef EDITREADER_H
#define EDITREADER_H
#include<iostream>
#include<string>

const std::string DESCRIPTION="desc";
const std::string STARTTIME = "stime";
const std::string ENDTIME = "etime";
const std::string STARTDATE = "sdate";
const std::string ENDDATE = "edate";

const int DESCRIPTIONINDEX= 1;
const int STARTTIMEINDEX= 2;
const int ENDTIMEINDEX= 3;
const int STARTDATEINDEX= 4;
const int ENDDATEINDEX= 5;
const int INVALIDINDEX=20;

class EditReader{ 

private:
	int _TaskIndex;
	int _CategoryIndex;
	std::string _NewInput;


public:
	EditReader(void);
	~EditReader(void);
	void interpretCommand(std::string);
	int indexCategory(std::string);
	std::string lowerCase(std::string);
	int getTaskindex() const;
	int getSelectedCategory() const;
	std::string getNewInput() const;
};

#endif