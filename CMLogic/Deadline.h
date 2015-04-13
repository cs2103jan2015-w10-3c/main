//@author A0111448M
#ifndef DEADLINE_H
#define DEADLINE_H

#include "Task.h"

//Deadline is a task which contains only the
//description for the user to relate and the date 
//which the deadline needs to be done. Both description
//and deadline will be shown to the user on the UI.
//Deadline is a subclass of Task.
class Deadline : public Task{ 
private:
	boost::posix_time::ptime _end;												// The deadline date and time

public:

	Deadline(std::string,boost::posix_time::ptime);
	~Deadline(void);
	virtual void editStartDate(boost::posix_time::ptime);
	virtual void editStartTime (boost::posix_time::ptime);
	virtual void editEndDate (boost::posix_time::ptime);
	virtual void editEndTime (boost::posix_time::ptime);

	virtual boost::posix_time::ptime getStart() const;
	virtual boost::posix_time::ptime getEnd() const;

	virtual bool hasClash(boost::posix_time::ptime,boost::posix_time::ptime);	//Deadlines do not have clashes
	virtual std::string getInfo();
	virtual bool isFound(std::string);
	virtual bool isEditedTask(std::string, boost::posix_time::ptime, boost::posix_time::ptime);
	virtual bool isFloat();	
	virtual bool isTimed();
	virtual bool isDeadline();
};
#endif
