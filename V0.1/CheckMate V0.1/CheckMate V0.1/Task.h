#pragma once
#include <iostream>
#include <string>

using namespace std;
//Abstract Base class
class Task
{
protected:
	string _Description;		//Describes what the task is about
	string _Category;			//Categorises task as personal/school/work

public:
	Task(string,string);
	~Task();
	//For all three tasks
	void editDescription(string);
	void editCategory(string);
	
	string getDescription() const;
	string getCategory() const;

	virtual void editStartDate(string)=0;
	virtual void editStartTime (string)=0;
	virtual void editEndDate (string)=0;
	virtual void editEndTime (string)=0;

	virtual string getStartDate() const=0;
	virtual string getStartTime() const=0;
	virtual string getEndDate() const=0;
	virtual string getEndTime() const=0; 
	//Different attributes to search
	virtual bool isFound(string)=0;
	virtual string getInfo()=0;
	
};

