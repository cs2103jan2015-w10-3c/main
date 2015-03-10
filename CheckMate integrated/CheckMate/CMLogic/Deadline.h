#pragma once
#include "Task.h"
class Deadline : public Task
{	string _Startdate;
string _Starttime;

public:
	Deadline(string,string,string,string);
	~Deadline(void);
	void editStartDate(string);
	void editStartTime (string);

	string getStartdate() const;
	string getStartTime() const;
};

