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
const std::string INVALIDTASKTYPE ="Invalid Task Type Chosen!";
const std::string INVALIDTYPE ="Invalid Category Chosen!";
const std::string UNDID = "Action was undone!";
const std::string REDID = "Undo was redone!";

class LogicCommand{
	CMParser _Parser;
	CMStorage _Storage;
	EditReader Editor;
	std::vector <std::string> _toDisplay;

public:

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
};

#endif