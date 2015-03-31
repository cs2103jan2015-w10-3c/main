#ifndef FLOATINGTASK_H
#define FLOATINGTASK_H

#include <iostream>
#include "Task.h"

class FloatingTask : public Task
{
public:
	FloatingTask(std::string);
	~FloatingTask(void);

	virtual void editStartDate(ptime);
	virtual void editStartTime (ptime);
	virtual void editEndDate (ptime);
	virtual void editEndTime (ptime);

	virtual ptime getStart() const;
	virtual ptime getEnd() const; 

	virtual bool isFound(std::string);
	virtual std::string getInfo();
	virtual bool IsChecked() const;
	};
#endif
