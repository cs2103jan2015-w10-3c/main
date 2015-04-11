#include <string>
#include <iostream>
<<<<<<< HEAD
#include "LogicRead.h"


LogicRead::LogicRead(void)
{}


LogicRead:: ~LogicRead(void)
{}

Command* LogicRead :: interpretCommand(std::string input){
	//Finding the first word
	std::size_t FirstLetter = input.find_first_not_of(" ");
	std::size_t LastLetter = input.find_first_of(" ",FirstLetter);
	std::string FirstWord = input.substr(FirstLetter,LastLetter-FirstLetter);
	FirstLetter = input.find_first_not_of(" ",LastLetter);
	Command* IndexedCommand = new Command(indexCommand(FirstWord),input.substr(FirstLetter));
=======
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


	Command* IndexedCommand = new Command(commandIndex,description);

>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

	return IndexedCommand;
}


<<<<<<< HEAD
int LogicRead :: indexCommand(std::string command){
	if(command==ADD){
		return INDEXADD;
	}else {
		if(command==SEARCH){
			return  INDEXSEARCH;
		}else{
			if(command==EDIT){
				return INDEXEDIT;
			}else{
				if(command==DEL){
					return INDEXDELETE;
				}else{
					if(command==TODAY){
						return INDEXTODAY;
					}else{
						if(command==TOMMORROW){
							return INDEXTOMMORROW;
						}else{
							if(command==UNDO){
								return INDEXUNDO;
							}else{
								if(command==HELP){
									return INDEXHELP;
								}else{
									if(command==EXIT){
										return INDEXEXIT;
									}else{
										if(command==CHECK){
											return INDEXCHECKTASK;
									}else{
										return INVALIDCOMMAND;
									}}}}}}}}}}
=======
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
			return INDEXREDO;
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
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}