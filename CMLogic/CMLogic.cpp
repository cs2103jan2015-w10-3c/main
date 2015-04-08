#include <iostream>
#include <vector>
#include <string>

#include "CMLogic.h"



CMLogic::CMLogic(){
	_isActive= true;
}

void CMLogic :: startUp(){
	_display=_commandExecutor.retrieveData();
	return;
}


void CMLogic :: executeCommand(std::string input){
	//Obtains index for switch and Description behind
	Command* newCommand = _commandReader.interpretCommand(input);
	int commandIndex = newCommand->getCommandIndex();
	std::string commandDescription=newCommand->getCommandDescription();

	switch(commandIndex){
		//AddTask
	case INDEXADD :{ 
		_display= _commandExecutor.addTask(commandDescription,FROMUSER,UNCOMPLETEDTASK); 
				   }
				   break;

				   //Search all mathcing Task
	case INDEXSEARCH:{   
		_display  = _commandExecutor.searchTask(commandDescription);
					 }
					 break;

					 //Edit a task
	case INDEXEDIT:{
		_display = _commandExecutor.editTask(commandDescription);
				   }
				   break;

				   //Delete task
	case INDEXDELETE:{ 
		_display = _commandExecutor.deleteTask(commandDescription);
					 }
					 break;

					 //Search for all Task Today
	case INDEXTODAY:{
		_display = _commandExecutor.displayToday();
					}
					break;

					//Search for all Task Tommorrow
	case INDEXTOMORROW:{
		_display = _commandExecutor.displayTomorrow();
					   }
					   break;

					   //Undo previous action
	case INDEXUNDO	:{
		_display=_commandExecutor.undoAction();
					 }
					 break;
					 //redo undone action
	case INDEXREDO:{
		_display=_commandExecutor.redoAction();
				   }
				   break;
				   //redo undone action
	case INDEXCLEAR:{
		_display=_commandExecutor.clearTask();
					}
					break;

					//check an index Task
	case INDEXCHECKTASK	:{
		_display=_commandExecutor.checkTask(commandDescription);
						 }
						 break;
						 //closes the Program
	case INDEXCOMPLETED:{
		_display=_commandExecutor.checkCompletedTask();
						}
						break;

	case INDEXUNCHECK:{
		_display=_commandExecutor.uncheckTask(commandDescription);
					  }
					  break;
	case INDEXCHANGESTORE:{
		_display=_commandExecutor.changeStorageDirectory(commandDescription);
					  }
					  break;

					  //Invalid Input
	default:{
		_display->editFeedback(INVALID_INPUT);
			}
			break;
	}

	return;

}

Output*  CMLogic :: getDisplay(){
	return _display;
}

