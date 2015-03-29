#pragma once
#include "Task.h"
class Deadline : public Task
{	string _StartDate;
	string _StartTime;

public:
	Deadline(string,string,string,string);
	~Deadline(void);
	virtual void editStartDate(string);
	virtual void editStartTime (string);
	virtual void editEndDate (string);
	virtual void editEndTime (string);

	virtual string getStartDate() const;
	virtual string getStartTime() const;
	virtual string getEndDate() const;
	virtual string getEndTime() const; 
	
	virtual string getInfo();
	virtual bool isFound(string);
};

