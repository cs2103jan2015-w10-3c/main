#include "Task.h"
#include <iostream>
#include <algorithm>

Task::Task(std::string Description)
{
	_Description= Description;
	_Checked= false;

} 

Task::~Task(void)
{}

void Task:: editDescription(std::string NewDescription){
	_Description = NewDescription;
}

std::string Task:: getDescription() const{
	return _Description;
}

bool Task :: isChecked(){
	return _Checked;
}

void Task :: checkTask(){
	_Checked=true;
}
