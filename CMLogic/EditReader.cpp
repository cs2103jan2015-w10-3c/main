#include "EditReader.h"
<<<<<<< HEAD

=======
#include <sstream>
#include <cctype>
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e

EditReader::EditReader(void)
{  int _TaskIndex =-1;
int _Categoryindex = -1;
std::string _NewInput ="";
}


EditReader::~EditReader(void)
{
}

<<<<<<< HEAD
void EditReader::interpretCommand(std::string CommandInput){
	//Find index of Searched Task
	std::size_t FirstLetter = CommandInput.find_first_not_of(" ");
	std::size_t LastLetter = CommandInput.find_first_of(" ",FirstLetter);
	std::string TaskIndex = CommandInput.substr(FirstLetter,LastLetter-FirstLetter);	//Chosen Task from Searched List
	_TaskIndex =atoi(TaskIndex.c_str());

	//Index Selected Category
	FirstLetter = CommandInput.find_first_not_of(" ",LastLetter);
	LastLetter = CommandInput.find_first_of(" ",FirstLetter);
	std:: string SelectedCategory = CommandInput.substr(FirstLetter,LastLetter-FirstLetter);
	_Categoryindex=indexCategory(SelectedCategory);

	//Find New input
	_NewInput=CommandInput.substr(LastLetter);

}

int EditReader::indexCategory(std::string categorystring){
	if(categorystring==DESCRIPTION){
		return DESCRIPTIONINDEX;}
	else{
		if(categorystring==STARTTIME){
				return STARTTIMEINDEX;}
			else{
				if(categorystring==ENDTIME){
					return ENDTIMEINDEX;}
				else{
					if(categorystring==STARTDATE){
						return STARTDATEINDEX;}
					else{
						if(categorystring==ENDDATE){
							return ENDDATEINDEX;}
						else{
							return INVALIDINDEX;}
					}}}}
=======
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
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}

int EditReader:: getTaskindex() const {
	return _TaskIndex;
}

int EditReader:: getSelectedCategory() const {
<<<<<<< HEAD
	return _Categoryindex;
=======
	return _CategoryIndex;
>>>>>>> c362e76c48e8505b12b61bf0ff5e09c006a3d56e
}

std::string EditReader:: getNewInput() const {
	return _NewInput;
}