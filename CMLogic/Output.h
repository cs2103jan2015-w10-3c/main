#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <vector>
#include "Task.h"

class Output{
	std::string _feedback;
	std::vector <Task*> _taskList;
	int _lastActionIndex;
	int	_firstFloatIndex;
public:
	Output(void);
	Output(std::string, std::vector<Task*>,int,int);

	void editFeedback(std::string);
	std::string getFeedback() const;
	std::vector <Task*> getDisplay() const;
	int getLastAction() const;
	int getFirstFloat() const;
};
#endif
