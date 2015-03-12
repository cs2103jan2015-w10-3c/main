#pragma once
#include "Task.h"

class TimedTask : public Task
{
	string _StartDate;
	string _StartTime;
	string _EndDate;
	string _EndTime;


public:
	TimedTask(string,string,string,string,string,string);
	~TimedTask(void);
	virtual void editStartDate(string);
	virtual void editStartTime (string);
	virtual void editEndDate (string);
	virtual void editEndTime (string);

	virtual string getStartDate() const;
	virtual string getStartTime() const;
	virtual string getEndDate() const;
	virtual string getEndTime() const; 

	virtual string getInfo();
	virtual bool isFound (string);
};

