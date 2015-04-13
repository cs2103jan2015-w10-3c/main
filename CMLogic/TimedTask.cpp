//@author A0111448M
#include <iomanip>
#include <sstream>
#include <algorithm>
#include<string>
#include "TimedTask.h"
#include<string>



TimedTask::TimedTask(std::string description,boost::posix_time::ptime start, boost::posix_time::ptime end)
	:Task(description){ 
		_start=start;
		_end =end;
}


TimedTask::~TimedTask(void)
{
}

void TimedTask:: editStartTime(boost::posix_time::ptime newStart){
	_start = newStart;
}

void TimedTask:: editEndTime (boost::posix_time::ptime newEnd){
	_end = newEnd;
}

void TimedTask:: editStartDate(boost::posix_time::ptime newStart){
	_start = newStart;
}

void TimedTask:: editEndDate (boost::posix_time::ptime newEnd){
	_end = newEnd;
}


boost::posix_time::ptime TimedTask:: getStart() const{
	return _start; }


boost::posix_time::ptime TimedTask:: getEnd() const{
	return _end;
}

bool TimedTask :: hasClash(boost::posix_time::ptime newStart, boost::posix_time::ptime newEnd){

	if((newEnd<=_start)||(newStart>=_end)){
		return NOCLASH;
	}else{
		return CLASH;
	}

}

bool TimedTask:: isFound (std::string keyword){
	bool found = false;
	size_t position;


	position = _description.find(keyword);
	if(position!= std::string::npos){
		return true;
	} else{
		position = to_simple_string(_start).find(keyword);
		if(position!= std::string::npos){
			return true;
		}else{
			position = to_simple_string(_end).find(keyword);
			if(position!= std::string::npos){
				return true;
			}
		}
	}

	return found;
}

std::string TimedTask:: getInfo() {
	std::ostringstream information;

	information <<std::left << std::setw(60)<<_description 
		<<std::setw(30)<<to_simple_string(_start)
		<<std::setw(30)<<to_simple_string(_end);

	return information.str();
}

bool TimedTask :: isFloat(){
	return false;
}

bool TimedTask :: isTimed(){
	return true;
}

bool TimedTask:: isDeadline(){
	return false;
}

bool TimedTask :: isEditedTask(std::string description, boost::posix_time::ptime start, boost::posix_time::ptime end){
	if(description==_description && start == _start&& end ==_end){
		return true;
	} else {
		return false;}
}