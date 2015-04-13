//@author A0111448M
#ifndef LOGICREAD_H
#define LOGICREAD_H

#include <iostream>
#include <string>
#include "Command.h"
//Expeceted commands which LogicRead will interpret.
const std::string ADD		= "add";
const std::string SEARCH	= "search";
const std::string EDIT		= "edit";
const std::string DEL		= "delete";
const std::string TODAY		= "today";
const std::string TOMORROW = "tomorrow";
const std::string UNDO		= "undo";
const std::string EXIT		= "exit";
const std::string CHECK		= "check";
const std::string REDO		= "redo";
const std::string CLEAR		= "clear";
const std::string COMPLETED = "completed";
const std::string UNCHECK	= "uncheck";
const std::string CHANGESTORE = "changestore";
const std::string HOME			= "home";


const int INDEXADD		 = 1;
const int INDEXSEARCH	 = 2;
const int INDEXEDIT		 = 3;
const int INDEXDELETE	 = 4;
const int INDEXTODAY	 = 5;
const int INDEXTOMORROW = 6;
const int INDEXUNDO		 = 7;
const int INDEXEXIT		 = 9;
const int INDEXCHECKTASK = 10;
const int INDEXCLEAR	 = 12;
const int INDEXCOMPLETED =13;
const int INDEXUNCHECK	 =14;
const int INDEXCHANGESTORE =15;
const int INDEXHOME		 =16;
const int INVALIDCOMMAND = 20;


//LogicRead inteprets the input into an index and a description.
//Helps CMLogic to determine the primary command of the user 
//and stores the remaining details into a string for LogicCommand to execute
class LogicRead{

public:
	int indexCommand(std::string);				//Indexes the command for a switch case
	Command* interpretCommand(std::string);		//Creates a Command object with the input string
	std::string lowerCase(std::string);			//Converts all command input into lower cases
};

#endif