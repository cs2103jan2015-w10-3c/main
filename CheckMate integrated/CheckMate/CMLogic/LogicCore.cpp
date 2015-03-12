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
		_Feedback= _CommandAction.addFloatTask(_CommandInput.getInput());
			}
			break;

			//Add Deadline
	case 2:{
		_Feedback = _CommandAction.addDeadlines(_CommandInput.getInput());
		   }
		   break;

		   //Add TimedTasked
	case 3:{
		_Feedback = _CommandAction.addTimeTask (_CommandInput.getInput());
		   }
		   break;

		   //Search Case
	case 4:{   
		_Feedback = _CommandAction.searchTask(_CommandInput.getInput());
		   }
		   break;

		   //Edit Case
	case 5:{
		_Feedback = _CommandAction.EditTask(_CommandInput.getInput());
		   }
		   break;

		   //Delete Case
	case 6:{ 
		_Feedback = _CommandAction.deleteTask(_CommandInput.getInput());
		   }
		   break;

	/*	      //Search for task today
	case 7:{
		_Feedback = _CommandAction.DisplayToday();
		   }
		   break;

		      //Search for task tommorrow
	case 8:{
		_Feedback = _CommandAction.DisplayTommorrow();
		   }
		   break;
		      //Undo previous action
	case 9:{
		   }
		   break;
		      // View help function commands
	case 10:{
		   }
		   break;
		   */

		   // Close Program
	case 11:{
			_IsActive = false;
			cout << GOODBYE << endl;}
		   break;
		
		   //Invalid Input
	default:{
		cout << INVALID_INPUT << endl;
			}
			break;
	}

}
string LogicCore:: displayFeedback(){
	return _Feedback; }


vector <string> LogicCore:: displayTask(){
	return _CommandAction.getDisplay();}
