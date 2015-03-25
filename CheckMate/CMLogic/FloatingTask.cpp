#include "FloatingTask.h"
#include <sstream>
#include <iomanip>
#include <string>



FloatingTask::FloatingTask(std::string Description, std::string Category)
	:Task( Description, Category){}


FloatingTask::~FloatingTask(void)
{}

void FloatingTask:: editStartDate(ptime NewStart){
	return;
}

void FloatingTask:: editStartTime (ptime NewStart){
	return;
}
void FloatingTask:: editEndDate (ptime NewEnd){
	return;
}
void FloatingTask:: editEndTime (ptime NewEnd){
	return;
}

ptime FloatingTask:: getStart() const{
	return ptime(not_a_date_time); }


ptime FloatingTask:: getEnd() const{
	return ptime(not_a_date_time);
}


bool FloatingTask :: isFound(std::string keyword){
	bool found = false;
	size_t position;
	
	position = _Category.find(keyword);
	if(position!= std::string::npos)
	{return true;}
	
	position = _Description.find(keyword);
	if(position!= std::string::npos)
	{return true;}
	

	return found;
}

std::string FloatingTask:: getInfo() {
	std::ostringstream information;
	
	information <<std::left << std::setw(40)<<_Description
				<<std::setw(10)<<"-"
				<<std::setw(20)<<"-"
				<<std::setw(10)<<"-"
				<<std::setw(20)<<"-"
				<<std::setw(30)<< _Category;
				

	return information.str();
}
