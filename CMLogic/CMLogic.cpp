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
			}
			break;
	}

	return;

}

Output*  CMLogic :: getDisplay(){

	return _Display;
}

