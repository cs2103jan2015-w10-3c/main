#pragma once
#include <iostream>
#include "Task.h"

class FloatingTask : public Task
{
public:
	FloatingTask(string,string);
	~FloatingTask(void);

	virtual void editStartDate(string);
	virtual void editStartTime (string);
	virtual void editEndDate (string);
	virtual void editEndTime (string);

	virtual string getStartDate() const;
	virtual string getStartTime() const;
	virtual string getEndDate() const;
	virtual string getEndTime() const; 

	virtual bool isFound(string);
	virtual string getInfo();
	};

