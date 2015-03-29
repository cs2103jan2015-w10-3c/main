#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <vector>
#include "Task.h"

class Output{
	std::string _Feedback;
	std::vector <Task*> _TaskList;
public:
	Output(void);
	Output(std :: string, std :: vector<Task*>);
	std::string getFeedback() const;
	std::vector <Task*> getDisplay() const;
};
#endif
