#ifndef LOGICREAD_H
#define LOGICREAD_H
#include <iostream>
#include <string>
#include "Command.h"

const std::string ADD		= "add";
const std::string DEL	= "delete";
const std::string EDIT		="edit";
const std::string SEARCH		= "search";
const std::string TODAY		="today";
const std::string TOMMORROW  ="tommorrow";
const std::string UNDO		="undo";
const std::string HELP		="help";
const std::string EXIT		= "exit";

const int INDEXADD = 1;
const int INDEXSEARCH	 = 2;
const int INDEXEDIT		 = 3;
const int INDEXDELETE	 = 4;
const int INDEXTODAY	 = 5;
const int INDEXTOMMORROW = 6;
const int INDEXUNDO		 = 7;
const int INDEXHELP		 = 8;
const int INDEXEXIT		 = 9;
const int INVALIDCOMMAND = 20;

//Intepret the input into an index and  and return a Command Object
class LogicRead{

public:
	LogicRead(void);
	~LogicRead(void);
	int indexCommand(std::string);				//Gives the Command an index for switch case
	Command* interpretCommand(std::string);		//Creates a Command object when an input is given.
};

#endif