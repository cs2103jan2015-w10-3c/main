#pragma once
#include "Task.h"
#include "LogicRead.h"
#include <vector>
#include "CMParser.h"
#include "CheckMateStorage.h"

const string INVALID_INPUT = "Invalid command given!";
const string FLOATINGTYPE = "float";
const string TIMEDTYPE = "time";
const string DEADLINE = "deadline";
const string ADDED = "was added!";
const string DELETED = "was deleted!";
const string EDITED = "was edited!";

class LogicCore
{		CMParser _Parser;
		CMStorage _Storage;
		string _Feedback;
		vector <string> _toDisplay;
		LogicRead _CommandInput;
		bool _IsActive;
public:
		LogicCore(void);
		~LogicCore(void);
		void ExecuteCommand(string);
		string getFeedback();
		vector <string> getDisplay();
	
};

