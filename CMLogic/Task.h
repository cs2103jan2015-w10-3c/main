#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

#include "boost/date_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

//Abstract Base class
class Task{
protected:
	std :: string _Description;		//Describes what the task is about
	bool _Checked;			

public:
	Task(std :: string);
	~Task();
	//For all three tasks
	void editDescription(std :: string);
	
	
	std :: string getDescription() const;


	virtual void editStartDate(ptime)=0;
	virtual void editStartTime (ptime)=0;
	virtual void editEndDate (ptime)=0;
	virtual void editEndTime (ptime)=0;

	virtual ptime getStart() const=0;
	virtual ptime getEnd() const=0;
	//Different attributes to search
	virtual bool isFound(std::string)=0;
	virtual std :: string getInfo()=0;

	bool isChecked();
	void checkTask();
	virtual bool isFloat()=0;
};

#endif