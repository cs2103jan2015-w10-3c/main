//@author A0111448M
#ifndef CMLOGIC_H
#define CMLOGIC_H

#include <iostream>
#include <vector>

#include "LogicCommand.h"
#include "LogicRead.h"
#include "Command.h"
#include "Output.h"

//Serves as the API to the GUI.  All inputs will first
//Enter the CMLogic who relies on the LogicRead to interpret 
//the command and LogicCommand to excute it. The GUI should only
//be able to access the feedback and Tasklist 
class CMLogic{
private:
	LogicCommand _commandExecutor;		//To execute actions
	LogicRead _commandReader;			//To interpret the user input
	bool _isActive;						//Status of system
	Output* _display;					// Display for GUI

public:
	CMLogic();
	void startUp();						//Retrieve Task from the saved text files
	void executeCommand(std::string);	//Exceutes the commands of the User
	Output* getDisplay();				//For GUI to retrieve the display.
};
#endif
