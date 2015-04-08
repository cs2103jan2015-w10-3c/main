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
<<<<<<< HEAD
		LogicCommand _CommandExecutor; //To execute actions
		LogicRead _CommandReader;	//To interpret the user input
		bool _IsActive;  //Status of system
		Output* _Display;
=======
		LogicCommand _commandExecutor;	//To execute actions
		LogicRead _commandReader;		//To interpret the user input
		bool _isActive;					//Status of system
		Output* _display;				// Display for GUI
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

public:
		CMLogic();
		void startUp();
<<<<<<< HEAD
		void ExecuteCommand(std :: string);
=======
		void executeCommand(std::string);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
		Output* getDisplay();
};
#endif
