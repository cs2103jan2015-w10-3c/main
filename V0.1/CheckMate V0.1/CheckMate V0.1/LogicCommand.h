#include "CMParser.h"
#include "CMStorage.h"
#include <iostream>
#include <string>
#include <vector>

const string INVALID_INPUT = "Invalid command given!";
const string FLOATINGTYPE = "float";
const string TIMEDTYPE = "time";
const string DEADLINE = "deadline";
const string ADDED = "was added!";
const string DELETED = "was deleted!";
const string EDITED = "was edited!";
const string SEARCHFOUND = "The search has found ";
const string TASKS = "tasks.";

using namespace std;

class LogicCommand
{
	CMParser _Parser;
	CMStorage _Storage;
	vector <string> _toDisplay;

public:
	LogicCommand(void);
	~LogicCommand(void);
	string addFloatTask(string);
	string addTimeTask(string);
	string addDeadlines(string);
	string deleteTask(string);
	string searchTask (string);
	/*string EditTask(string);
	string DisplayToday();
	string DisplayTommorrow();*/
	vector <string> getDisplay();

};

