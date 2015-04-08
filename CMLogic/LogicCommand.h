#ifndef LOGICCOMMAND_H
#define LOGICCOMMAND_H

#include <iostream>
#include <string>
#include <vector>
<<<<<<< HEAD
=======
#include <sstream>
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
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
<<<<<<< HEAD
#include "IntToStringConvertor.h"
=======
#include "StringConvertor.h"
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

const std::string INVALID_INPUT		= "Invalid command given!";
const std::string FLOATINGTYPE		= "float";
const std::string TIMEDTYPE			= "timed";
const std::string DEADLINE			= "deadline";
<<<<<<< HEAD
const std::string ADDED				= "was added!";
const std::string DELETED			= "was deleted!";
const std::string EDITED			= "Edit Done!";
const std::string SEARCHFOUND		= "The search has found ";
const std::string TASKS				= "tasks.";
const std::string INVALIDTASKTYPE	=  "Invalid Task Type Chosen!";
=======
const std::string ADDED				= " was added!";
const std::string DELETED			= " was deleted!";
const std::string EDITED			= "Edit Done!";
const std::string SEARCHFOUND		= "Found";
const std::string TASKS				= " tasks.";
const std::string INVALIDTASKTYPE	= "Invalid Task Type Chosen!";
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
const std::string INVALIDTYPE		= "Invalid Category Chosen!";
const std::string UNDID				= "Action was undone!";
const std::string REDID				= "Undo was redone!";
const std::string GOODBYE			= "Goodbye! ";
<<<<<<< HEAD
const std::string WELCOMEBACK		= "Welcome Back ";
const std::string USERNAME			= "Master";
const std::string NEWDIRECTORY		= "Directory Changed to ";
const std::string CHECKED			= "It has been checked";

const int NOINDEX					= -1;

class LogicCommand{
	CMParser _Parser;
	CMStorage _Storage;
	EditReader Editor;
	IntToStringConvertor _IntConvertor;
	
	// CMTextFile _TextFile;
	std::vector <std::string> _toDisplay;

public:
	Output* retrieveData();
	Output* addTask (std::string);
	Output* addFloatTask();
	Output* addTimeTask();
	Output* addDeadlines();
	Output* deleteTask(std::string);
	Output* searchTask (std::string);
	Output* EditTask(std::string);
	Output* DisplayToday();
	Output* DisplayTomorrow();
	Output* UndoAction();
	Output* RedoAction();
	Output* CheckTask(std::string);
=======
const std::string WELCOMEBACK		= "Welcome Back!";
const std::string NEWDIRECTORY		= "Directory Changed to ";
const std::string CHECKED			= "It has been checked";
const std::string CLEARED			= "All Task have been cleared!";
const std::string SAVED				= "Files have been saved";
const std::string ARCHIVED			= "These are the Completed Task.";

const int NOINDEX					= -1;
const int FROMFILE					= 1;
const int FROMUSER					= 2;
const int NONOBSERVABLE				=-1;
const int NONE						=0;

const bool UNCOMPLETEDTASK			= false;
const bool COMPLETEDTASK			= true;

class LogicCommand{
	CMParser _Parser;			//To interpret description
	CMStorage _Storage;			//To store Task into files
	EditReader Editor;			//To edit Task in files
	StringConvertor _stringConvertor;	

	std::vector <std::string> _toDisplay;		//Display of Task
	int _lastActionIndex;						//Index for Last User Action
	int _firstFloatIndex;						//Index for GUI to know first floattask position


public:
	Output* retrieveData();			//Obtains data from TextFiles
	Output* addTask (std::string,int,bool);			//Adds a task
	Output* addFloatTask(bool);						//Add a Floating task
	Output* addTimeTask(bool);
	Output* addDeadlines(bool);
	Output* searchTask (std::string);
	Output* editTask(std::string);
	Output* deleteTask(std::string);
	Output* displayToday();
	Output* displayTomorrow();
	Output* undoAction();
	Output* redoAction();
	Output* clearTask();
	Output* checkTask(std::string);
	Output* checkCompletedTask();
	Output* uncheckTask(std::string);
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
	Output* changeStorageDirectory(std::string);
};

#endif