#include <string>
#include <iostream>
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

	return IndexedCommand;
}


int LogicRead :: indexCommand(std::string command){
	if(command==ADD){
		return ADDTASK;
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
										return INVALIDCOMMAND;
									}}}}}}}}}}
