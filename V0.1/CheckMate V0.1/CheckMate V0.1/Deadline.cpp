#include "Deadline.h"
#include <iomanip>
#include <sstream>
#include <algorithm>


Deadline::Deadline(string Description,string Category ,string StartDate,string StartTime)
	:Task( Description, Category)
{ 
	_StartDate = StartDate;
	_StartTime = StartTime;

}

Deadline::~Deadline(void)
{
}

void Deadline:: editStartDate(string NewStartDate){
	_StartDate = NewStartDate;
}
void Deadline:: editStartTime (string NewStartTime){
	_StartTime = NewStartTime;
}

void Deadline:: editEndDate (string NewEndDate){
	return;
}
void Deadline:: editEndTime (string NewEndTime){
	return;
}


string Deadline:: getStartDate() const{
	return _StartDate; 
}

string Deadline :: getStartTime() const{
	return _StartTime;
}

string Deadline:: getEndDate() const{
	return NULL;
}

 string Deadline:: getEndTime() const{
	return NULL;
}

bool Deadline:: isFound (string keyword){

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

	return found;
}

string Deadline:: getInfo() {
	ostringstream information;
	
	information <<left<< setw(15)<<_Description 
				<<setw(10)<<_StartDate
				<<setw(8)<<_StartTime
				<<setw(10)<<"-"
				<<setw(8)<<"-"
				<<setw(8)<< _Category;

	return information.str();
}	
