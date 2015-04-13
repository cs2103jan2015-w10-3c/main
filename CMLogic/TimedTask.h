//@author A0111448M
#ifndef TIMEDTASK_H
#define TIMEDTASK_H
#include "Task.h"

//Timed Task is a task which contains the
//description, a start time/date and an end time/date for the user to 
//plan his eventse. All information will be shown to the user on the UI.
//Deadline is a subclass of Task.
class TimedTask : public Task{
private:
	boost::posix_time::ptime _start;
	boost::posix_time::ptime _end;

public:
	TimedTask(std::string,boost::posix_time::ptime,boost::posix_time::ptime);
	~TimedTask(void);

	virtual void editStartDate(boost::posix_time::ptime);
	virtual void editStartTime (boost::posix_time::ptime);
	virtual void editEndDate (boost::posix_time::ptime);
	virtual void editEndTime (boost::posix_time::ptime);

	virtual boost::posix_time::ptime getStart() const;
	virtual boost::posix_time::ptime getEnd() const;

	virtual bool hasClash(boost::posix_time::ptime,boost::posix_time::ptime);
	virtual std::string getInfo();
	virtual bool isFound (std::string);
	virtual bool isEditedTask(std::string, boost::posix_time::ptime, boost::posix_time::ptime);
	virtual bool isFloat();
	virtual bool isTimed();
	virtual bool isDeadline();
};

#endif