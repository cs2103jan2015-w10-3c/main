#include "FloatingTask.h"
#include <sstream>
#include <iomanip>



FloatingTask::FloatingTask(string Description, string Category)
	:Task( Description, Category){}


FloatingTask::~FloatingTask(void)
{}

void FloatingTask:: editStartDate(string NewStartDate){
	return;
}

void FloatingTask:: editStartTime (string NewStartTime){
	return;
}
void FloatingTask:: editEndDate (string NewEndDate){
	return;
}
void FloatingTask:: editEndTime (string NewEndTime){
	return;
}

string FloatingTask:: getStartDate() const{
	return NULL; }
string FloatingTask:: getStartTime() const{
	return NULL;
}

string FloatingTask:: getEndDate() const{
	return NULL;
}

 string FloatingTask:: getEndTime() const{
	return NULL;
}

bool FloatingTask :: isFound(string keyword){
	bool found = false;
	size_t position;
	position = _Description.find(keyword);
	if(position!= string::npos)
		found = true;
	position = _Category.find(keyword);
	if(position!= string::npos)
		found = true;
	return found;
}

string FloatingTask:: getInfo() {
	ostringstream information;
	
	information <<left << setw(15)<<_Description 
				<<setw(10)<<"-"
				<<setw(8)<<"-"
				<<setw(10)<<"-"
				<<setw(8)<<"-"
				<<setw(8)<< _Category;
				

	return information.str();
}
