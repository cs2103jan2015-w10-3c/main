#ifndef LOGICREAD_H
#define LOGICREAD_H
#include <iostream>
#include <string>
#include "Command.h"

const std::string ADD		= "add";
const std::string SEARCH	= "search";
const std::string EDIT		= "edit";
const std::string DEL		= "delete";
const std::string TODAY		= "today";
const std::string TOMMORROW = "tommorrow";
const std::string UNDO		= "undo";
const std::string EXIT		= "exit";
const std::string CHECK		= "check";
const std::string START		= "start";
const std::string REDO		= "redo";
const std::string CLEAR		= "clear";

const int INDEXADD		 = 1;
const int INDEXSEARCH	 = 2;
const int INDEXEDIT		 = 3;
const int INDEXDELETE	 = 4;
const int INDEXTODAY	 = 5;
const int INDEXTOMMORROW = 6;
const int INDEXUNDO		 = 7;
const int INDEXEXIT		 = 9;
const int INDEXCHECKTASK = 10;
const int INDEXSTART	 = 11;
const int INDEXREDO		 = 12;
const int INDEXCLEAR	 = 13;
const int INVALIDCOMMAND = 20;

//Intepret the input into an index and a description
class LogicRead{

public:
	int indexCommand(std::string);				//Indexes the command for a switch case
	Command* interpretCommand(std::string);		// Converts all command input into lower cases
	std::string lowerCase(std::string);			//Creates a Command object with the input string
};

#endif