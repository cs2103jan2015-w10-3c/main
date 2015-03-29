#ifndef LOGICCOMMAND_H
#define LOGICCOMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include "CMParser.h"
#include "CheckMateStorage.h"
#include "Output.h"
#include "Task.h"
#include "FloatingTask.h"
#include "Deadline.h"
#include "TimedTask.h"

const std::string INVALID_INPUT = "Invalid command given!";
const std::string FLOATINGTYPE = "float";
const std::string TIMEDTYPE = "time";
const std::string DEADLINE = "deadline";
const std::string ADDED = "was added!";
const std::string DELETED = "was deleted!";
const std::string EDITED = "was edited!";
const std::string SEARCHFOUND = "The search has found ";
const std::string TASKS = "tasks.";


class LogicCommand
{
	CMParser _Parser;
	CMStorage _Storage;
	std::vector <std::string> _toDisplay;

public:
	LogicCommand(void);
	~LogicCommand(void);
	Output addFloatTask(std::string);
	Output addTimeTask(std::string);
	Output addDeadlines(std::string);
	Output deleteTask(std::string);
	Output searchTask (std::string);
	Output EditTask(std::string);
	/*std::string DisplayToday();
	std::string DisplayTommorrow();*/
};

#endif