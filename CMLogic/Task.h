//@author A0111448M
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

#include "boost/date_time.hpp"

const bool NOCLASH = false;
const bool CLASH = true;

//Abstract Base class of Floating Task/Deadlines/Timed Task.
//A task can be created, retrieved of information,deleted, edited
//checked for completion, checked for clash, checked for type.
class Task{
protected:
	std :: string _description;		//Describes what the task is about			

public:
	Task(std :: string);
	~Task();
	//For all three tasks
	void editDescription(std :: string);


	std :: string getDescription() const;


	virtual void editStartDate(boost::posix_time::ptime)=0;
	virtual void editStartTime (boost::posix_time::ptime)=0;
	virtual void editEndDate (boost::posix_time::ptime)=0;
	virtual void editEndTime (boost::posix_time::ptime)=0;

	virtual boost::posix_time::ptime getStart() const=0;
	virtual boost::posix_time::ptime getEnd() const=0;
	//Different attributes to search
	virtual bool isFound(std::string)=0;															//Returns true when string is found in any category
	virtual std :: string getInfo()=0;																//Returns a string of the comppiled details
	virtual bool hasClash(boost::posix_time::ptime,boost::posix_time::ptime)=0;						//Checks if the task clashes within a timeframe

	virtual bool isEditedTask(std::string, boost::posix_time::ptime, boost::posix_time::ptime)=0;	//To identify if task was the recently edited task)
	virtual bool isFloat()=0;
	virtual bool isTimed()=0;
	virtual bool isDeadline()=0;
};

#endif