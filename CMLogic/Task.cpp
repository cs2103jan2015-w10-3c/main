//@author A0111448M
#include "Task.h"
#include <iostream>
#include <algorithm>

Task::Task(std::string description)
{
	_description= description;
} 

Task::~Task(void)
{}

void Task:: editDescription(std::string NewDescription){
	_description = NewDescription;
}

std::string Task:: getDescription() const{
	return _description;
}

