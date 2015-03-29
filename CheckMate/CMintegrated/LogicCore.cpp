#include <iostream>
#include <vector>
#include <string>
#include "LogicCore.h"

using namespace std;

LogicCore::LogicCore(void)
{ _IsActive = true;		//Program is running.
}


LogicCore::~LogicCore(void)
{ _IsActive = false;
}


void LogicCore :: ExecuteCommand(string input){
	_CommandInput.readCommand(input);
	switch(_CommandInput.getCommandIndex()){
		//AddFloatingTask
	case 1 :{ 
		string Description =_Parser.getDescription(_CommandInput.getInput(),FLOATINGTYPE);
		string Category = _Parser.getCategory(_CommandInput.getInput());
		_Storage.addFloatingTask(Description,Category);
		_toDisplay=_Storage.getDisplay();
		string feedback = Description + " " + Category + " " + ADDED;
		_Feedback= feedback;
			}
			break;

			//Add Deadline
	case 2:{string Description =_Parser.getDescription(_CommandInput.getInput(),DEADLINE);
		string Category = _Parser.getCategory(_CommandInput.getInput());
		string StartDate = _Parser.getStartTime(_CommandInput.getInput(),DEADLINE);
		string StartTime =_Parser.getStartDate(_CommandInput.getInput(),DEADLINE);
		_Storage.addDeadline(Description,Category,StartDate,StartTime);
		_toDisplay=_Storage.getDisplay();
		string feedback = Description +  " " + StartDate + " " + StartTime +" " + Category + " " + ADDED;
		_Feedback= feedback;

		   }
		   break;

		   //Add TimedTasked
	case 3:{
		string Description =_Parser.getDescription(_CommandInput.getInput(),TIMEDTYPE);
		string Category = _Parser.getCategory(_CommandInput.getInput());
		string StartDate = _Parser.getStartTime(_CommandInput.getInput(),TIMEDTYPE);
		string StartTime =_Parser.getStartDate(_CommandInput.getInput(),TIMEDTYPE);
		string EndDate = _Parser.getEndTime(_CommandInput.getInput());
		string EndTime =_Parser.getEndDate(_CommandInput.getInput());
		_Storage.addTimedTask(Description,Category,StartDate,StartTime, EndDate,EndTime);

		_toDisplay=_Storage.getDisplay();

		string feedback = Description +  " " + StartDate + " " + StartTime + " " +
			EndDate + " " + EndTime + " " + " " + Category + ADDED;
		_Feedback= feedback;
		   }
		   break;

		   //Search Case
	case 4:{   
		_toDisplay= _Storage.searchTask(_CommandInput.getInput());
		   }
		   break;

		   //Edit Case
	case 5:{
		   }
		   break;

		   //Delete Case
	case 6:{ 
		int index =atoi(_CommandInput.getInput().c_str());
		_Storage.deleteTask(index);
		_toDisplay=_Storage.getDisplay();
		   }
		   break;

		   //Invalid Input
	default:{
		cout << INVALID_INPUT << endl;
			}
			break;
	}

}
string LogicCore:: getFeedback(){
	return _Feedback; }


vector <string> LogicCore:: getDisplay(){
	return _toDisplay; }
