#include "EditReader.h"


EditReader::EditReader(void)
{  int _TaskIndex =-1;
int _Categoryindex = -1;
std::string _NewInput ="";
}


EditReader::~EditReader(void)
{
}

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
		if(categorystring==CATEGORY){
			return CATEGORYINDEX;}
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
					}}}}}
}

int EditReader:: getTaskindex() const {
	return _TaskIndex;
}

int EditReader:: getSelectedCategory() const {
	return _Categoryindex;
}

std::string EditReader:: getNewInput() const {
	return _NewInput;
}