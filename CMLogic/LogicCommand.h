#ifndef LOGICCOMMAND_H
#define LOGICCOMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include "CMParser.h"

#include "CMDateParser.h"
#include "CMTimeParser.h"

#include "CheckMateStorage.h"
#include "Output.h"
#include "Task.h"
#include "FloatingTask.h"
#include "Deadline.h"
#include "TimedTask.h"
#include "EditReader.h"
#include "boost/date_time.hpp"
#include "IntToStringConvertor.h"

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

const std::string INVALID_INPUT		= "Invalid command given!";
const std::string FLOATINGTYPE		= "float";
const std::string TIMEDTYPE			= "timed";
const std::string DEADLINE			= "deadline";
const std::string ADDED				= "was added!";
const std::string DELETED			= "was deleted!";
const std::string EDITED			= "Edit Done!";
const std::string SEARCHFOUND		= "The search has found ";
const std::string TASKS				= "tasks.";
const std::string INVALIDTASKTYPE	= "Invalid Task Type Chosen!";
const std::string INVALIDTYPE		= "Invalid Category Chosen!";
const std::string UNDID				= "Action was undone!";
const std::string REDID				= "Undo was redone!";
const std::string GOODBYE			= "Goodbye! ";
const std::string WELCOMEBACK		= "Welcome Back ";
const std::string USERNAME			= "Master";
const std::string NEWDIRECTORY		= "Directory Changed to ";
const std::string CHECKED			= "It has been checked";
const std::string CLEARED			= "All Task have been cleared!";
const std::string SAVED				= "Files have been saved";

const int NOINDEX					= -1;
const int FROMFILE					= 1;
const int FROMUSER					= 2;

class LogicCommand{
	CMParser _Parser;			//To interpret description
	CMStorage _Storage;			//To store Task into files
	EditReader Editor;			//To edit Task in files
	IntToStringConvertor _IntConvertor;		
	std::vector <std::string> _toDisplay;

public:
	Output* retrieveData();

	Output* addTask (std::string,int);
	Output* addFloatTask();
	Output* addTimeTask();
	Output* addDeadlines();
	Output* searchTask (std::string);
	Output* editTask(std::string);
	Output* deleteTask(std::string);
	Output* displayToday();
	Output* displayTomorrow();
	Output* undoAction();
	Output* redoAction();
	Output* clearTask();
	Output* checkTask(std::string);


	Output* changeStorageDirectory(std::string);
};

#endif