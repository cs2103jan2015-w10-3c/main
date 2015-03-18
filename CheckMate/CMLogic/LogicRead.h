#ifndef LOGICREAD_H
#define LOGICREAD_H
#include <iostream>
#include <string>
#include "Command.h"

const std::string ADDF		= "addf";
const std::string ADDT		= "addt";
const std::string ADDD		= "addd";
const std::string DEL	= "delete";
const std::string EDIT		="edit";
const std::string SEARCH		= "search";
const std::string TODAY		="today";
const std::string TOMMORROW  ="tommorrow";
const std::string UNDO		="undo";
const std::string HELP		="help";
const std::string EXIT		= "exit";

const int ADDFLOATTASK	 = 1;
const int ADDDEADLINE	 = 2;
const int ADDTIMEDTASK	 = 3;
const int INDEXSEARCH	 = 4;
const int INDEXEDIT		 = 5;
const int INDEXDELETE	 = 6;
const int INDEXTODAY	 = 7;
const int INDEXTOMMORROW = 8;
const int INDEXUNDO		 = 9;
const int INDEXHELP		 = 10;
const int INDEXEXIT		 = 11;
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