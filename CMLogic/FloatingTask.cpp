//@author A0111448M
#include "FloatingTask.h"
#include <sstream>
#include <iomanip>
#include <string>



FloatingTask::FloatingTask(std::string description)
	:Task(description){}


FloatingTask::~FloatingTask(void)
{}

void FloatingTask:: editStartDate(boost::posix_time::ptime NewStart){
	return;
}

void FloatingTask:: editStartTime (boost::posix_time::ptime NewStart){
	return;
}
void FloatingTask:: editEndDate (boost::posix_time::ptime NewEnd){
	return;
}
void FloatingTask:: editEndTime (boost::posix_time::ptime NewEnd){
	return;
}

boost::posix_time::ptime FloatingTask:: getStart() const{
	return boost::posix_time::ptime(); }


boost::posix_time::ptime FloatingTask:: getEnd() const{
	return boost::posix_time::ptime();
}

bool FloatingTask :: hasClash(boost::posix_time::ptime newStart, boost::posix_time::ptime newEnd){
	return NOCLASH;
}


bool FloatingTask :: isFound(std::string keyword){
	bool found = false;
	size_t position;

	position = _description.find(keyword);
	if(position!= std::string::npos)
	{return true;}


	return found;
}

std::string FloatingTask:: getInfo() {
	std::ostringstream information;

	information <<std::left << std::setw(60)<<_description
		<<std::setw(30)<<"      --NIL--"
		<<std::setw(30)<<"      --NIL--";

	return information.str();
}

bool FloatingTask :: isFloat(){
	return true;
}

bool FloatingTask :: isTimed(){
	return false;
}

bool FloatingTask :: isDeadline(){
	return false;
}

bool FloatingTask :: isEditedTask(std::string description, boost::posix_time::ptime start, boost::posix_time::ptime end){
	if(description==_description && start == boost::posix_time::ptime()&& end == boost::posix_time::ptime()){
		return true;
	} else {
		return false;}
}