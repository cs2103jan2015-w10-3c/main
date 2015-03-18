#ifndef FLOATINGTASK_H
#define FLOATINGTASK_H
#pragma once
#include <iostream>
#include "Task.h"

class FloatingTask : public Task
{
public:
	FloatingTask(std::string,std::string);
	~FloatingTask(void);

	virtual void editStartDate(ptime);
	virtual void editStartTime (ptime);
	virtual void editEndDate (ptime);
	virtual void editEndTime (ptime);

	virtual ptime getStart() const;
	virtual ptime getEnd() const; 

	virtual bool isFound(std::string);
	virtual std::string getInfo();
	};
#endif
