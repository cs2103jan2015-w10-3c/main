//@author A0111448M
#include "Deadline.h"
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>


Deadline::Deadline(std::string description,boost::posix_time::ptime end)
	:Task(description){ 
		_end = end;
}

Deadline::~Deadline(void){
}

void Deadline:: editStartDate(boost::posix_time::ptime newStart){
	return;
}
void Deadline:: editStartTime (boost::posix_time::ptime newStart){
	return;
}

void Deadline:: editEndDate (boost::posix_time::ptime newEnd){
	_end= newEnd;
}
void Deadline:: editEndTime (boost::posix_time::ptime newEnd){
	_end=newEnd;
}


boost::posix_time::ptime Deadline:: getStart() const{
	return boost::posix_time::ptime() ; 
}


boost::posix_time::ptime Deadline:: getEnd() const{
	return _end;
}


bool Deadline :: hasClash(boost::posix_time::ptime newStart,boost::posix_time::ptime newEnd){
	return NOCLASH;
}

bool Deadline:: isFound (std::string keyword){

	bool found = false;
	size_t position;

	position = _description.find(keyword);
	if(position!= std::string::npos){
		found = true;
	}

	position = to_simple_string(_end).find(keyword);
	if(position!= std::string::npos){
		found = true;
	}

	return found;
}

std:: string Deadline:: getInfo() {
	std::ostringstream information;

	information <<std::left<< std::setw(60)<<_description
		<<std::setw(30)<<"      --NIL--"
		<<std::setw(30)<<to_simple_string(_end);


	return information.str();
}	

bool Deadline :: isFloat(){
	return false;
}

bool Deadline :: isTimed(){
	return false;
}

bool Deadline :: isDeadline(){
	return true;
}

bool Deadline :: isEditedTask(std::string description, boost::posix_time::ptime start, boost::posix_time::ptime end){
	if(description==_description && start == boost::posix_time::ptime()&& end == _end){
		return true;
	} else {
		return false;
	}
}