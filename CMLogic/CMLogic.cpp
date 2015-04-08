#include <iostream>
#include <vector>
#include <string>

#include "CMLogic.h"



CMLogic::CMLogic(){
<<<<<<< HEAD
	_IsActive= true;
}

void CMLogic :: startUp(){
		_Display=_CommandExecutor.retrieveData();
		return;
}


void CMLogic :: ExecuteCommand(std::string input){

	Command* NewCommand = _CommandReader.interpretCommand(input);

	switch(NewCommand->getCommandIndex()){
		//AddTask
	case INDEXADD :{ 
		_Display= _CommandExecutor.addTask(NewCommand->getCommandDescription()); 
					   }
					   break;

					  //Search Case
	case INDEXSEARCH:{   
		_Display  = _CommandExecutor.searchTask(NewCommand->getCommandDescription());
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

					 //Search for task today
	case INDEXTODAY:{
		_Display = _CommandExecutor.DisplayToday();
					}
					break;

					//Search for task tommorrow
	case INDEXTOMMORROW:{
		_Display = _CommandExecutor.DisplayTomorrow();
						}
						break;
						//Undo previous action
	case INDEXUNDO	:{
		_Display=_CommandExecutor.UndoAction();
					 }
					 break;

	case INDEXCHECKTASK	:{
		_Display=(_CommandExecutor.CheckTask(NewCommand->getCommandDescription()));
					 }
					 break;

					 // View help function commands
	/*case INDEXHELP	:{
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
=======
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
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
			}
			break;
	}

	return;

}

Output*  CMLogic :: getDisplay(){
<<<<<<< HEAD

	return _Display;
=======
	return _display;
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}

