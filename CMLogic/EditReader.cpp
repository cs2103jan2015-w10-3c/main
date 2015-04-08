#include "EditReader.h"
#include <sstream>
#include <cctype>

EditReader::EditReader(void)
{  int _TaskIndex =-1;
int _Categoryindex = -1;
std::string _NewInput ="";
}


EditReader::~EditReader(void)
{
}

bool EditReader::interpretCommand(std::string CommandInput){
	//Find index of Searched Task
	std::istringstream EditDetails(CommandInput);

	if(EditDetails>>_TaskIndex){
	}else {return false;}

	std::string Category;

	if(EditDetails>>Category){
		_CategoryIndex=indexCategory(Category);
	} else {return false;}					//Invalid Input


	if(getline(EditDetails,_NewInput)){
		_NewInput=_NewInput.substr(1);
		return true;} 
	else{
		return false;}
}

int EditReader::indexCategory(std::string category){

	std::string Catergory = lowerCase(category); 

	if(Catergory==DESCRIPTION){
		return DESCRIPTIONINDEX;}
	else if
		(Catergory==STARTTIME){
			return STARTTIMEINDEX;
	}else if
		(Catergory==ENDTIME){
			return ENDTIMEINDEX;
	}else if
		(Catergory==STARTDATE){
			return STARTDATEINDEX;
	}else if
		(Catergory==ENDDATE){
			return ENDDATEINDEX;
	}else
		return INVALIDINDEX;
}

std::string EditReader :: lowerCase(std::string CommandInput){

	char NewCase;
	for(unsigned int index = 0; index < CommandInput.size();index++){
		if(isupper(CommandInput[index])){ 
			NewCase= tolower(CommandInput[index]);
			CommandInput[index] = NewCase;
		}
	}
	return CommandInput;
}

int EditReader:: getTaskindex() const {
	return _TaskIndex;
}

int EditReader:: getSelectedCategory() const {
	return _CategoryIndex;
}

std::string EditReader:: getNewInput() const {
	return _NewInput;
}