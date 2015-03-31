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
		LogicCommand _CommandExecutor; //To execute actions
		LogicRead _CommandReader;	//To interpret the user input
		bool _IsActive;  //Status of system
		Output* _Display;

public:
		CMLogic();
		void startUp();
		void ExecuteCommand(std :: string);
		Output* getDisplay();
};
#endif
