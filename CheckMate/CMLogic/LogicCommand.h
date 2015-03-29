#ifndef LOGICCOMMAND_H
#define LOGICCOMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include "CMParser.h"
<<<<<<< HEAD
=======
#include "CMDateParser.h"
#include "CMTimeParser.h"
>>>>>>> e9e324e88bd6228cdc316ba3bcb4003a65e770ea
#include "CheckMateStorage.h"
#include "Output.h"
#include "Task.h"
#include "FloatingTask.h"
#include "Deadline.h"
#include "TimedTask.h"
#include "EditReader.h"
#include "boost/date_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

const std::string INVALID_INPUT = "Invalid command given!";
const std::string FLOATINGTYPE = "float";
const std::string TIMEDTYPE = "timed";
const std::string DEADLINE = "deadline";
const std::string ADDED = "was added!";
const std::string DELETED = "was deleted!";
const std::string EDITED = "Edit Done!";
const std::string SEARCHFOUND = "The search has found ";
const std::string TASKS = "tasks.";
const std::string INVALIDTYPE ="InvalidCategoryChosen!";
const std::string UNDID = "Action was undone!";
const std::string REDID = "Undo was redone!";

class LogicCommand{
	CMParser _Parser;
	CMStorage _Storage;
	EditReader Editor;
	std::vector <std::string> _toDisplay;

public:
	Output* addFloatTask(std::string);
	Output* addTimeTask(std::string);
	Output* addDeadlines(std::string);
	Output* deleteTask(std::string);
	Output* searchTask (std::string);
	Output* EditTask(std::string);
	Output* DisplayToday();
	Output* DisplayTomorrow();
	Output* UndoAction();
	Output* RedoAction();
};

#endif