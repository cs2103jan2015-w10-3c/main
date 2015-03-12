#include "TimedTask.h"
#include <iomanip>
#include <sstream>
#include <algorithm>



TimedTask::TimedTask(string Description,string Category ,string StartDate,string StartTime,string EndDate,string EndTime)
	:Task( Description, Category)
{ 
	_StartDate = StartDate;
	_StartTime = StartTime;
	_EndDate = EndDate;
	_EndTime = EndTime;
}


TimedTask::~TimedTask(void)
{
}

void TimedTask:: editStartDate(string NewStartDate){
	_StartDate = NewStartDate;
}

void TimedTask:: editStartTime (string NewStartTime){
	_StartTime = NewStartTime;
}
void TimedTask:: editEndDate (string NewEndDate){
	_EndDate = NewEndDate;
}
void TimedTask:: editEndTime (string NewEndTime){
	_EndTime = NewEndTime;
}

string TimedTask:: getStartDate() const{
	return _StartDate; }
string TimedTask:: getStartTime() const{
	return _StartTime;
}

string TimedTask:: getEndDate() const{
	return _EndDate;
}

 string TimedTask:: getEndTime() const{
	return _EndTime;
}

bool TimedTask:: isFound (string keyword){
	bool found = false;
	size_t position;
	position = _Description.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _Category.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _StartDate.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _StartTime.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _EndDate.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _EndTime.find(keyword);
	if(position!= string::npos)
		found = true;

	return found;
}

string TimedTask:: getInfo() {
	ostringstream information;
	
	information << left << setw(15)<<_Description 
				<<setw(10)<<_StartDate
				<<setw(8)<<_StartTime
				<<setw(10)<<_EndDate
				<<setw(8)<<_EndTime
				<<setw(8)<< _Category;
	return information.str();
}
