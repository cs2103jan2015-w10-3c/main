#ifndef TIMEDTASK_H
#define TIMEDTASK_H
#include "Task.h"

class TimedTask : public Task{

	ptime _Start;
	ptime _End;


public:
	TimedTask(std::string,std::string,ptime,ptime);
	~TimedTask(void);

	virtual void editStartDate(ptime);
	virtual void editStartTime (ptime);
	virtual void editEndDate (ptime);
	virtual void editEndTime (ptime);

	virtual ptime getStart() const;
	virtual ptime getEnd() const;
	
	virtual std::string getInfo();
	virtual bool isFound (std::string);
};

#endif