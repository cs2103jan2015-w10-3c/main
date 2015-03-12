#include "LogicCommand.h"
#include <iostream>

using namespace std;

LogicCommand::LogicCommand(void)
{_toDisplay=_Storage.getDisplay();}


LogicCommand::~LogicCommand(void)
{}


string LogicCommand :: addFloatTask(string CommandInput){
	string Description =_Parser.getDescription(CommandInput,FLOATINGTYPE);
	string Category = _Parser.getCategory(CommandInput);
	string feedback = Description + " " + Category + " " + ADDED;
	_Storage.addFloatingTask(Description,Category);
	_toDisplay=_Storage.getDisplay();
	return feedback;
}


string LogicCommand :: addDeadlines(string CommandInput){
	string Description =_Parser.getDescription(CommandInput,DEADLINE);
	string Category = _Parser.getCategory(CommandInput);
	string StartDate = _Parser.getStartTime(CommandInput,DEADLINE);
	string StartTime =_Parser.getStartDate(CommandInput,DEADLINE);

	_Storage.addDeadline(Description,Category,StartDate,StartTime);
	_toDisplay=_Storage.getDisplay();

	string feedback = Description +  " " + StartDate + " " + StartTime +" " + Category + " " + ADDED;
	return feedback;
}

string LogicCommand :: addTimeTask(string CommandInput){

	string Description =_Parser.getDescription(CommandInput,TIMEDTYPE);
	string Category = _Parser.getCategory(CommandInput);
	string StartDate = _Parser.getStartTime(CommandInput,TIMEDTYPE); // To identify a deadline and TimedTask
	string StartTime =_Parser.getStartDate(CommandInput,TIMEDTYPE);
	string EndDate = _Parser.getEndTime(CommandInput);
	string EndTime =_Parser.getEndDate(CommandInput);

	_Storage.addTimedTask(Description,Category,StartDate,StartTime,EndDate,EndTime);
	_toDisplay=_Storage.getDisplay();

	string feedback = Description +  " " + StartDate + " " + StartTime + " " +
		EndDate + " " + EndTime +  " " + Category + ADDED;
	return feedback;
}

string LogicCommand :: searchTask (string CommandInput){
	_toDisplay= _Storage.searchTask(CommandInput);
	string feedback = SEARCHFOUND + _toDisplay.size() + " " + TASKS;
	return feedback;
}

string LogicCommand :: deleteTask(string CommandInput){
	int index =atoi(CommandInput.c_str());
	string feedback = _Storage.DeleteIndex(index);
	_toDisplay=_Storage.getDisplay();
	return feedback;
}
/*
string LogicCommand :: EditTask(string){

}

	string LogicCommand :: DisplayToday(){

	}

	string LogicCommand ::  DisplayTommorrow(){

	}

*/
vector <string> LogicCommand :: getDisplay(){
	return _toDisplay;}