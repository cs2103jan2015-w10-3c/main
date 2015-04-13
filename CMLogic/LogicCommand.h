//@author A0111448M
#ifndef LOGICCOMMAND_H
#define LOGICCOMMAND_H

#include <iostream>
#include <sstream>
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
#include "StringConvertor.h"
#include "ClashCheck.h"

//Feedback after each action is done
const std::string INVALID_INPUT		= "Invalid command given!";
const std::string FLOATINGTYPE		= "float";
const std::string TIMEDTYPE			= "timed";
const std::string DEADLINE			= "deadline";
const std::string ADDED				= " was added!";
const std::string DELETED			= " was deleted!";
const std::string EDITED			= "Edit Done!";
const std::string SEARCHFOUND		= "Found";
const std::string TASKS				= " tasks.";
const std::string INVALIDTASKTYPE	= "Invalid Task Type Chosen!";
const std::string INVALIDTYPE		= "Invalid Category Chosen!";
const std::string UNDID				= "Action was undone!";
const std::string GOODBYE			= "Goodbye! ";
const std::string WELCOMEBACK		= "Welcome Back!";
const std::string NEWDIRECTORY		= "Directory Changed to ";
const std::string CHECKED			= "It has been checked";
const std::string CLEARED			= "All Task have been cleared!";
const std::string SAVED				= "Files have been saved";
const std::string ARCHIVED			= "These are the Completed Task.";
const std::string CLASHED			= "There is a clash with this appointment!";
const std::string NOTFOUND			= "No Task were Found";

const int NOINDEX					= -1;
const int FROMFILE					= 1;
const int FROMUSER					= 2;
const int NONOBSERVABLE				= -1;
const int NONE						= 0;
//For Add method to differentiate an archived task to a current task
const bool ACTIVETASK			= false;
const bool COMPLETEDTASK		= true;

//LogicCommand contains the meethods to execute the commands interprets in CMLogic.
//It is the component which utilizes the Parser and Storage components to interpret
//and store respectively. Logic Command returns an Output object which contains all neccessary
//details for the GUI to display.
class LogicCommand{
	CMParser _parser;								//To interpret descriptions, time and date
	CMStorage _storage;								//To store Task into files and change directory
	EditReader _editor;								//To edit Task in files
	ClashCheck _checker;							//To check if add Timed Task has clashes with previous task
	StringConvertor _stringConvertor;	

	bool _listType;
	std::string _feedback;
	std::vector <Task*> _taskList;					
	int _lastActionIndex;							//Index of Last User Action
	int _firstFloatIndex;							//Index for GUI to know where to seperate the float task in the list


public:
	Output* retrieveData();							
	Output* addTask (std::string,int,bool);			
	Output* addFloatTask(bool);						
	Output* addTimeTask(bool);						
	Output* addDeadlines(bool);
	Output* searchTask (std::string);
	Output* editTask(std::string);
	Output* deleteTask(std::string);
	Output* displayToday();
	Output* displayTomorrow();
	Output* undoAction();
	Output* clearTask();
	Output* checkTask(std::string);
	Output* checkCompletedTask();
	Output* uncheckTask(std::string);
	Output* changeStorageDirectory(std::string);
	Output* returnToHomePage();
};

#endif