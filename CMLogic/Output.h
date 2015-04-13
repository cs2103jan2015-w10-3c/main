//@author A0111448M
#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <vector>
#include "Task.h"

//Output is an object consolidating all important details
//for the GUI to display.
class Output{
	std::string _feedback;				//To acknowledge the commands of the user.
	std::vector <Task*> _taskList;		//The TaskList to display. (Can be completed or current Task)
	int _lastActionIndex;				//The index for the GUI to highlight so the User can easily identify his action
	int	_firstFloatIndex;				//The position for the GUI to know when to split the float task
	bool _listType;						//To indicate if User is accessing Active task or Archived

public:
	Output(void);
	Output(std::string, std::vector<Task*>,int,int,bool);

	void editFeedback(std::string);
	std::string getFeedback() const;
	std::vector <Task*> getDisplay() const;
	int getLastAction() const;
	int getFirstFloat() const;
	bool getListType() const;
};
#endif
