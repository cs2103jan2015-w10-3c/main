#ifndef DEADLINE_H
#define DEADLINE_H

#include "Task.h"

class Deadline : public Task
{ 
	ptime _Start;

public:

	Deadline(std::string,ptime);
	~Deadline(void);
	virtual void editStartDate(ptime);
	virtual void editStartTime (ptime);
	virtual void editEndDate (ptime);
	virtual void editEndTime (ptime);

	virtual ptime getStart() const;
	virtual ptime getEnd() const;

	
	virtual std::string getInfo();
	virtual bool isFound(std::string);
	
};
#endif
