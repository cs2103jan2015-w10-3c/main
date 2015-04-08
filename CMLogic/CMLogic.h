#ifndef CMLOGIC_H
#define CMLOGIC_H

#include <vector>
#include <iostream>

#include "LogicCommand.h"
#include "LogicRead.h"
#include "Command.h"
#include "Output.h"




class CMLogic
{	private:
		LogicCommand _commandExecutor;	//To execute actions
		LogicRead _commandReader;		//To interpret the user input
		bool _isActive;					//Status of system
		Output* _display;				// Display for GUI

public:
		CMLogic();
		void startUp();
		void executeCommand(std::string);
		Output* getDisplay();
};
#endif
