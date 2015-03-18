#include <iostream>
#include <vector>
#include <string>

#include "CMLogic.h"




CMLogic::~CMLogic(void){
	
	_IsActive = false;
}

void CMLogic :: ExecuteCommand(std::string input){
	Command* NewCommand = _CommandReader.interpretCommand(input);
	switch(NewCommand->getCommandIndex()){
		//AddFloatingTask
	case ADDFLOATTASK :{ 
		_Display= _CommandExecutor.addFloatTask(NewCommand->getCommandDescription()); 
					  }
					   break;

					   //Add Deadline
	case ADDDEADLINE:{
		_Display = _CommandExecutor.addDeadlines(NewCommand->getCommandDescription());
					 }
					 break;

					 //Add TimedTasked
	case ADDTIMEDTASK:{
		_Display = _CommandExecutor.addTimeTask (NewCommand->getCommandDescription());
					  }
					  break;

					  //Search Case
	case INDEXSEARCH:{   
		_Display = _CommandExecutor.searchTask(NewCommand->getCommandDescription());
					 }
					 break;

					 //Edit Case
	case INDEXEDIT:{
		_Display = _CommandExecutor.EditTask(NewCommand->getCommandDescription());
				   }
				   break;

				   //Delete Case
	case INDEXDELETE:{ 
		_Display = _CommandExecutor.deleteTask(NewCommand->getCommandDescription());
					 }
					 break;

					 /*	      //Search for task today
					 case INDEXTODAY:{
					 _Feedback = _CommandAction.DisplayToday();
					 }
					 break;

					 //Search for task tommorrow
					 case INDEXTOMMORROW:{
					 _Feedback = _CommandAction.DisplayTommorrow();
					 }
					 break;
					 //Undo previous action
					 case INDEXUNDO	:{
					 }
					 break;
					 // View help function commands
					 case INDEXHELP	:{
					 }
					 break;
					 */

					 // Close Program
	case INDEXEXIT:{
		_IsActive = false;
		std::cout << GOODBYE << std::endl;}
				   break;

				   //Invalid Input
	default:{
		std::cout << INVALID_INPUT << std::endl;
			}
			break;
	}

}

Output CMLogic:: getOutput() const{
	return _Display; }


