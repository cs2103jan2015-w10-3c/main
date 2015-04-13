//@author A0111448M
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

//Serves as a reader to interpret a string input into an index of the Task selected,
//the type of category chosen( Description, start time, start date, end time, end date)
//and the new infomartion to update. It is assumed the user know the category keywords
class EditReader{ 

private:
	int _taskIndex;							//Index of selected task Displayed
	int _categoryIndex;						//Index of Description/Start/End
	std::string _newInput;					//New input to replace previous


public:
	EditReader(void);
	~EditReader(void);
	bool interpretCommand(std::string);		//Retruns false if line is Invalid
	int indexCategory(std::string);			//Indexes the category for switch case
	std::string lowerCase(std::string);		//Allows Logic to read upper and lowercase
	int getTaskIndex() const;
	int getSelectedCategory() const;
	std::string getNewInput() const;
};

#endif