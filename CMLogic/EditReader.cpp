//@author A0111448M
#include "EditReader.h"
#include <sstream>
#include <cctype>

EditReader::EditReader(void){
	int _taskIndex =-1;
	int _categoryindex = -1;
	std::string _newInput ="";
}


EditReader::~EditReader(void){
}

bool EditReader::interpretCommand(std::string CommandInput){
	//Find index of Searched Task
	std::istringstream editDetails(CommandInput);

	if(editDetails>>_taskIndex){
	}else{
		return false;
	}

	std::string Category;

	if(editDetails>>Category){
		_categoryIndex=indexCategory(Category);
	} else {
		_categoryIndex=INVALIDINDEX;
		_newInput="";
		return false;}					//Invalid Input


	if(getline(editDetails,_newInput)){
		_newInput=_newInput.substr(1);
		return true;} 
	else{
		_newInput="";
		return false;}
}

int EditReader::indexCategory(std::string category){

	std::string catergory = lowerCase(category); 

	if(catergory==DESCRIPTION){
		return DESCRIPTIONINDEX;}
	else if
		(catergory==STARTTIME){
			return STARTTIMEINDEX;
	}else if
		(catergory==ENDTIME){
			return ENDTIMEINDEX;
	}else if
		(catergory==STARTDATE){
			return STARTDATEINDEX;
	}else if
		(catergory==ENDDATE){
			return ENDDATEINDEX;
	}else
		return INVALIDINDEX;
}

std::string EditReader :: lowerCase(std::string commandInput){

	char newCase;
	for(unsigned int index = 0; index < commandInput.size();index++){
		if(isupper(commandInput[index])){ 
			newCase= tolower(commandInput[index]);
			commandInput[index] = newCase;
		}
	}
	return commandInput;
}

int EditReader:: getTaskIndex() const {
	return _taskIndex;
}

int EditReader:: getSelectedCategory() const {
	return _categoryIndex;
}

std::string EditReader:: getNewInput() const {
	return _newInput;
}