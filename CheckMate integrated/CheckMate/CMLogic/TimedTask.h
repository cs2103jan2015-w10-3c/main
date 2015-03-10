#pragma once
#include "Task.h"

class TimedTask : public Task
{
	string _Startdate;
	string _Starttime;
	string _Enddate;
	string _Endtime;


public:
	TimedTask(string,string,string,string,string,string);
	~TimedTask(void);
	void editStartDate(string);
	void editStartTime (string);
	void editEndTime (string);
	void editEndTime (string);

	string getStartdate() const;
	string getStartTime() const;
	string getEndDate() const;
	string getEndTime() const; 
};

