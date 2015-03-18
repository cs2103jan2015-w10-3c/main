#include "Deadline.h"
#include <iomanip>
#include <sstream>
#include <algorithm>


Deadline::Deadline(std::string Description,std::string Category ,ptime Start)
	:Task( Description, Category){ 
	_Start = Start;
}

Deadline::~Deadline(void){
}

void Deadline:: editStartDate(ptime NewStart){
	_Start = NewStart;
}
void Deadline:: editStartTime (ptime NewStart){
	_Start = NewStart;
}

void Deadline:: editEndDate (ptime NewEnd){
	return;
}
void Deadline:: editEndTime (ptime NewEnd){
	return;
}


ptime Deadline:: getStart() const{
	return _Start; 
}


ptime Deadline:: getEnd() const{
	return ptime(not_a_date_time);
}

bool Deadline:: isFound (std::string keyword){

	bool found = false;
	size_t position;
	position = _Description.find(keyword);
	if(position!= std::string::npos)
		found = true;
	position = _Category.find(keyword);
	if(position!= std::string::npos)
		found = true;
	position = to_simple_string(_Start).find(keyword);
	if(position!= std::string::npos)
		found = true;

	return found;
}

std:: string Deadline:: getInfo() {
	std::ostringstream information;
	
	information <<std::left<< std::setw(15)<<_Description 
				<<std::setw(10)<<_Start
				<<std::setw(10)<<"-"
				<<std::setw(8)<<"-"
				<<std::setw(8)<< _Category;

	return information.str();
}	
