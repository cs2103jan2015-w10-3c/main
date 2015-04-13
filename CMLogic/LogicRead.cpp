//@author A0111448M
#include <string>
#include <iostream>
#include <sstream>
#include "LogicRead.h"


Command* LogicRead :: interpretCommand(std::string input){
	std::istringstream userInput(input);
	std::string userCommand;	
	std::string description;	

	int commandIndex;

	if(userInput>>userCommand){
		commandIndex = indexCommand(userCommand);
	}else {commandIndex = INVALIDCOMMAND;}

	if(getline(userInput,description)){
		description=description.substr(1);
	}else{
		description="";}

	std::cout<<"2. LogicRead :"<<commandIndex<<" " <<description<<std::endl;
	Command* IndexedCommand = new Command(commandIndex,description);


	return IndexedCommand;
}


int LogicRead :: indexCommand(std::string NewCommand){

	std::string command = lowerCase(NewCommand); 

	if(command==ADD){
		return INDEXADD;
	}else if
		(command==SEARCH){
			return  INDEXSEARCH;
	}else if
		(command==EDIT){
			return INDEXEDIT;
	}else if
		(command==DEL){
			return INDEXDELETE;
	}else if
		(command==TODAY){
			return INDEXTODAY;
	}else if
		(command==TOMORROW){
			return INDEXTOMORROW;
	}else if
		(command==UNDO){
			return INDEXUNDO;
	}else if
		(command==EXIT){
			return INDEXEXIT;
	}else if
		(command==CHECK){
			return INDEXCHECKTASK;
	}else if
		(command==REDO){
			return INDEXUNDO;
	}else if
		(command==CLEAR){
			return INDEXCLEAR;
	}else if
		(command==COMPLETED){
			return INDEXCOMPLETED;
	}else if
		(command==UNCHECK){
			return INDEXUNCHECK;
	}else if
		(command==CHANGESTORE){
			return INDEXCHANGESTORE;
	}else if
		(command==HOME){
			return INDEXHOME;
	}else{
		return INVALIDCOMMAND;
	}
}

std::string LogicRead :: lowerCase(std::string commandInput){

	char newCase;
	for(unsigned int index = 0; index < commandInput.size();index++){
		if(isupper(commandInput[index])){ 
			newCase= tolower(commandInput[index]);
			commandInput[index] = newCase;
		}
	}
	return commandInput;
}