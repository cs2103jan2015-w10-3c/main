#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <vector>
#include "Task.h"

class Output{
<<<<<<< HEAD
	std::string _Feedback;
	std::vector <Task*> _TaskList;
	int _LastAction;
public:
	Output(void);
	Output(std :: string, std :: vector<Task*>,int);
	std::string getFeedback() const;
	std::vector <Task*> getDisplay() const;
	int getLastAction() const;
=======
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
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
};
#endif
