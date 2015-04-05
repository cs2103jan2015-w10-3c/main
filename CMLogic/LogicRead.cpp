#include <string>
#include <iostream>
#include <sstream>
#include "LogicRead.h"


Command* LogicRead :: interpretCommand(std::string input){
	std::istringstream UserInput(input);
	
	std::string CommandOrder; //Finding the User Command
	std::string Description;	//Finding the details of command

	UserInput>>CommandOrder;
	getline(UserInput,Description);

	int CommandIndex = indexCommand(CommandOrder);

	Command* IndexedCommand = new Command(CommandIndex,Description);

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
		(command==TOMMORROW){
			return INDEXTOMMORROW;
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
		(command==START){
			return INDEXSTART;
	}else if
		(command==REDO){
			return INDEXREDO;
	}else if
		(command==CLEAR){
			return INDEXCLEAR;
	}else{
		return INVALIDCOMMAND;
	}
}

std::string LogicRead :: lowerCase(std::string CommandInput){

	char NewCase;
	for(unsigned int index = 0; index < CommandInput.size();index++){
		if(isupper(CommandInput[index])){ 
			NewCase= tolower(CommandInput[index]);
			CommandInput[index] = NewCase;
		}
	}
	return CommandInput;
}