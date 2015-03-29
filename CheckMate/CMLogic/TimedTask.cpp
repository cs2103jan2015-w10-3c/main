#include <iomanip>
#include <sstream>
#include <algorithm>
#include<string>
#include "TimedTask.h"
#include<string>



TimedTask::TimedTask(std::string Description,ptime start, ptime end)
	:Task( Description){ 
		_Start=start;
		_End =end;
}


TimedTask::~TimedTask(void)
{
}

void TimedTask:: editStartTime(ptime NewStart){
	_Start = NewStart;
}

void TimedTask:: editEndTime (ptime NewEnd){
	_End = NewEnd;
}

void TimedTask:: editStartDate(ptime NewStart){
	_Start = NewStart;
}

void TimedTask:: editEndDate (ptime NewEnd){
	_End = NewEnd;
}


ptime TimedTask:: getStart() const{
	return _Start; }


ptime TimedTask:: getEnd() const{
	return _End;
}

bool TimedTask:: isFound (std::string keyword){
	bool found = false;
	size_t position;


		position = _Description.find(keyword);
		if(position!= std::string::npos)
		{return true;}

		else{
			position = to_simple_string(_Start).find(keyword);
			if(position!= std::string::npos)
			{return true;}
			else{
				position = to_simple_string(_End).find(keyword);
				if(position!= std::string::npos)
				{return true;}
			}}

	return found;
}

std::string TimedTask:: getInfo() {
	std::ostringstream information;

	information <<std::left << std::setw(40)<<_Description 
		<<std::setw(40)<<to_simple_string(_Start)
		<<std::setw(40)<<to_simple_string(_End);

	return information.str();
}
