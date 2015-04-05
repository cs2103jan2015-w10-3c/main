#include <iostream>
#include <vector>
#include <string>

#include "CMLogic.h"



CMLogic::CMLogic(){
	_IsActive= true;
}

void CMLogic :: startUp(){
	_Display=_CommandExecutor.retrieveData();
	return;
}


void CMLogic :: ExecuteCommand(std::string input){

	Command* NewCommand = _CommandReader.interpretCommand(input);		//Obtains index for switch and Description behind
	int CommandIndex = NewCommand->getCommandIndex();
	std::string CommandDescription=NewCommand->getCommandDescription();

	switch(CommandIndex){
		//AddTask
	case INDEXADD :{ 
		_Display= _CommandExecutor.addTask(CommandDescription,FROMUSER); 
				   }
				   break;

				   //Search all mathcing Task
	case INDEXSEARCH:{   
		_Display  = _CommandExecutor.searchTask(CommandDescription);
					 }
					 break;

					 //Edit a task
	case INDEXEDIT:{
		_Display = _CommandExecutor.editTask(CommandDescription);
				   }
				   break;

				   //Delete task
	case INDEXDELETE:{ 
		_Display = _CommandExecutor.deleteTask(CommandDescription);
					 }
					 break;

					 //Search for all Task Today
	case INDEXTODAY:{
		_Display = _CommandExecutor.displayToday();
					}
					break;

					//Search for all Task Tommorrow
	case INDEXTOMMORROW:{
		_Display = _CommandExecutor.displayTomorrow();
						}
						break;

						//Undo previous action
	case INDEXUNDO	:{
		_Display=_CommandExecutor.undoAction();
					 }
					 break;
					 //redo undone action
	case INDEXREDO:{
		_Display=_CommandExecutor.redoAction();
				   }
				   break;
				   //redo undone action
	case INDEXCLEAR:{
		_Display=_CommandExecutor.clearTask();
					}
					break;

					//check an index Task
	case INDEXCHECKTASK	:{
		_Display=_CommandExecutor.checkTask(CommandDescription);
						 }
						 break;
						 //closes the Program
	/*case INDEXEXIT:{
		_IsActive = false;
		_Display=_CommandExecutor.exit();
				   }
				   break;*/

				   //Invalid Input
	default:{
		_Display->editFeedback(INVALID_INPUT);
			}
			break;
	}

	return;

}

Output*  CMLogic :: getDisplay(){
	return _Display;
}

