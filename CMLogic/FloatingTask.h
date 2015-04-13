//@author A0111448M
#ifndef FLOATINGTASK_H
#define FLOATINGTASK_H

#include <iostream>
#include "Task.h"

//FloatingTask is a task which contains only the
//description for the user to relate. This Description
//will be shown to the user on the UI serperate from the other type of Task
//and he will be able to search, delete and edit a FloatingTask
//Floating Task is a subclass of Task.
class FloatingTask : public Task
{
public:
	FloatingTask(std::string);
	~FloatingTask(void);

	virtual void editStartDate(boost::posix_time::ptime);
	virtual void editStartTime (boost::posix_time::ptime);
	virtual void editEndDate (boost::posix_time::ptime);
	virtual void editEndTime (boost::posix_time::ptime);

	virtual boost::posix_time::ptime getStart() const;
	virtual boost::posix_time::ptime getEnd() const; 

	virtual bool hasClash(boost::posix_time::ptime,boost::posix_time::ptime);
	virtual bool isFound(std::string);
	virtual std::string getInfo();
	virtual bool isEditedTask(std::string, boost::posix_time::ptime, boost::posix_time::ptime);
	virtual bool isFloat();	
	virtual bool isTimed();
	virtual bool isDeadline();
};
#endif
